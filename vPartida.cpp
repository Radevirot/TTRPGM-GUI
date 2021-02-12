#include "vPartida.h"
#include "vPersonaje.h"
#include "vItem.h"
#include "vDados.h"
#include "vCombate.h"
#include "Partida.h"

vPartida::vPartida(wxWindow *parent) : Ventana_partida(parent) {
	Show();
}

vPartida::~vPartida() {
	
}

void vPartida::OnMenuNueva( wxCommandEvent& event )  {
	Close(true);
	vPartida *Part1 = new vPartida(NULL);
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
	vDados *Dados = new vDados(NULL);
}

