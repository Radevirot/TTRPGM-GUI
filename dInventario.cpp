#include "dInventario.h"

dInventario::dInventario(wxWindow *parent, Personaje &p, Partida *pa) : Dialogo_Inventario(parent) {
	m_Personaje=&p;
	m_partida=pa;
	Cant=m_partida->ObtenerCantidadDeItems();
	for(int i=0;i<Cant;i++) { 
		Item I=m_partida->ObtenerItem(i);
		m_ListaItems->Append(std_to_wx(I.ObtenerNombre()));
	}
}

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	int pos=m_ListaItems->GetSelection();
	Item I=m_partida->ObtenerItem(pos);
	Cant=m_Personaje->TamInv();
	bool esigual=false;
	for(int i=0;i<Cant;i++) { 
		Item I2=m_Personaje->MostrarItem(i);
		if(I==I2){ 
			wxMessageBox(wxT("No es posible agregar un item que ya exista\nen el inventario del personaje."),wxT("Error"),wxICON_ERROR);
			esigual=true;
		}
	}
	if(!esigual){ 
		m_Personaje->AgregarInv(I);
		EndModal(1);
	}
}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void dInventario::OnListDobleClick( wxCommandEvent& event )  {
	int pos=m_ListaItems->GetSelection();
	Item I=m_partida->ObtenerItem(pos);
	Cant=m_Personaje->TamInv();
	bool esigual=false;
	for(int i=0;i<Cant;i++) { 
		Item I2=m_Personaje->MostrarItem(i);
		if(I==I2){ 
			wxMessageBox(wxT("No es posible agregar un item que ya exista\nen el inventario del personaje."),wxT("Error"),wxICON_ERROR);
			esigual=true;
		}
	}
	if(!esigual){ 
		m_Personaje->AgregarInv(I);
		EndModal(1);
	}
}

dInventario::~dInventario() {
	
}


