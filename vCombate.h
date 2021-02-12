#ifndef VCOMBATE_H
#define VCOMBATE_H
#include "wxfb_project.h"

class vCombate : public Ventana_combate {
	
private:
	
protected:
	void OnClickCerrar( wxCommandEvent& event )  override;
	
public:
	vCombate(wxWindow *parent=NULL);
	~vCombate();
};

#endif

