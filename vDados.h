#ifndef VDADOS_H
#define VDADOS_H
#include "wxfb_project.h"

class vDados : public Ventana_dados {
	
private:
	
protected:
	void OnClickSeleccionado( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickArrojar( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickCerrar( wxCommandEvent& event )  override;
	
public:
	vDados(wxWindow *parent=NULL);
	~vDados();
};

#endif

