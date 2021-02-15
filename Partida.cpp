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
	return Dlist.size();
}


void Partida::Guardar(std::string nombrearchi){
	/*
	Pide un string para el nombre del archivo. Exporta la partida junto con
	los dados, personajes y sus items.
	*/
	nombrearchi+=".dat";													
	std::ofstream archivo(nombrearchi,std::ios::binary|std::ios::trunc);
	
	int CantPersonaje=Plist.size(), CantDados=Dlist.size();
	char straux[256];
	archivo.write(reinterpret_cast<char*>(&CantPersonaje),sizeof(int));
	archivo.write(reinterpret_cast<char*>(&CantDados),sizeof(int));
	
	std::strcpy(straux,_nombre.c_str());											
	archivo.write(straux,256);	
	
	archivo.close();
	for(int i=0;i<CantDados;i++) { 
		Dlist[i].Exportar(nombrearchi);
	}
	
	for(int i=0;i<CantPersonaje;i++) { 
		Plist[i].Exportar(nombrearchi, false);
	}
	
}

void Partida::Cargar(std::string nombrearchi){
	/*
	Pide un string para el archivo. Importa todos los datos de la partida, 
	incluyendo los dados, personajes y sus items.
	*/
	nombrearchi+=".dat";
	std::ifstream archivo(nombrearchi,std::ios::binary);
	
	if (!archivo.is_open()){
		std::cout << "No se pudo abrir el archivo." << std::endl;
	} else {
		size_t TamDado=sizeof(int)*2;
		int CantPersonaje, CantDados, posbinaria=TamDado+256;
		
		archivo.read(reinterpret_cast<char*>(&CantPersonaje),sizeof(int));
		archivo.read(reinterpret_cast<char*>(&CantDados),sizeof(int));
		
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
		
	}
}

float Partida::Combate(int posp1, int posp2,  int formula, float multiplicador, bool modificar){
	Personaje p1 = Plist[posp1], p2 = Plist[posp2];
	
	float DanioProb;
	float daniop1=p1.ObtenerStat(7),fuerzap1=p1.ObtenerStat(2),armorp2=p2.ObtenerStat(1);
	
	switch(formula){ 
	case 1:  DanioProb = (50+(daniop1*4)*multiplicador)-(armorp2*2); 
	break;
	case 2:  DanioProb = (((daniop1*0.5)*multiplicador)-(armorp2*0.25)); 
	break;
	case 3:  DanioProb = (((fuerzap1)*multiplicador)-(armorp2*0.5)); 
	break;
	case 4:  DanioProb = ((fuerzap1+(daniop1*0.5)*multiplicador)-(armorp2*0.25)); 
	break;
	case 5:  DanioProb = ((fuerzap1+(daniop1*0.5)*multiplicador)-(armorp2*0.5)); 
	break;
	}
	
	if(DanioProb<0){ 
		DanioProb=0;
	}
	float newhp=p2.ObtenerStat(0)-DanioProb;
	
	if(modificar) Partida::ModificarStatDePersonaje(posp2,0,newhp);
	
	return DanioProb;
	
}
