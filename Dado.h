#ifndef DADO_H
#define DADO_H
#include <stdlib.h>
#include <time.h>
#include <string>
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
	void ModificarDado(int DadoMax, int DadoMin);
	int TirarDado();
	void Exportar(std::string nombrearchi);
	void Importar(std::string nombrearchi, int posbinaria);
private:
	int ValMin, ValMax;
};

#endif

