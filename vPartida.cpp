#include "vPartida.h"
#include "vPersonaje.h"
#include "vItem.h"
#include "vDados.h"
#include "vCombate.h"
#include "dErrorArrojarsinSelec.h"
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
	vPersonaje *Pers = new vPersonaje(NULL, m_partida, true);
}

void vPartida::OnClickCrearI( wxCommandEvent& event )  {
	vItem *Item = new vItem(NULL, m_partida, true);
	
}

void vPartida::OnClickCombate( wxCommandEvent& event )  {
	vCombate *Combate = new vCombate(NULL, m_partida);
}

void vPartida::OnClickDado( wxCommandEvent& event )  {
	vDados *Dados = new vDados(NULL,m_partida);
}

void vPartida::OnFocusPartida( wxFocusEvent& event )  {
	m_ListaItems->Clear();
	m_ListaPersonajes->Clear();
	for(int i=0;i<m_partida->ObtenerCantidadDeItems();i++) { 
		Item I=m_partida->ObtenerItem(i);
		std::string nombrefinal=I.ObtenerNombre().substr(0,20);
		if(I.ObtenerNombre().length()>20){
			nombrefinal+="... - ";
		} else{
			nombrefinal+=" - ";
		}
		nombrefinal+=I.ObtenerDesc().substr(0,20);
		if(I.ObtenerDesc().length()>20){
			nombrefinal+="...";
		}
		m_ListaItems->Append(std_to_wx(nombrefinal));
	}
	for(int i=0;i<m_partida->ObtenerTamPersonajes();i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		m_ListaPersonajes->Append(std_to_wx(P.ObtenerNombre()+" - PV: "+std::to_string(P.ObtenerStat(0))));
	}
}

void vPartida::OnDobleClickListaItem( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnClickBorrar( wxCommandEvent& event )  {
	if(m_ListaItems->GetSelection()==wxNOT_FOUND){
		dErrorArrojarsinSelec Error(this,1);
		Error.ShowModal();
	}
}



void vPartida::OnDobleClickListaPersonaje( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnClickBorrarPersonaje( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnClickVerInventario( wxCommandEvent& event )  {
	event.Skip();
}

