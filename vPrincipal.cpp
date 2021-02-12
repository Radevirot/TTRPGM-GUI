#include "vPrincipal.h"
#include "dNombrePartida.h"

vPrincipal::vPrincipal(wxWindow *parent) : Ventana_principal(parent) {
	Show();
}

vPrincipal::~vPrincipal() {
	
}

void vPrincipal::OnClickEmpezar( wxCommandEvent& event )  {
	dNombrePartida *NomPart = new dNombrePartida(NULL);
	NomPart->Show();
	if (NomPart->IsBeingDeleted()) Close(true);
}

void vPrincipal::OnClickCargar( wxCommandEvent& event )  {
	event.Skip();
}

void vPrincipal::OnClickSalir( wxCommandEvent& event )  {
	Close(true);
}

