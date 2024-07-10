#include "Calculator.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
//Vectors containing the pattern info (content) nd cargo properties (definitions)
//vector<vector<int>> content;
//vector<vector<int>> definitions;
//vector<int> containerSize;
vector<int> status;

float fc = 0.5; //float, coefficient of static friction, typically 0.5 for cardboard - on - cardboard and cardboard - on - wooden pallet
float fkc = 0.01; //float, coefficient of kinetic friction, arround 0.2

//accelerations in different directions
float accF = 9.81;
float accB = 4.905;
float accR = 4.905;
float accL = 4.905;

//time under acceleration for each direction
float tF = 5;
float tB = 5;
float tR = 5;
float tL = 5;

//vector<vector<int>> definitions;
vector<int> containerDims;
int counter;

bool vertInContainer(int pointX, int pointY, int pointZ){
    bool inContainer = true;
    if (pointX > containerDims[0]) {
        inContainer = false;
    }
    else if (pointY > containerDims[1]) {
        inContainer = false;
    }
    else if (pointZ > containerDims[2]) {
        inContainer = false;
    }
    if (pointX < 0 || pointY < 0 || pointZ < 0) {
        inContainer = false;
        //cout << to_string(pointX)+"In container\n";
    }
    
    return inContainer;
}

bool vertsIntersect(vector<int> lowerPoint1, vector<int> lowerPoint2, vector<int> volume) {//float[3] lowerPoint1, float[3] lowerPoint2, float[6] volume, returns boolean
    bool intersect = true;
    if (vertInContainer(lowerPoint1[0], lowerPoint1[1], lowerPoint1[2]) && vertInContainer(lowerPoint2[0], lowerPoint2[1], lowerPoint2[2])) {
        intersect = false;
        if (volume[0] <= lowerPoint1[0] && lowerPoint1[0] <= volume[3]) { //these interval comparisons aren't nearly as pretty as in C++, sorry :(
            if (volume[1] <= lowerPoint1[1] && lowerPoint1[1] <= volume[4]) {
                if (volume[2] <= lowerPoint1[2] && lowerPoint1[2] <= volume[5]) {
                    intersect = true;
                }
            }
        }
        if (volume[0] <= lowerPoint2[0] && lowerPoint2[0] <= volume[3]) {
            if (volume[1] <= lowerPoint2[1] && lowerPoint2[1] <= volume[4]) {
                if (volume[2] <= lowerPoint2[2] && lowerPoint2[2] <= volume[5]) {
                    intersect = true;
                }
            }
        }
    }
    return intersect;
}


bool hasBoxOnTop(vector<int>volume, vector<int>lowerPoint1) {
    bool onTop = false;
    if (volume[0]*2 <= lowerPoint1[0] && lowerPoint1[0] <= volume[3] * 2) { //these interval comparisons aren't nearly as pretty as in C++, sorry :(
        if (volume[1] * 2 <= lowerPoint1[1] && lowerPoint1[1] <= volume[4] * 2) {
            if (volume[2] <= lowerPoint1[2] && lowerPoint1[2] <= volume[5]) {
                onTop = true;
                //cout <<  "Has box on Top\n";
            }
        }
    }

    return onTop;
}


int boxCheck(vector<int>boxVolume, float accelMagnitude, int forwardSide) { //float[6] boxVolume, float boxMass, float accelMagnitude, int forwardSide
    int status = 0; //int, zero for intact, 1 for broken

    if (accelMagnitude > 9.81 * fc && boxVolume[1]!=0) { //Checks if the box will slide and isn't on ground level.
        status = 1;
    }
    else { //Checks if the box will tip over
        if (forwardSide == 1) { //if the acceleration is in the forward or backwards direction
            if (accelMagnitude * (boxVolume[5] - boxVolume[2]) > 9.81 * (boxVolume[4] - boxVolume[1])) {
                status = 2;
            }
        }
        else if (accelMagnitude * (boxVolume[5] - boxVolume[2]) > 9.81 * (boxVolume[3] - boxVolume[0])) {
                status = 2;
        }
        
    }
     return status;
 }

int boxTest(vector<int>boxVolume, float accelMagnitude, int dir) { //float[6] boxVolume, float boxMass, float accelMagnitude, int forwardSide
    int status = boxCheck(boxVolume, accelMagnitude, dir);
    int state = 0; //int, zero for intact, 1 for broken
    float d = 0;
    if (status == 1) { 
        if (dir == 1) {
            if (0.5 * accelMagnitude * tF * tF > 0.5 * (boxVolume[4] - boxVolume[1])) {//Checks if the box slides to the point of falling.
                state = 1;
            }
        }
        else if (0.5 * accelMagnitude * tB * tB > 0.5 * (boxVolume[4] - boxVolume[1])) {
            state = 1;
        }
        
    }
    else if (status == 2) {
        if (dir == 1) {
            d = sqrt((boxVolume[4] - boxVolume[1]) * (boxVolume[4] - boxVolume[1]) + (boxVolume[5] - boxVolume[2]) * (boxVolume[5] - boxVolume[2]));
            if (9.81 * (d - (boxVolume[5] - boxVolume[2])) < accelMagnitude * sqrt(pow((boxVolume[4] - boxVolume[1]), 2) + pow(d - (boxVolume[5] - boxVolume[2]), 2))) {
                state = 1;
            }
        }
        else if (0.5 * accelMagnitude * tB * tB > 0.5 * (boxVolume[4] - boxVolume[1])) {
            d = sqrt((boxVolume[3] - boxVolume[0]) * (boxVolume[3] - boxVolume[0]) + (boxVolume[5] - boxVolume[2]) * (boxVolume[5] - boxVolume[2]));
            if (9.81 * (d - (boxVolume[5] - boxVolume[2])) < accelMagnitude * sqrt(pow((boxVolume[3] - boxVolume[0]), 2) + pow(d - (boxVolume[5] - boxVolume[2]), 2))) {
                state = 1;
            }
        }
    }
    return state;
}

int Calculator::estimate() {

    vector<int> lp1;
    vector<int> lp2;
    vector<int> lp3;
    vector<int> vol;
    vector<int> colVol; //collision volume
    int broken = 0;
    int mass = 0;
    bool boxOnTop = false; //checksif there is a box on top of he current one

    containerDims = containerSize;
    for (int i = 0; i < counter; i++)
    {
        //content[i][8] = 0;
        boxOnTop = false;
        //cout << "Tal vez vacio \n";
        //cout << to_string(content[1][1]) + "\n";
        lp1.clear();
        lp2.clear();
        vol.clear();
        mass = definitions[content[i][6]][8] / 10000;//revisar, imprimir pesos
        bool hasClearance = true;
        for (int j = 0; j < 6; j++) {
            vol.push_back(content[i][j]);
        }
        //Test forward
        lp1 = { vol[0], vol[4] + definitions[content[i][6]][3] / 2, vol[2] - definitions[content[i][6]][4]/2 };
        lp2 = { vol[3], vol[4] + definitions[content[i][6]][3] / 2, vol[2] - definitions[content[i][6]][4] / 2 };
        lp3 = { (vol[0]+ vol[3])/2,  (vol[1] + vol[4])/2, vol[5]+1};
        
        for (int k = 0; k < counter; k++) {
            if (k != i) {
                colVol.clear();
                for (int j = 0; j < 6; j++) {
                    colVol.push_back(content[k][j]);
                }
                if (hasBoxOnTop(colVol, lp3)) {
                    boxOnTop = true;
                }
                if (vertsIntersect(lp1, lp2, colVol)) {
                    hasClearance = false;
                }
            }
        }
        if (hasClearance) {
            //cout << "clearance\n";
            content[i][7] = boxTest(vol,accF, 1);
        }

        //Test backwards
        lp1 = { vol[0], vol[1] - definitions[content[i][6]][3] / 2, vol[2] - definitions[content[i][6]][4] / 2 };
        lp2 = { vol[3], vol[1] - definitions[content[i][6]][3] / 2, vol[2] - definitions[content[i][6]][4] / 2 };
        hasClearance = true;
        for (int k = 0; k < counter; k++) {
            if (k != i) {
                colVol.clear();
                for (int j = 0; j < 6; j++) {
                    colVol.push_back(content[k][j]);
                }
                if (vertsIntersect(lp1, lp2, colVol)) {
                    hasClearance = false;
                }
            }
        }
        if (hasClearance) {// && content[i][6] == 0) {
            //cout << "clearance\n";
            content[i][7] = boxTest(vol, accB, 1);
        }

        //Test left
        lp1 = { vol[0] + definitions[content[i][6]][1] / 2, vol[1], vol[2] - definitions[content[i][6]][4] / 2 };
        lp2 = { vol[0] + definitions[content[i][6]][1] / 2, vol[4], vol[2] - definitions[content[i][6]][4] / 2 };
        hasClearance = true;
        for (int k = 0; k < counter; k++) {
            if (k != i) {
                colVol.clear();
                for (int j = 0; j < 6; j++) {
                    colVol.push_back(content[k][j]);
                }
                if(vertsIntersect(lp1, lp2, colVol)) {
                    hasClearance = false;
                }
            }
        }
        if (hasClearance) {// && content[i][6] == 0) {
            //cout << "clearance\n";
            content[i][7] = boxTest(vol, accL, 0);
        }

        //Test right
        lp1 = { vol[0] - definitions[content[i][6]][1] / 2, vol[1], vol[2] - definitions[content[i][6]][4] / 2 };
        lp2 = { vol[0] - definitions[content[i][6]][1] / 2, vol[4], vol[2] - definitions[content[i][6]][4] / 2 };
        hasClearance = true;
        for (int k = 0; k < counter; k++) {
            if (k != i) {
                colVol.clear();
                for (int j = 0; j < 6; j++) {
                    colVol.push_back(content[k][j]);
                }
                if (vertsIntersect(lp1, lp2, colVol)) {
                    hasClearance = false;
                }
            }
        }
        if (hasClearance){//&& content[i][6] == 0) {
            //cout << "clearance\n";
            content[i][7] = boxTest(vol, accR, 0);
        }
        if (boxOnTop) {
            content[i][7] = 0;
        }

        //std::cout << "Rotas " << content[i][7] << "\n";
    }
    
    for (int i = 0; i < counter; i++){
        broken += content[i][7];
        
    }
    return broken;
}
