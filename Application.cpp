#include "Application.h"


IMPLEMENT_APP(Application)

bool Application::OnInit() {
	/*
	Crea un puntero de partida y muestra la ventana principal. 
	*/
	m_partida = new Partida("");
	wxInitAllImageHandlers();
	
	vPrincipal Princ(m_partida);
	int valor = Princ.ShowModal();
	
	if(valor==1){
		vPartida *Part = new vPartida(NULL,m_partida);
	}else{
		return false;
	}
	
	return true;
}

