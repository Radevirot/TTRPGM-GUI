#ifndef DITEM_H
#define DITEM_H
#include "wxfb_project.h"

class dItem : public Dialogo_item {
	
private:
	
protected:
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
public:
	dItem(wxWindow *parent=NULL);
	~dItem();
};

#endif

