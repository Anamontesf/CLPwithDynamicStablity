#pragma warning (disable: 4786)

//GRASP CORRIENDO PARA TESIS -> MONTAJE DEL VALIDADOR DE ESTABILIDAD DINAMICA EN LA PARTE DEL CONSTRUCTIVO Y DE LA BUSQUEDA LOCAL 

#include "Container.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

void main(int argc,char **argv)
{
	//Variables de tiempo
	//si es 1 es full_supported

	CONTAINER Container(argv[1],1,atoi(argv[3]));
	Container.SetValorQuita(0.5);
	bool parametro_opcion_algoritmo=atoi(argv[2]);
	int parametro_opcion=atoi(argv[3]);
	int parametro_opcion_construccion=atoi(argv[4]);
	int parametro_mejoras=atoi(argv[5]);
	Container.Set_Full_Suported(true);
	Container.Set_Algoritmo_Opcion(parametro_opcion);
	Container.Set_Algoritmo_Opcion_Construccion(parametro_opcion_construccion);
	Container.Set_Algoritmo_Opcion_Mejora(parametro_mejoras);

	Container.Set_Val_Quita_Aleatorio(false);
	
	Container.Set_Algoritmo_Opcion_Irrestricto(true);
	Container.SetTipoMejora(2);
	Container.SetTipoMixto(false);
	Container.SetObjetivoCapas(true);
	switch(parametro_mejoras)
	{
		case 1:
		{
			Container.SetMejoraLocal(false);
			Container.Set_m_mejora_local_cliente(false);
		}
		break;
		case 2:
		{
			Container.SetMejoraLocal(true);
			Container.Set_m_mejora_local_cliente(false);
		}
		break;
		case 3:
		{
			Container.SetMejoraLocal(false);
			Container.Set_m_mejora_local_cliente(true);
		} 
		break;
		case 4:
		{
			Container.SetMejoraLocal(true);
			Container.Set_m_mejora_local_cliente(true);
		} 
		break;
	}	
		
	Container.SetMuchasIteraciones(false);
	Container.Set_Tipo_Origen(8);
	Container.Set_Val_Quita_Aleatorio(false);
//	Container.Set_Cadena_Salida(argv[1]);
	Container.Set_m_tipo_evaluacion(2);
	Container.Set_Algoritmo_Opcion_Daneses(false);
	Container.Set_Algoritmo_Opcion_Ceschia(false);
	if(parametro_opcion_algoritmo)		
		Container.Set_Algoritmo_Opcion_Junqueira(true); //TRUE -> Delta igual a cero 
	else
		Container.Set_Algoritmo_Opcion_Junqueira(false);

			Container.Grasp_Ceschia();
	
	
	std::cout << "Calculo best \n"; //esta es la ruta de ejecucion
	int numeroRotas = 0;
	Calculator c = Container.ConfiguracaoToCalculator(Container.Get_BestListaConfiguracaos());
	std::cout << c.counter << "\n";
	numeroRotas = c.estimate();
	double perRotas = 1.0 * numeroRotas / (1.0 * c.counter);
	cout.precision(5);
	std::cout << "Se rompieron " << fixed << perRotas << "\n"; //numero de rotas		
	Container.DibujarOpenGL(Container.Get_BestListaConfiguracaos());
}
