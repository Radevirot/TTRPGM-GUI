#ifndef DPERSONAJE_H
#define DPERSONAJE_H
#include "wxfb_project.h"
#include "Partida.h"
#include "Personaje.h"
#include <string>
#include <vector>
#include "wx/dynarray.h"
#include "string_conv.h"
#include "dInventario.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include "Item.h"
#include "dItem.h"

class dPersonaje : public Dialogo_Personaje {
	
private:
	Partida *m_partida;
	Personaje m_Personaje;
	int pos;
	int it=0;
	wxArrayInt W;
	void Actualizacion();
	void GuardarCambios();
protected:
	
	//BOTONES DE EDICION DE PERSONAJE 
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	
	//TILDADO DE ITEM EN INVENTARIO
	void OnCheckListInventario( wxCommandEvent& event )  override;
	
	//ATAJO DE MOUSE
	void OnCheckListPersonaje( wxCommandEvent& event )  override;
	
	//ACTUALIZAR VENTANA
	void OnSpinCtrlPersonaje( wxSpinDoubleEvent& event )  override;
	
public:
	dPersonaje(wxWindow *parent, Partida *p, Personaje &P, int posc);
	~dPersonaje();
};

#endif

