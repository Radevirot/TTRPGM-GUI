#include "dErrorArrojarsinSelec.h"

dErrorArrojarsinSelec::dErrorArrojarsinSelec(wxWindow *parent) : Dialogo_ErrorArrojarsinSelec(parent) {
	
}

dErrorArrojarsinSelec::~dErrorArrojarsinSelec() {
	
}

void dErrorArrojarsinSelec::OnClickAceptar( wxCommandEvent& event )  {
	EndModal(0);
}

