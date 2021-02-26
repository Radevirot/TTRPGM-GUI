#ifndef DNOMBREPARTIDA_H
#define DNOMBREPARTIDA_H
#include "wxfb_project.h"
#include "Partida.h"
#include "string_conv.h"
#include "vPartida.h"


class dNombrePartida : public Dialogo_NombrePartida {

private:
	Partida *m_partida;
protected:
	
	//BOTONES DE LA VENTANA
	void OnClickAceptar( wxCommandEvent& event )  override;
	void OnClickCancelar( wxCommandEvent& event )  override;
	
	//ATAJO DE TECLADO
	void OnTextEnter( wxCommandEvent& event )  override;
	
public:
	dNombrePartida(wxWindow *parent,Partida *p);
	~dNombrePartida();
};

#endif

