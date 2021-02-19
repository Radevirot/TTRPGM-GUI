#ifndef DITEM_H
#define DITEM_H
#include "wxfb_project.h"
#include "Partida.h"

class dItem : public Dialogo_item {
	
private:
	Partida *m_partida;
protected:
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
public:
	dItem(wxWindow *parent, Partida *p);
	~dItem();
};

#endif

