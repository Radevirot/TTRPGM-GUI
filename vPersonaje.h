#ifndef VPERSONAJE_H
#define VPERSONAJE_H
#include "wxfb_project.h"
#include "wx/dynarray.h"
#include "Partida.h"
#include <string>


class vPersonaje : public Ventana_personaje {
	
private:
	Partida *m_partida;
	Personaje *m_Personaje;
	int i=0;
	bool m_tipo;
	wxArrayInt W;
protected:
	void OnCheckListInventario( wxCommandEvent& event )  override;
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	
public:
	vPersonaje(wxWindow *parent, Partida *p, bool tipo);
	~vPersonaje();
};

#endif

