#include "dInventario.h"

dInventario::dInventario(wxWindow *parent, Personaje *p, Partida *pa) : Dialogo_Inventario(parent) {
	m_Personaje=p;
	m_partida=pa;
	int Cant=m_partida->ObtenerCantidadDeItems();
	for(int i=0;i<Cant;i++) { 
		Item I=m_partida->ObtenerItem(i);
		m_ListaItems->Append(std_to_wx(I.ObtenerNombre()));
	}
}

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	int pos=m_ListaItems->GetSelection();
	Item I=m_partida->ObtenerItem(pos);
	m_Personaje->AgregarInv(I);
	EndModal(1);
}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

dInventario::~dInventario() {
	
}

