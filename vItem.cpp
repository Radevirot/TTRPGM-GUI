#include "vItem.h"

vItem::vItem(wxWindow *parent) : Ventana_item(parent) {
	Show();
}

vItem::~vItem() {
	
}

void vItem::OnClickAplicar( wxCommandEvent& event )  {
	event.Skip();
}

void vItem::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

