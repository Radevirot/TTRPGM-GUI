#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "wxfb_project.h"

class vPrincipal : public Ventana_principal {
	
private:
	
protected:
	void OnClickEmpezar( wxCommandEvent& event )  override;
	void OnClickCargar( wxCommandEvent& event )  override;
	void OnClickSalir( wxCommandEvent& event )  override;
	
public:
	vPrincipal(wxWindow *parent=NULL);
	~vPrincipal();
};

#endif

