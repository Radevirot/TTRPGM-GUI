#include "Dado.h"

Dado::Dado() {
	/*
	Constructor que crea un dado vacío.
	*/
	ValMin=1;
	ValMax=20;
}

int Dado::TirarDado(){
	/*
	Tira un numero random.
	*/
	return rand()%(ValMax-ValMin+1)+ValMin;
}

void Dado::ModificarDado(int DadoMax, int DadoMin){
	/*
	Modifica el valor máximo y mínimo del dado, pide dos enteros para la modificación.
	*/
	ValMin=DadoMin;
	ValMax=DadoMax;
}

void Dado::Exportar(std::string nombrearchi){
	/*
	Pide el nombre del archivo que no debe incluir la extensión.
	Exporta el dado de una partida.
	*/
	std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::app);
	archivo.write(reinterpret_cast<char*>(&ValMin),sizeof(int));
	archivo.write(reinterpret_cast<char*>(&ValMax),sizeof(int));
	archivo.close();
}

void Dado::Importar(std::string nombrearchi, int posbinaria){
	/*
	Pide el nombre del archivo que no debe incluir la extensión. Tambien la 
	posición desde la que tiene que empezar a leer.
	Importa el dado de una partida.
	*/
	std::ifstream archivo(nombrearchi,std::ios::binary);
	archivo.seekg(posbinaria);
	archivo.read(reinterpret_cast<char*>(&ValMin),sizeof(int));
	archivo.read(reinterpret_cast<char*>(&ValMax),sizeof(int));
	archivo.close();
}
