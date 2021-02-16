#include "dInventario.h"
#include "Partida.h"

dInventario::dInventario(wxWindow *parent, Partida *p) : Dialogo_Inventario(parent) {
	m_partida=p;
	ShowModal();
}

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	event.Skip();
}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	event.Skip();
}

dInventario::~dInventario() {
	
}

