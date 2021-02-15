#ifndef PARTIDA_H
#define PARTIDA_H
#include "Personaje.h"
#include "Dado.h"
#include <iostream>



class Partida {
	/*
	La clase Partida contiene un string guarda el nombre de la misma y dos
	vectores que guardan personaje y dados usados en la partida.
	Sus metodos estan explicados en Partida.cpp.
	*/
public:
	
	Partida(std::string nombre);
	
	void ModificarNombre(std::string nombre);
	std::string ObtenerNombre();
	
	void AgregarPersonaje(Personaje p1);
	Personaje ObtenerPersonaje(int pos);
	void EliminarPersonaje(int pos);
	int ObtenerTamPersonajes();
	void ModificarStatDePersonaje(int poslistaP, int posStats, float stat);
	void OrdenarPAlph();
	
	void AgregarItem(Item i1);
	Item ObtenerItem(int pos);
	void EliminarItem(int pos);
	void OrdenarIAlph();
	
	void AgregarDado(Dado d1);
	Dado ObtenerDado(int pos);
	void EliminarDado(int pos);
	int ObtenerCantidadDeDados();
	

	void Guardar(std::string nombrearchi);
	void Cargar(std::string nombrearchi);
	
	float Combate(int posp1, int posp2, int formula,float multiplicador,bool modificar);
	
	
private:
	std::string _nombre;
	std::vector<Personaje> Plist;
	std::vector<Dado> Dlist;
	std::vector<Item> Ilist;
};

#endif

