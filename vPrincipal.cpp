#include "vPrincipal.h"

vPrincipal::vPrincipal(Partida *p) : Ventana_principal(NULL) {
	m_partida=p;
}

void vPrincipal::OnClickEmpezar( wxCommandEvent& event )  {
	dNombrePartida NomPart(this,m_partida);
	int valor = NomPart.ShowModal();
	if(valor==1){
		EndModal(1);
	}
}

void vPrincipal::OnClickCargar( wxCommandEvent& event )  {
	event.Skip();
}

void vPrincipal::OnClickSalir( wxCommandEvent& event )  {
	EndModal(0);
}

vPrincipal::~vPrincipal() {
	
}

