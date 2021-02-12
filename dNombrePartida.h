#ifndef DNOMBREPARTIDA_H
#define DNOMBREPARTIDA_H
#include "wxfb_project.h"

class dNombrePartida : public Dialogo_NombrePartida {
	
private:
	
protected:
	void OnClickCancelar( wxCommandEvent& event )  override;
	void OnClickAceptar( wxCommandEvent& event )  override;
	
public:
	dNombrePartida(wxWindow *parent=NULL);
	~dNombrePartida();
};

#endif

