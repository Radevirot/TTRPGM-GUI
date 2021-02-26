#ifndef VPERSONAJE_H
#define VPERSONAJE_H
#include "wxfb_project.h"
#include "wx/dynarray.h"
#include "Partida.h"
#include <string>
#include "Personaje.h"
#include "string_conv.h"
#include "dInventario.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include "Item.h"
#include "dItem.h"

class vPersonaje : public Ventana_personaje {
	
private:
	Partida *m_partida;
	Personaje m_Personaje;
	int it=0;
	wxArrayInt W;
	void Actualizacion();
	void GuardarCambios();
protected:
	
	//BOTONES DE CREACION DE PERSONAJE 
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
	vPersonaje(wxWindow *parent, Partida *p);
	~vPersonaje();
};

#endif

