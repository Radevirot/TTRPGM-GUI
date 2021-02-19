#ifndef DNOMBREPARTIDA_H
#define DNOMBREPARTIDA_H
#include "wxfb_project.h"
#include "Partida.h"

class dNombrePartida : public Dialogo_NombrePartida {

private:
	Partida *m_partida;
protected:
	void OnKeyDownEnter( wxKeyEvent& event )  override;
	void OnClickAceptar( wxCommandEvent& event )  override;
	void OnClickCancelar( wxCommandEvent& event )  override;
	
public:
	dNombrePartida(wxWindow *parent,Partida *p);
	~dNombrePartida();
};

#endif

