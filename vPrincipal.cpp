#include "vPrincipal.h"
#include "vPartida.h"

vPrincipal::vPrincipal(wxWindow *parent) : Ventana_principal(parent) {
	Show();
}

vPrincipal::~vPrincipal() {
	
}

void vPrincipal::OnClickEmpezar( wxCommandEvent& event )  {
	Close(true);
	vPartida *win1 = new vPartida(NULL);
	win1->Show();
}

void vPrincipal::OnClickCargar( wxCommandEvent& event )  {
	event.Skip();
}

void vPrincipal::OnClickSalir( wxCommandEvent& event )  {
	Close(true);
}

