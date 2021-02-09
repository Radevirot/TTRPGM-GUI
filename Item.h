#ifndef ITEM_H
#define ITEM_H
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

class Item {
	/*
	La clase Item contiene un vector de flotantes que representa todas las estadísticas,
	3 strings para indicar nombre, descripción y detalle del objeto, un booleano que indica
	si se encuentra equipado o no (lo cuál será útil cuando el Item se encuentre dentro de un
	vector en Personaje y haya que saber cuándo se deben sumar sus estadísticas), contiene
	además un entero llamado cantidad, el cual indica cuántos items del mismo tipo hay.
	Los métodos se encuentran detallados en Item.cpp.
	*/
public:
	
	Item();
	Item(float Hp, float defensa, float fuerza, float agilidad, float RM, float inteligencia, float mana, float danio, float rango, float punteria, float bloqueo);
	
	void MostrarInfo();
	void ModificarStat(int pos,float stat);
	float ObtenerStat(int pos);
	
	void NombrarItem(std::string nombre);
	std::string ObtenerNombre();
	
	void ModificarDetalle(std::string detalle);
	std::string ObtenerDetalle();
	
	void ModificarDesc(std::string desc);
	std::string ObtenerDesc();
	
	void ModificarCant(int cant);
	int ObtenerCant();
	
	void EquiparToggle();
	bool Equipado();
	
	bool operator< (Item i2) const;
	
	void Exportar(std::string nombrearchi, bool esunico=true);
	void Importar(std::string nombrearchi, bool esunico=true, int posbinaria=0);
	
private:
	std::vector<float> IStats;
	std::string _nombre,_detalle,_desc;
	int _cant;
	bool equipado=false;
};

#endif

