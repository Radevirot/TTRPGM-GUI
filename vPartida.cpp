#include "vPartida.h"
#include "vPersonaje.h"
#include "vItem.h"
#include "vDados.h"
#include "vCombate.h"
#include "dNombrePartida.h"
#include "string_conv.h"


vPartida::vPartida(wxWindow *parent, Partida *p) : Ventana_partida(parent) {
	m_partida=p;
	this->ActualizarNombre();
	Show();
}

vPartida::~vPartida() {
	
}

void vPartida::ActualizarNombre() {
	std::string name = "TTRPGM: " + m_partida->ObtenerNombre();
	this->SetTitle(std_to_wx(name));
}

void vPartida::OnMenuNueva( wxCommandEvent& event )  {
	dNombrePartida NomPart(this,m_partida);
	int valor = NomPart.ShowModal();
	if(valor==1){
		Partida b(m_partida->ObtenerNombre());
		*m_partida= b;
		this->ActualizarNombre();
	}
}

void vPartida::OnClickCrearP( wxCommandEvent& event )  {
	vPersonaje *Pers = new vPersonaje(NULL);
}

void vPartida::OnClickCrearI( wxCommandEvent& event )  {
	vItem *Item = new vItem(NULL);
}

void vPartida::OnClickCombate( wxCommandEvent& event )  {
	vCombate *Combate = new vCombate(NULL);
}

void vPartida::OnClickDado( wxCommandEvent& event )  {
	vDados *Dados = new vDados(NULL,m_partida);
}

