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
	std::vector <wxStaticText*> textos{m_PVt,m_DFNt,m_FRZt,m_AGLt,m_RMt,m_INTt,m_MNt,m_DN,m_RNG,m_PNT,m_BLQ};
	std::vector <wxSpinCtrlDouble*> spins{m_PVb,m_DFNb,m_FRZb,m_AGLb,m_RMb,m_INTb,m_MNb};
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
	
	//ATAJOS DE TECLADO
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
	dPersonaje(wxWindow *parent, Partida *p, Personaje &P, int posc);
	~dPersonaje();
};

#endif

