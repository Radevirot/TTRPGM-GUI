#include "vCombate.h"

vCombate::vCombate(wxWindow *parent) : Ventana_combate(parent) {
	Show();
}

vCombate::~vCombate() {
	
}

void vCombate::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

void vCombate::OnClickAtacar( wxCommandEvent& event )  {
	event.Skip();
}

