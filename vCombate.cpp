#include "vCombate.h"

vCombate::vCombate(wxWindow *parent) : Ventana_combate(parent) {
	Show();
}

vCombate::~vCombate() {
	
}

void vCombate::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

