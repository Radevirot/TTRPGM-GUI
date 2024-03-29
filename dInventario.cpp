#include "dInventario.h"

dInventario::dInventario(wxWindow *parent, Personaje &p, Partida *pa) : Dialogo_Inventario(parent) {
	/*
	Constructor de la ventana dInventario, se le ingresan como parámetros un puntero
	a la ventana padre, otro a la partida actual y un personaje por referencia.
	Carga y muestra los items de la partida.
	*/
	
	wxAcceleratorEntry entries[2];
	entries[1].Set(0,WXK_RETURN, wxID_HIGHEST+30);
	entries[2].Set(0,WXK_ESCAPE, wxID_HIGHEST+31);
	wxAcceleratorTable accel(2, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+30 , wxEVT_MENU, wxCommandEventHandler( dInventario::OnClickAgregar ));
	Connect( wxID_HIGHEST+31 , wxEVT_MENU, wxCommandEventHandler( dInventario::OnClickCancelar ));
	
	m_Personaje=&p;
	m_partida=pa;
	Cant=m_partida->ObtenerCantidadDeItems();
	for(int i=0;i<Cant;i++) { 
		Item I=m_partida->ObtenerItem(i);
		m_ListaItems->Append(std_to_wx(I.ObtenerNombre()));
	}
	if(m_partida->ObtenerCantidadDeItems()!=0) m_ListaItems->SetSelection(0);
}

dInventario::~dInventario() {
	
}



//BOTONES DE LA LISTA

void dInventario::OnClickAgregar( wxCommandEvent& event )  {
	/*
	Pasa al inventario del personaje el item seleccionado.
	Si es igual a un item existente en el inventario salta un error.
	Si no hay ningun item marcado salta un error.
	*/
	int pos=m_ListaItems->GetSelection();
	if(pos==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible agregar un item sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
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

}

void dInventario::OnClickCancelar( wxCommandEvent& event )  {
	/* Cierra la ventana. */
	EndModal(0);
}


//ATAJO DE MOUSE

void dInventario::OnListDobleClick( wxCommandEvent& event )  {
	/*
	Con Doble-Click pasa al inventario del personaje el item seleccionado.
	Si es igual a un item existente en el inventario salta un error.
	Si no hay ningun item marcado salta un error.
	*/
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



