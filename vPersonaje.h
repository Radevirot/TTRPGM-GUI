#ifndef VPERSONAJE_H
#define VPERSONAJE_H
#include "wxfb_project.h"
#include "Partida.h"

class vPersonaje : public Ventana_personaje {
	
private:
	Partida *m_partida;
	Personaje P;
protected:
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	
public:
	vPersonaje(wxWindow *parent, Partida *p);
	~vPersonaje();
};

#endif

