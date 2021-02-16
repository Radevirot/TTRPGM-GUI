#include "dInventario.h"

dInventario::dInventario(wxWindow *parent) : Dialogo_Inventario(parent) {
	
}

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	event.Skip();
}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	event.Skip();
}

dInventario::~dInventario() {
	
}

