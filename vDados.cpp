#include "vDados.h"
#include "Partida.h"
#include "Dado.h"


vDados::vDados(wxWindow *parent) : Ventana_dados(parent) {
	Show();
}

vDados::~vDados() {
	
}

void vDados::OnClickSeleccionado( wxCommandEvent& event )  {
	event.Skip();
}

void vDados::OnClickAgregar( wxCommandEvent& event )  {
	Dado D();
	D.Dado::ObtenerMax();
}

void vDados::OnClickArrojar( wxCommandEvent& event )  {
	event.Skip();
}

void vDados::OnClickBorrar( wxCommandEvent& event )  {
	event.Skip();
}

void vDados::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

