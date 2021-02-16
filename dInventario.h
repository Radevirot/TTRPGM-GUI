#ifndef DINVENTARIO_H
#define DINVENTARIO_H
#include "wxfb_project.h"

class dInventario : public Dialogo_Inventario {
	
private:
	
protected:
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickCancelar( wxCommandEvent& event )  override;
	
public:
	dInventario(wxWindow *parent=NULL);
	~dInventario();
};

#endif

