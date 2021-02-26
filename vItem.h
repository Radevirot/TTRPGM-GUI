#ifndef VITEM_H
#define VITEM_H
#include "wxfb_project.h"
#include "Partida.h"
#include "Item.h"
#include "string_conv.h"
#include <wx/filedlg.h>

class vItem : public Ventana_item {
	
private:
	Partida *m_partida;
	Item CargarInformacion();
	bool manteniendoControl=false;
protected:
	void OnActivarItem( wxActivateEvent& event )  override;
	void OnApretarTecla( wxKeyEvent& event )  override;
	void OnLevantarTecla( wxKeyEvent& event )  override;
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
public:
	vItem(wxWindow *parent, Partida *p);
	~vItem();
};

#endif

