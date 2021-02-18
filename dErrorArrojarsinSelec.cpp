#include "dErrorArrojarsinSelec.h"

dErrorArrojarsinSelec::dErrorArrojarsinSelec(wxWindow *parent,int tipo) : Dialogo_ErrorArrojarsinSelec(parent) {
	switch (tipo){
	case 1: m_staticText63->SetLabel(std_to_wx("No es posible borrar un item sin\nhaber seleccionado uno previamente.")); break;
	case 2: m_staticText63->SetLabel(std_to_wx("No es posible arrojar un dado sin\nhaber seleccionado uno previamente.")); break;
	case 3: m_staticText63->SetLabel(std_to_wx("No es posible borrar un dado sin\nhaber seleccionado uno previamente.")); break;
	case 4: m_staticText63->SetLabel(std_to_wx("No es posible borrar un personaje sin\nhaber seleccionado uno previamente.")); break;
	}
}

void dErrorArrojarsinSelec::OnClickAceptar( wxCommandEvent& event )  {
	EndModal(0);
}

dErrorArrojarsinSelec::~dErrorArrojarsinSelec() {
	
}

