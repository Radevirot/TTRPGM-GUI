#include "Partida.h"

Partida::Partida(std::string nombre) {
	/*
	Contructor que pide un string.
	*/
	_nombre=nombre;
}


void Partida::ModificarNombre(std::string nombre){
	/*
	Pide un string y modifica el nombre actual.
	*/
	_nombre=nombre;
}

std::string Partida::ObtenerNombre(){
	/*
	Retorna el nombre actual.
	*/
	return _nombre;
}


void Partida::AgregarPersonaje(Personaje p1){
	/*
	Pide un Personaje y lo ingresa en el vector de personajes.
	*/
	Plist.push_back(p1);
}

Personaje Partida::ObtenerPersonaje(int pos){
	/*
	Pide una posci�n y retorna el personaje de la misma.
	*/
	return Plist[pos];
}
	
void Partida::EliminarPersonaje(int pos){
	/*
	Pide una posici�n y elimina el personaje de esa posici�n, luego redimensiona
	el vector.
	*/
	size_t Aux=Plist.size();
	auto it= Plist.begin()+pos;
	Plist.erase(it);
	Plist.resize(Aux-1);
}

int Partida::ObtenerTamPersonajes(){
	/*
	Retorna el tama�o de la lista de personajes.
	*/
	return Plist.size();
}
	
void Partida::ModificarStatDePersonaje(int poslistaP, int posStats, float stat){
	/*
	Modifica la stat actuale, pide las posiciones del personaje en el vector, 
	de la stat y su valor nuevo.
	*/
	Personaje X;
	X=Partida::ObtenerPersonaje(poslistaP);
	X.ModificarStat(posStats,stat);
	Plist[poslistaP]=X;
}

void Partida::OrdenarPAlph(){
	/*
	Ordena la lista de personajes.
	*/
	auto itinc= Plist.begin();
	auto itfin= Plist.end();
	sort(itinc, itfin); 
}


void Partida::AgregarItem(Item i1){
	/*
	Pide un Item y lo ingresa en el vector de items.
	*/
	Ilist.push_back(i1);
}

Item Partida::ObtenerItem(int pos){
	/*
	Pide una posci�n y retorna el item del vector.
	*/
	return Ilist[pos];
}

void Partida::EliminarItem(int pos){
	/*
	Pide una posici�n y elimina el item de esa posici�n, luego redimensiona
	el vector.
	*/
	size_t Aux=Ilist.size();
	auto it= Ilist.begin()+pos;
	Ilist.erase(it);
	Ilist.resize(Aux-1);
}

int Partida::ObtenerCantidadDeItems(){
	/*
	Retorna la cantidad de items.
	*/
	return Ilist.size();
}

void Partida::OrdenarIAlph(){
	/*
	Ordena la lista de personajes.
	*/
	auto itinc= Ilist.begin();
	auto itfin= Ilist.end();
	sort(itinc, itfin); 
}


void Partida::AgregarDado(Dado d1){
	/*
	Pide un Dado y lo ingresa en el vector de dados.
	*/
	Dlist.push_back(d1);
}

Dado Partida::ObtenerDado(int pos){
	/*
	Pide una posici�n y retorna el dado de esa posici�n.
	*/
	return Dlist[pos];
}

void Partida::EliminarDado(int pos){
	/*
	Pide una posici�n y elimina el dado de la misma, luego redimensiona el 
	vector.
	*/
	size_t Aux=Dlist.size();
	auto it= Dlist.begin()+pos;
	Dlist.erase(it);
	Dlist.resize(Aux-1);
}

int Partida::ObtenerCantidadDeDados(){
	/*
	Retorna la cantidad de dados.
	*/
	return Dlist.size();
}


void Partida::Guardar(std::string nombrearchi){
	/*
	Pide un string para el nombre del archivo. Exporta la partida junto con
	los dados, personajes y sus items.
	*/												
	std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::trunc);
	
	int CantPersonaje=Plist.size(), CantDados=Dlist.size(), CantItems=Ilist.size();
	char straux[256];
	archivo.write(reinterpret_cast<char*>(&CantPersonaje),sizeof(int));
	archivo.write(reinterpret_cast<char*>(&CantDados),sizeof(int));
	archivo.write(reinterpret_cast<char*>(&CantItems),sizeof(int));
	
	std::strcpy(straux,_nombre.c_str());											
	archivo.write(straux,256);	
	
	archivo.close();
	for(int i=0;i<CantDados;i++) { 
		Dlist[i].Exportar(nombrearchi);
	}
	
	for(int i=0;i<CantPersonaje;i++) { 
		Plist[i].Exportar(nombrearchi, false);
	}
	
	for(int i=0;i<CantItems;i++) { 
		Ilist[i].Exportar(nombrearchi, false);
	}
	
}

void Partida::Cargar(std::string nombrearchi){
	/*
	Pide un string para el archivo. Importa todos los datos de la partida, 
	incluyendo los dados, personajes y sus items.
	*/
	std::ifstream archivo(nombrearchi,std::ios::binary);
	
	if (!archivo.is_open()){
		
	} else {
		size_t TamDado=(sizeof(int)*2)+16, TamItem=256+1000*2+sizeof(int)+sizeof(float)*11+sizeof(bool);
		int CantPersonaje, CantDados, CantItems, posbinaria=sizeof(int)*3+256;
		
		archivo.read(reinterpret_cast<char*>(&CantPersonaje),sizeof(int));
		archivo.read(reinterpret_cast<char*>(&CantDados),sizeof(int));
		archivo.read(reinterpret_cast<char*>(&CantItems),sizeof(int));
		
		char straux[256];
		archivo.read(straux,256);
		_nombre=straux;
		
		archivo.close();
		for(int i=0;i<CantDados;i++) { 
			Dado d1;
			d1.Importar(nombrearchi, posbinaria);
			Dlist.push_back(d1);
			posbinaria+=TamDado;
		}
		
		for(int i=0;i<CantPersonaje;i++) { 
			Personaje p1;
			p1.Importar(nombrearchi, posbinaria);
			Plist.push_back(p1);
		}
		
		for(int i=0;i<CantItems;i++) { 
			Item i1;
			i1.Importar(nombrearchi, false, posbinaria);
			Ilist.push_back(i1);
			posbinaria+=TamItem;
		}
		
	}
}

float Partida::Combate(int posp1, int posp2,  int formula, float multiplicador, bool modificar){
	/*
	Pide las posiciones de dos personajes, la posicion de la formula, el multiplicador
	y un booleano que detecta si modifica la vida actual.
	Retorna el da�o provocado al segundo personaje.
	*/
	Personaje p1 = Plist[posp1], p2 = Plist[posp2];
	
	float DanioProb;
	float daniop1=p1.ObtenerStat(7),fuerzap1=p1.ObtenerStat(2),
		  intep1=p1.ObtenerStat(5),armorp2=p2.ObtenerStat(1),
		  resmp2=p2.ObtenerStat(4);
	
	switch(formula){ 
	case 0:  DanioProb = (50+(daniop1*4)*multiplicador)-(armorp2*2); break;
	case 1:  DanioProb = (((daniop1*0.5)*multiplicador)-(armorp2*0.25)); break;
	case 2:  DanioProb = (((fuerzap1)*multiplicador)-(armorp2*0.5)); break;
	case 3:  DanioProb = ((fuerzap1+(daniop1*0.5)*multiplicador)-(armorp2*0.25)); break;
	case 4:  DanioProb = ((fuerzap1+(daniop1*0.5)*multiplicador)-(armorp2*0.5)); break;
	case 5:  DanioProb = (50+(intep1*4)*multiplicador)-(resmp2*2); break;
	case 6:  DanioProb = (((intep1*0.5)*multiplicador)-(resmp2*0.25)); break;
	}
	
	if(DanioProb<0){ 
		DanioProb=0;
	}
	float newhp=p2.ObtenerStat(0)-DanioProb;
	
	if(modificar) Partida::ModificarStatDePersonaje(posp2,0,newhp);
	
	return DanioProb;
	
}
