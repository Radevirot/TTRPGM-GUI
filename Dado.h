#ifndef DADO_H
#define DADO_H
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
//#include <random>

class Dado {
	/*
	La clase Dado contiene dos enteros que determinan el valor m�ximo y m�nimo
	por el cual el dado dara un n�mero.
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

