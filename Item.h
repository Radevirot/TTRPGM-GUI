#ifndef ITEM_H
#define ITEM_H
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

class Item {
	/*
	La clase Item contiene un vector de flotantes que representa todas las estad�sticas,
	3 strings para indicar nombre, descripci�n y detalle del objeto, un booleano que indica
	si se encuentra equipado o no (lo cu�l ser� �til cuando el Item se encuentre dentro de un
	vector en Personaje y haya que saber cu�ndo se deben sumar sus estad�sticas), contiene
	adem�s un entero llamado cantidad, el cual indica cu�ntos items del mismo tipo hay.
	Los m�todos se encuentran detallados en Item.cpp.
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

