#include "dItem.h"

dItem::dItem(wxWindow *parent) : Dialogo_item(parent) {
	
}

void dItem::OnClickAplicar( wxCommandEvent& event )  {
	event.Skip();
}

void dItem::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

dItem::~dItem() {
	
}

