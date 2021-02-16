#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "Item.h"
#include <algorithm>


class Personaje {
	/*
	La clase Personaje contiene un vector de flotantes que representa todas las 
	estadísticas y un vector de items llamado inventario.
	Tiene 2 strings para indicar nombre y detalle del personaje, contiene
	además un entero llamado nivel y un flotante llamado XP.
	Los métodos se encuentran detallados en Personaje.cpp.
	*/
public:
	Personaje();
	Personaje(float Hp, float defenza, float fuerza, float agilidad, float RM, float inteligencia, float mana); //STATS

	void MostrarInfo();
	float ObtenerStat(int pos);	
	void SumarStatsDeItem(Item &item);												//EDITAR STATS
	void RestarStatsDeItem(Item &item);
	void ModificarStat(int pos,float stat);
	
	void NombrarPersonaje(std::string nombre);										//NOMBRE
	std::string ObtenerNombre();
	
	void ModificarNivel(int nivel);													//NIVEL
	int ObtenerNivel();
	
	void ModificarXP(float xp);														//XP
	float ObtenerXP();
	
	void ModificarDetalle(std::string detalle);										//DETALLE
	std::string ObtenerDetalle();
	
	void AgregarInv(Item I);																//INVENTARIO
	Item MostrarItem(int Pos);
	void BorrarItem(int Pos);
	void OrdenarAlph();
	
	void Exportar(std::string nombrearchi,bool esunico=true);											//EXPORTAR IMPORTAR
	void Importar(std::string nombrearchi);
	void Importar(std::string nombrearchi, int &posbinaria);
	
	bool operator< (Personaje p2) const;
	
private:
	std::string Pnombre, Pdetalle;
	std::vector<float> PStats;
	std::vector<Item> Inv;
	int Pnivel;
	float XP;
};

#endif

