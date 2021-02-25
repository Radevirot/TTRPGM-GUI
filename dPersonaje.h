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
	void OnSpinCtrlPersonaje( wxSpinDoubleEvent& event )  override;
	void OnCheckListPersonaje( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	void OnCheckListInventario( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	
public:
	dPersonaje(wxWindow *parent, Partida *p, Personaje &P, int posc);
	~dPersonaje();
};

#endif

