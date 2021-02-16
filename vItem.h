#ifndef VITEM_H
#define VITEM_H
#include "wxfb_project.h"

class vItem : public Ventana_item {
	
private:
	
protected:
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
public:
	vItem(wxWindow *parent=NULL);
	~vItem();
};

#endif

