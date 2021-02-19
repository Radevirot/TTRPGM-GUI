#ifndef DITEM_H
#define DITEM_H
#include "wxfb_project.h"
#include "Partida.h"
#include "string_conv.h"
#include "Item.h"


class dItem : public Dialogo_item {
	
private:
	Partida *m_partida;
	Item I;
	int pos;
protected:
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
public:
	dItem(wxWindow *parent, Partida *p, Item Im, int posc);
	~dItem();
};

#endif



