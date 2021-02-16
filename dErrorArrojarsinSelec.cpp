#include "dErrorArrojarsinSelec.h"

dErrorArrojarsinSelec::dErrorArrojarsinSelec(wxWindow *parent) : Dialogo_ErrorArrojarsinSelec(parent) {
	
}

void dErrorArrojarsinSelec::OnClickAceptar( wxCommandEvent& event )  {
	EndModal(0);
}

dErrorArrojarsinSelec::~dErrorArrojarsinSelec() {
	
}

