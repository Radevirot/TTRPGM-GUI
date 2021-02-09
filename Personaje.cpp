#include "Personaje.h"
#include <iostream>

Personaje::Personaje(){
	/* 
	Constructor que crea un personaje vacio, redimensiona su vector de stats a 7.
	*/
	PStats.resize(11);
}

Personaje::Personaje(float Hp, float defensa, float fuerza, float agilidad, float RM, float inteligencia, float mana) {
	/* 
	Constructor que requiere todas las stats, probablemente no lo usemos.
	*/
	PStats[0]=Hp;
	PStats[1]=defensa;
	PStats[2]=fuerza;
	PStats[3]=agilidad;
	PStats[4]=RM;
	PStats[5]=inteligencia;
	PStats[6]=mana;
	PStats[7]=0;
	PStats[8]=0;
	PStats[9]=0;
	PStats[10]=0;
	
}

void Personaje::MostrarInfo(){
	/*
	M�todo temporal para mostrar informaci�n del personaje.
	*/
	std::cout << "Nombre: " << Pnombre << std::endl;
	std::cout << "Detalle: " << Pdetalle << std::endl;
	std::cout << "Nivel: " << Pnivel << std::endl;
	std::cout << "Experiencia: " << XP << std::endl;
	std::cout << "Vida: " << PStats[0] << std::endl;
	std::cout << "Defensa: " << PStats[1] << std::endl;
	std::cout << "Fuerza: " << PStats[2] << std::endl;
	std::cout << "Agilidad: " << PStats[3] << std::endl; 
	std::cout << "Resistencia Magica: " << PStats[4] << std::endl;
	std::cout << "Inteligencia: " << PStats[5] << std::endl; 
	std::cout << "Mana: " << PStats[6] << std::endl;
	std::cout << "Da�o: " << PStats[7] << std::endl;
	std::cout << "Rango: " << PStats[8] << std::endl;
	std::cout << "Punteria: " << PStats[9] << std::endl;
	std::cout << "Probabilidad de bloqueo: " << PStats[10] << std::endl;
	std::cout << "INVENTARIO" << std::endl;
	std::cout << "Cantidad de items en inventario: " << Inv.size() << std::endl;
	for(size_t i=0;i<Inv.size();i++) { 
		std::cout << "Item " << i+1 << ":" << std::endl;
		Inv[i].MostrarInfo();
		std::cout << std::endl;
	}
}

float Personaje::ObtenerStat(int pos){
	/*
	Retorna una stat del vector, pide una posicion para el vector.
	*/
	return PStats[pos];
}


void Personaje::SumarStatsDeItem(Item &item){
	/*
	Suma las stats del personaje y las de sus items equipados. Pide un item.
	*/
	for(int i=0;i<11;i++) { 
		float aux = PStats[i] + item.ObtenerStat(i);
		PStats[i] = aux;
	}
	
}

void Personaje::RestarStatsDeItem(Item &item){
	/*
	Resta las stats de un item a las stats de un personaje. Pide un item.
	*/
	for(int i=0;i<11;i++) { 
		float aux = PStats[i] - item.ObtenerStat(i);
		PStats[i] = aux;
	}
	
}

void Personaje::ModificarStat(int pos,float stat){
	/*
	Modifica las stats actuales, pide la posicion de esa stat y su valor.
	*/
	PStats[pos] = stat;
}

void Personaje::NombrarPersonaje(std::string nombre){
	/*
	Modifica el nombre actual del personaje, pide un string.
	*/
	Pnombre=nombre;
}

std::string Personaje::ObtenerNombre(){
	/*
	Retorna el nombre actual.
	*/
	return Pnombre;
}


void Personaje::ModificarNivel(int nivel){
	/*
	Modifica lo que diga el nivel, pide un int, que ser� el que se le coloque.
	*/
	Pnivel=nivel;
}


int Personaje::ObtenerNivel(){
	/*
	Retorna el nivel actual del personaje.
	*/
	return Pnivel;
}


void Personaje::ModificarXP(float xp){
	/*
	Modifica lo que diga el XP, pide un flotante, que ser� el que se le coloque.
	*/
	XP=xp;
}

float Personaje::ObtenerXP(){
	/*
	Retorna la experiencia actual del personaje.
	*/
	return XP;
}


void Personaje::ModificarDetalle(std::string detalle){
	/*
	Modifica lo que diga el detalle, pide un string, que ser� el que se le coloque.
	*/
	Pdetalle=detalle;
}


std::string Personaje::ObtenerDetalle(){
	/*
	Retorna el detalle actual del personaje.
	*/
	return Pdetalle;
}

void Personaje::AgregarInv(Item &I){
	/*
	Inserta un item dentro del invetario, pide un item.
	*/
	Inv.push_back(I);
}

Item Personaje::MostrarItem(int Pos){
	/*
	Devuelve un item del inventario, pide la poscion del item.
	*/
	return Inv[Pos];
}

void Personaje::BorrarItem(int Pos){
	/*
	Borra un item del inventario, pide la poscion del item.
	*/
	size_t Aux=Inv.size();
	auto it= Inv.begin()+Pos;
	Inv.erase(it);
	Inv.resize(Aux-1);
}

void Personaje::OrdenarAlph(){
	/*
	Ordena alfabeticamente los items del inventario.
	*/
	auto itinc= Inv.begin();
	auto itfin= Inv.end();
	sort(itinc, itfin);
}


void Personaje::Exportar(std::string nombrearchi, bool esunico){
	/*
	Pide el nombre del archivo que no debe incluir la extensi�n, y un
	booleano que indica si el personaje se exportar� como un archivo independiente
	(true) o si se encuentra dentro del archivo de partida (false).
	
	Exporta los datos del personaje y sus items.
	*/
	
	if(esunico){
		nombrearchi+=".dat";
		std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::trunc);
		
		char pstraux[256], pdetalleaux[1000];
		std::strcpy(pstraux,Pnombre.c_str());											// Se copia el nombre del personaje al vector de chars auxiliar
		archivo.write(pstraux,256);														// Escritura
		
		std::strcpy(pdetalleaux,Pdetalle.c_str());										// DETALLE
		archivo.write(pdetalleaux,1000);
		
		archivo.write(reinterpret_cast<char*>(&(Pnivel)),sizeof(int));					// NIVEL
		
		archivo.write(reinterpret_cast<char*>(&(XP)),sizeof(float));					// XP
		
		for(size_t i=0;i<PStats.size();i++) { 											// Ciclo de escritura de todas las stats del personaje
			archivo.write(reinterpret_cast<char*>(&(PStats[i])),sizeof(float));
		}
		
		archivo.close();
		for(size_t i=0;i<Inv.size();i++) { 
			Inv[i].Exportar(nombrearchi,false);
		}
	} else{
		std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::app);
		
		int CantItems=Inv.size();
		archivo.write(reinterpret_cast<char*>(&(CantItems)),sizeof(int));	
		
		char pstraux[256], pdetalleaux[1000];
		std::strcpy(pstraux,Pnombre.c_str());											// Se copia el nombre del personaje al vector de chars auxiliar
		archivo.write(pstraux,256);														// Escritura
		
		std::strcpy(pdetalleaux,Pdetalle.c_str());										// DETALLE
		archivo.write(pdetalleaux,1000);
		
		archivo.write(reinterpret_cast<char*>(&(Pnivel)),sizeof(int));					// NIVEL
		
		archivo.write(reinterpret_cast<char*>(&(XP)),sizeof(float));					// XP
		
		for(size_t i=0;i<PStats.size();i++) { 											// Ciclo de escritura de todas las stats del personaje
			archivo.write(reinterpret_cast<char*>(&(PStats[i])),sizeof(float));
		}
		
		archivo.close();
		for(int i=0;i<CantItems;i++) { 
			Inv[i].Exportar(nombrearchi,false);
		}
	}
	
}

void Personaje::Importar(std::string nombrearchi){
	/*
	Pide el nombre del archivo que no debe incluir la extensi�n.
	
	Este m�todo se encuentra sobrecargado, en este caso funciona para
	archivos de tipo personaje �nicos.
	
	Importa los datos del personaje y sus items.
	*/
	nombrearchi+=".dat";		
	std::ifstream archivo(nombrearchi,std::ios::binary);
	
	if (!archivo.is_open()){
		std::cout << "No se pudo abrir el archivo." << std::endl;
	} else {
		char pstraux[256], pdetalleaux[1000];
		archivo.read(pstraux,256);
		Pnombre=pstraux;
		
		archivo.read(pdetalleaux,1000);
		Pdetalle=pdetalleaux;
		
		archivo.read(reinterpret_cast<char*>(&Pnivel),sizeof(int));
		
		archivo.read(reinterpret_cast<char*>(&XP),sizeof(float));
		
		for(size_t i=0;i<11;i++) { 
			float auxiliar;
				archivo.read(reinterpret_cast<char*>(&auxiliar),sizeof(float));
			PStats[i]=auxiliar;
		}
		archivo.close();
		
		size_t tampers, tamitem;
		int pos,cantitems;
		tampers=256+1000+sizeof(int)+sizeof(float)*12;
		tamitem=256+1000*2+sizeof(int)+sizeof(float)*11+sizeof(bool);
		archivo.open(nombrearchi,std::ios::binary|std::ios::ate);
		pos=archivo.tellg();
		cantitems = (pos-tampers)/tamitem;
		archivo.close();
		for(int i=0;i<cantitems;i++) { 
			int itemcounter=tampers+(tamitem*i);
			Item aux;
			aux.Importar(nombrearchi,false,itemcounter);
			Inv.push_back(aux);
		}
		
	}
	
}

void Personaje::Importar(std::string nombrearchi, int &posbinaria){
	/*
	Pide el nombre del archivo que no debe incluir la extensi�n, y una posici�n
	binaria para saber desde d�nde comenzar a leer el personaje.
	
	Este m�todo se encuentra sobrecargado, en este caso funciona para
	personajes que se encuentren dentro de un archivo de partida.
	
	Importa los datos del personaje y sus items de una partida.
	*/
	
	std::ifstream archivo(nombrearchi,std::ios::binary);
	archivo.seekg(posbinaria);
	
	int CantItems;
	archivo.read(reinterpret_cast<char*>(&CantItems),sizeof(int));
	
	char pstraux[256], pdetalleaux[1000];
	archivo.read(pstraux,256);
	Pnombre=pstraux;
	
	archivo.read(pdetalleaux,1000);
	Pdetalle=pdetalleaux;
	
	archivo.read(reinterpret_cast<char*>(&Pnivel),sizeof(int));
	
	archivo.read(reinterpret_cast<char*>(&XP),sizeof(float));
	
	for(size_t i=0;i<11;i++) { 
		float auxiliar;
		archivo.read(reinterpret_cast<char*>(&auxiliar),sizeof(float));
		PStats[i]=auxiliar;
	}
	archivo.close();
	
	size_t tampers, tamitem;
	tampers=256+1000+(sizeof(int)*2)+sizeof(float)*12;
	tamitem=256+1000*2+sizeof(int)+sizeof(float)*11+sizeof(bool);
	
	for(int i=0;i<CantItems;i++) { 
		int itemcounter=posbinaria+tampers+(tamitem*i);
		Item aux;
		aux.Importar(nombrearchi,false,itemcounter);
		Inv.push_back(aux);
	}
	
	posbinaria+=tampers+(tamitem*CantItems);
}

bool Personaje::operator< (Personaje p2) const{
	/*
	Sobrecarga del operador menor.
	Pide un personaje para comparar.
	*/
	bool EsMenor=this->Pnombre<p2.Pnombre;
	return EsMenor;
}