#ifndef VDADOS_H
#define VDADOS_H
#include "wxfb_project.h"
#include "Partida.h"
#include <string>

class vDados : public Ventana_dados {
	
private:
	Partida *m_partida;
	Dado D;
protected:
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickArrojar( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickCerrar( wxCommandEvent& event )  override;
	
public:
	vDados(wxWindow *parent, Partida *p);
	~vDados();
};

#endif

