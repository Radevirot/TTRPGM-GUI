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
	std::vector <wxStaticText*> textos{m_PVt,m_DFNt,m_FRZt,m_AGLt,m_RMt,m_INTt,m_MNt,m_DN,m_RNG,m_PNT,m_BLQ};
	std::vector <wxSpinCtrlDouble*> spins{m_PVb,m_DFNb,m_FRZb,m_AGLb,m_RMb,m_INTb,m_MNb};
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
	
	// ATAJOS DE TECLADO
	void OnApretarSupr( wxCommandEvent& event );
	void OnApretarTecla( wxKeyEvent& event )  override;
	
	//ACTUALIZAR VENTANA
	void OnSpinCtrlPersonaje( wxSpinDoubleEvent& event )  override;
	
	//RUEDITAS
	void OnRueditaEXP( wxMouseEvent& event )  override;
	void OnRueditaVida( wxMouseEvent& event )  override;
	void OnRueditaDef( wxMouseEvent& event )  override;
	void OnRueditaFuerza( wxMouseEvent& event )  override;
	void OnRueditaAgi( wxMouseEvent& event )  override;
	void OnRueditaResM( wxMouseEvent& event )  override;
	void OnRueditaInte( wxMouseEvent& event )  override;
	void OnRueditaMana( wxMouseEvent& event )  override;
	
public:
	vPersonaje(wxWindow *parent, Partida *p);
	~vPersonaje();
};

#endif

