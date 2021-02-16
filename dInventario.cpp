#include "dInventario.h"

dInventario::dInventario(wxWindow *parent, Partida *p) : Dialogo_Inventario(parent) {
	m_partida=p;
	
}

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	event.Skip();
}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

dInventario::~dInventario() {
	
}

