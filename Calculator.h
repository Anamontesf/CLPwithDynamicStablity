#pragma once
#include <vector>
using namespace std;

class Calculator
{
public:
	//Vectors containing the pattern info (content) nd cargo properties (definitions)
	vector<vector<int>> content;
	vector<vector<int>> definitions; 
	vector<int> containerSize;
	int counter;
	int estimate(); // cuantas cajas fallan alguna prueba;
	//single estabilidad=1-(estimate()/counter);

	//Paramos el grasp, le quitamos todas las posibles soluciones que no cumplen con el threshold, seguimos
	//Probamos distintos thresholds, si no es posible generar soluciones para ese threshold, soltamos excepción y lo ponemos de límite
	//Armamos la curva estabilidad vs utilización para distintos valores de threshold
	//Escogemos un threshold de manera Ingenieril®
	
};

