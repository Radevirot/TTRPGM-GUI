#include "vItem.h"

vItem::vItem(wxWindow *parent, Partida *p) : Ventana_item(parent) {
	m_partida=p;
	Show();
}

vItem::~vItem() {
	
}

void vItem::OnClickAplicar( wxCommandEvent& event )  {
	Item I;
	I.NombrarItem(wx_to_std(m_NombreItem->GetLabel()));
}

void vItem::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

