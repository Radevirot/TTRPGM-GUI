#include "dInventario.h"

dInventario::dInventario(wxWindow *parent, Personaje *p, Partida *pa) : Dialogo_Inventario(parent) {
	m_Personaje=p;
	m_partida=pa;
}

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	int pos=m_ListaItems->GetSelection();
	m_Personaje->AgregarInv(m_partida->ObtenerItem(pos));
	EndModal(1);
}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

dInventario::~dInventario() {
	
}

