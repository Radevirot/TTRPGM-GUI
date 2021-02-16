#ifndef DINVENTARIO_H
#define DINVENTARIO_H
#include "wxfb_project.h"
#include "Partida.h"

class dInventario : public Dialogo_Inventario {
	
private:
	Partida *m_partida;
protected:
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickCancelar( wxCommandEvent& event )  override;
	
public:
	dInventario(wxWindow *parent, Partida *p);
	~dInventario();
};

#endif

