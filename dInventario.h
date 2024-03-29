#ifndef DINVENTARIO_H
#define DINVENTARIO_H
#include "wxfb_project.h"
#include "Personaje.h"
#include "Partida.h"
#include "Item.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

class dInventario : public Dialogo_Inventario {
	
private:
	Personaje *m_Personaje;
	Partida *m_partida;
	int Cant;
protected:
	
	//BOTONES DE LA LISTA
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickCancelar( wxCommandEvent& event )  override;
	
	//ATAJO DE MOUSE
	void OnListDobleClick( wxCommandEvent& event )  override;
	
public:
	dInventario(wxWindow *parent, Personaje &p, Partida *pa);
	~dInventario();
};

#endif

