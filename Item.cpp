#include "Item.h"
#include <iostream>

Item::Item(){
	/*
	Constructor que crea un item vacio, redimensiona su vector de stats a 11.
	*/
	IStats.resize(11);
}

Item::Item(float Hp, float defensa, float fuerza, float agilidad, float RM, float inteligencia, float mana, float danio, float rango, float punteria, float bloqueo) {
	/* 
	Constructor que requiere todas las stats, probablemente no lo usemos.
	*/
	
	IStats[0]=Hp;
	IStats[1]=defensa;
	IStats[2]=fuerza;
	IStats[3]=agilidad;
	IStats[4]=RM;
	IStats[5]=inteligencia;
	IStats[6]=mana;
	IStats[7]=danio;
	IStats[8]=rango;
	IStats[9]=punteria;
	IStats[10]=bloqueo;
	
}


void Item::MostrarInfo(){
	/*
	Método temporal para mostrar información del item.
	*/
	std::cout << "Nombre: " << _nombre << std::endl;
	std::cout << "Cantidad: " << _cant << std::endl;
	std::cout << "Equipado: "; if(equipado){std::cout << "Si" << std::endl;} else {std::cout << "No" << std::endl;}
	std::cout << "Descripcion: " << _desc << std::endl;
	std::cout << "Detalle: " << _detalle << std::endl;
	std::cout << "Vida: " << IStats[0] << std::endl;
	std::cout << "Defensa: " << IStats[1] << std::endl;
	std::cout << "Fuerza: " << IStats[2] << std::endl;
	std::cout << "Agilidad: " << IStats[3] << std::endl; 
	std::cout << "Resistencia Magica: " << IStats[4] << std::endl;
	std::cout << "Inteligencia: " << IStats[5] << std::endl; 
	std::cout << "Mana: " << IStats[6] << std::endl; 
	std::cout << "Daño: " << IStats[7] << std::endl; 
	std::cout << "Rango: " << IStats[8] << std::endl; 
	std::cout << "Punteria: " << IStats[9] << std::endl; 
	std::cout << "Probabilidad de bloqueo: " << IStats[10] << std::endl; 
}

void Item::ModificarStat(int pos,float stat){
	/*
	Modifica una de las estadísticas del item, pide una posición
	correspondiente al vector de stats, y también pide la stat
	nueva por la que se va a reemplazar.
	*/
	IStats[pos]=stat;
}

float Item::ObtenerStat(int pos){
	/*
	Retorna una de las estadísticas del vector de stats, pide una
	posición.
	*/
	return IStats[pos];
}


void Item::NombrarItem(std::string nombre){
	/*
	Asigna el nombre del item, pide un string, que será el que se le coloque.
	*/
	_nombre=nombre;
}
	
std::string Item::ObtenerNombre(){
	/*
	Retorna el nombre actual del item.
	*/
	return _nombre;
}


void Item::ModificarDetalle(std::string detalle){
	/*
	Modifica lo que diga el detalle, pide un string, que será el que se le coloque.
	*/
	_detalle=detalle;
}

std::string Item::ObtenerDetalle(){
	/*
	Retorna el detalle actual del item.
	*/
	return _detalle;
}


void Item::ModificarDesc(std::string desc){
	/*
	Modifica lo que diga la descripción, pide un string, que será el que se le coloque.
	*/
	_desc=desc;
}

std::string Item::ObtenerDesc(){
	/*
	Retorna la descripción actual del item.
	*/
	return _desc;
}


void Item::ModificarCant(int cant){
	/*
	Modifica la cantidad de items, pide un entero, que será el que se le coloque.
	*/
	_cant=cant;
}

int Item::ObtenerCant(){
	/*
	Retorna la cantidad de items.
	*/
	return _cant;
}

void Item::EquiparToggle(){
	/*
	Cambia el booleano que indica si el item está equipado o no,
	dependiendo del valor que tenga se le asignará el contrario.
	*/
	if (!equipado){
		equipado=true;
	} else {
		equipado=false;
	}
}

bool Item::Equipado(){
	/*
	Retorna el booleano que indica si el objeto está equipado.
	*/
	return equipado;
}


bool Item::operator< (Item i2) const{
	/*
	Sobrecarga del operador menor, pide un item que comparar.
	Retorna un booleano que indica que item es menor alfabeticamente.
	*/
	bool EsMenor=this->_nombre<i2._nombre;
	return EsMenor;
}


void Item::Exportar(std::string nombrearchi, bool esunico){
	/*
	Pide el nombre del archivo que no debe incluir la extensión y un booleano
	que indica si el item se exportará como un archivo independiente (true) o
	si se incluirá dentro de otro archivo, que sería el de personaje (false).
	
	Exporta el item creado en un archivo binario para poder
	importarlo en un futuro.
	*/
	
	if(esunico){
		nombrearchi+=".dat";															// Agrega .dat al nombre.
		std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::trunc);			// Crear archivo.
		
		char straux[256],descaux[1000],detalleaux[1000];
		std::strcpy(straux,_nombre.c_str());											// Se copia el NOMBRE del item al vector de chars auxiliar.
		archivo.write(straux,256);														// Escritura.
	
		std::strcpy(detalleaux,_detalle.c_str());										// DETALLE
		archivo.write(detalleaux,1000);
		
		std::strcpy(descaux,_desc.c_str());												// DESCRIPCIÓN
		archivo.write(descaux,1000);
		
		archivo.write(reinterpret_cast<char*>(&_cant),sizeof(int));						// Escritura de cantidad.
		
		for(size_t i=0;i<IStats.size();i++) { 											// Escritura de todas las stats del item.
			archivo.write(reinterpret_cast<char*>(&(IStats[i])),sizeof(float));
		}
		archivo.write(reinterpret_cast<char*>(&equipado),sizeof(bool));					// Booleano.
		archivo.close();
		
	} else {
		std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::app);				// Posicionarse al final.
		
		char straux[256],descaux[1000],detalleaux[1000];
		std::strcpy(straux,_nombre.c_str());											// Se copia el NOMBRE del item al vector de chars auxiliar.
		archivo.write(straux,256);														// Escritura.
		
		std::strcpy(detalleaux,_detalle.c_str());										// DETALLE
		archivo.write(detalleaux,1000);
		
		std::strcpy(descaux,_desc.c_str());												// DESCRIPCIÓN
		archivo.write(descaux,1000);
		
		archivo.write(reinterpret_cast<char*>(&_cant),sizeof(int));						// Escritura de cantidad.
		
		for(size_t i=0;i<IStats.size();i++) { 											// Escritura de todas las stats del item.
			archivo.write(reinterpret_cast<char*>(&(IStats[i])),sizeof(float));
		}
		archivo.write(reinterpret_cast<char*>(&equipado),sizeof(bool));					// Booleano.
		archivo.close();
	}

	
	
}

void Item::Importar(std::string nombrearchi, bool esunico, int posbinaria){
	/*
	Pide el nombre del archivo que no debe incluir la extensión, un booleano
	que indica si se importa un item individual (true) o si la importación
	se encuentra dentro de otro archivo, que sería el de personaje (false).
	
	Se incluye además un entero que indica la posición binaria en la que
	se debe comenzar a leer el item, que sólo se utiliza en caso de que
	el item se encuentre dentro del archivo de personaje.
	
	Importa un item desde un archivo binario.
	*/
	
	if(esunico){
		nombrearchi+=".dat";		
		std::ifstream archivo(nombrearchi,std::ios::binary);
		
		if (!archivo.is_open()){
			std::cout << "No se pudo abrir el archivo." << std::endl;					// Checkea si se abrió el archivo
		} else {
			char straux[256],descaux[1000],detalleaux[1000];
			archivo.read(straux,256);													
			_nombre=straux;																
			
			archivo.read(detalleaux,1000);
			_detalle=detalleaux;
			
			archivo.read(descaux,1000);
			_desc=descaux;
			
			archivo.read(reinterpret_cast<char*>(&_cant),sizeof(int));	
			
			for(size_t i=0;i<11;i++) { 
				float auxiliar;
				archivo.read(reinterpret_cast<char*>(&auxiliar),sizeof(float));
				IStats[i]=auxiliar;
			}
			archivo.read(reinterpret_cast<char*>(&equipado),sizeof(bool));	
			archivo.close();
		}
	} else{
		std::ifstream archivo(nombrearchi,std::ios::binary);
		archivo.seekg(posbinaria);
		
		char straux[256],descaux[1000],detalleaux[1000];
		archivo.read(straux,256);
		_nombre=straux;
		
		archivo.read(detalleaux,1000);
		_detalle=detalleaux;
		
		archivo.read(descaux,1000);
		_desc=descaux;
		
		archivo.read(reinterpret_cast<char*>(&_cant),sizeof(int));	
		
		for(size_t i=0;i<11;i++) { 
			float auxiliar;
			archivo.read(reinterpret_cast<char*>(&auxiliar),sizeof(float));
			IStats[i]=auxiliar;
		}
		archivo.read(reinterpret_cast<char*>(&equipado),sizeof(bool));	
		archivo.close();
	}


}
