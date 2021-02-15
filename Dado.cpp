#include "Dado.h"

Dado::Dado() {
	/*
	Constructor que crea un dado con valores por defecto.
	*/
	_nombre="";
	ValMin=1;
	ValMax=20;
}

void Dado::Modificar(std::string nombre, int DadoMin, int DadoMax){
	_nombre=nombre;
	ValMin=DadoMin;
	ValMax=DadoMax;
}

int Dado::TirarDado(){
	/*
	Tira un numero random.
	*/
	return rand()%(ValMax-ValMin+1)+ValMin;
}

std::string Dado::ObtenerNombre(){
	return _nombre;
}

int Dado::ObtenerMax(){
	return ValMax;
}

int Dado::ObtenerMin(){
	return ValMin;
}

void Dado::Exportar(std::string nombrearchi){
	/*
	Pide el nombre del archivo que no debe incluir la extensión.
	Exporta el dado de una partida.
	*/
	std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::app);
	
	char straux[16];
	std::strcpy(straux,_nombre.c_str());											
	archivo.write(straux,16);	
	
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
	char straux[16];
	archivo.read(straux,16);
	_nombre=straux;
	archivo.read(reinterpret_cast<char*>(&ValMin),sizeof(int));
	archivo.read(reinterpret_cast<char*>(&ValMax),sizeof(int));
	archivo.close();
}
