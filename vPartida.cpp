#include "vPartida.h"
#include "vPersonaje.h"
#include "vDados.h"
#include "vCombate.h"
#include "dItem.h"
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


void vPartida::OnDobleClickListaItem( wxCommandEvent& event )  {
	
	int pos = m_ListaItems->GetSelection();
	Item I=m_partida->ObtenerItem(pos);
	dItem ItemMod(this,m_partida,I,pos);
	ItemMod.ShowModal();
}

void vPartida::OnClickBorrar( wxCommandEvent& event )  {
	if(m_ListaItems->GetSelection()==wxNOT_FOUND){
		dErrorArrojarsinSelec Error(this,1);
		Error.ShowModal();
	} else {
		int pos = m_ListaItems->GetSelection();
		m_partida->EliminarItem(pos);
		m_ListaItems->Delete(pos);
	}
	
}

void vPartida::OnDobleClickListaPersonaje( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnClickBorrarPersonaje( wxCommandEvent& event )  {
	if(m_ListaPersonajes->GetSelection()==wxNOT_FOUND){
		dErrorArrojarsinSelec Error(this,4);
		Error.ShowModal();
	} else {
		int pos = m_ListaPersonajes->GetSelection();
		m_partida->EliminarPersonaje(pos);
		m_ListaPersonajes->Delete(pos);
	}
}

void vPartida::OnClickVerInventario( wxCommandEvent& event )  {
	event.Skip();
}


void vPartida::OnMenuEditar( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnMenuGuardar( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnMenuCargar( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnMenuAyuda( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnEntrarPartida( wxMouseEvent& event )  {
	event.Skip();
	m_ListaItems->Clear();
	m_ListaPersonajes->Clear();
	for(int i=0;i<m_partida->ObtenerCantidadDeItems();i++) { 
		Item I=m_partida->ObtenerItem(i);
		std::string nombrefinal = I.ObtenerNombre().substr(0,30);
		if(I.ObtenerNombre().length()>30){
			nombrefinal += "... - DÑ: ";
		} else{
			nombrefinal += " - DÑ: ";
		}
		std::string numerito=std::to_string(I.ObtenerStat(7));
		numerito.erase(numerito.end()-4,numerito.end());
		nombrefinal += numerito;
		m_ListaItems->Append(std_to_wx(nombrefinal));
	}
	for(int i=0;i<m_partida->ObtenerTamPersonajes();i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		std::string nombrefinal = P.ObtenerNombre().substr(0,30);
		if(P.ObtenerNombre().length()>30){
			nombrefinal += "... - PV: ";
		} else{
			nombrefinal += " - PV: ";
		}
		std::string numerito=std::to_string(P.ObtenerStat(0));
		numerito.erase(numerito.end()-4,numerito.end());
		nombrefinal += numerito;
		m_ListaPersonajes->Append(std_to_wx(nombrefinal));
	}
	event.Skip(false);
}

