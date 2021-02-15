#ifndef DADO_H
#define DADO_H
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <fstream>
//#include <random>

class Dado {
	/*
	La clase Dado contiene dos enteros que determinan el valor máximo y mínimo
	por el cual el dado dara un número.
	Sus metodos estan explicados en Dado.cpp.
	*/
public:
	Dado();
	void Modificar(std::string nombre, int DadoMin, int DadoMax);
	std::string ObtenerNombre();
	int ObtenerMax();
	int ObtenerMin();
	int TirarDado();
	void Exportar(std::string nombrearchi);
	void Importar(std::string nombrearchi, int posbinaria);
private:
	std::string _nombre;
	int ValMin, ValMax;
};

#endif

