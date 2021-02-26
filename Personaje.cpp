#include "Personaje.h"

Personaje::Personaje(){
	/* 
	Constructor que crea un personaje vacio, redimensiona su vector de stats a 7.
	*/
	PStats.resize(11);
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

void Personaje::ResetStat(){
	/*
	Modifica las stats actuales, las deja a 0.
	*/
	PStats[0] = 0;
	PStats[1] = 0;
	PStats[2] = 0;
	PStats[3] = 0;
	PStats[4] = 0;
	PStats[5] = 0;
	PStats[6] = 0;
	PStats[7] = 0;
	PStats[8] = 0;
	PStats[9] = 0;
	PStats[10] = 0;
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
	Modifica lo que diga el nivel, pide un int, que será el que se le coloque.
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
	Modifica lo que diga el XP, pide un flotante, que será el que se le coloque.
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
	Modifica lo que diga el detalle, pide un string, que será el que se le coloque.
	*/
	Pdetalle=detalle;
}


std::string Personaje::ObtenerDetalle(){
	/*
	Retorna el detalle actual del personaje.
	*/
	return Pdetalle;
}

void Personaje::AgregarInv(Item I){
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

int Personaje::TamInv(){
	/*
	Devuelve la cantidad de items en el inventario.
	*/
	return Inv.size();
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
	Pide el nombre del archivo que no debe incluir la extensión, y un
	booleano que indica si el personaje se exportará como un archivo independiente
	(true) o si se encuentra dentro del archivo de partida (false).
	
	Exporta los datos del personaje y sus items.
	*/
	
	if(esunico){
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
	Pide el nombre del archivo que no debe incluir la extensión.
	
	Este método se encuentra sobrecargado, en este caso funciona para
	archivos de tipo personaje únicos.
	
	Importa los datos del personaje y sus items.
	*/	
	std::ifstream archivo(nombrearchi,std::ios::binary);
	
	if (!archivo.is_open()){
		
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
	Pide el nombre del archivo que no debe incluir la extensión, y una posición
	binaria para saber desde dónde comenzar a leer el personaje.
	
	Este método se encuentra sobrecargado, en este caso funciona para
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
