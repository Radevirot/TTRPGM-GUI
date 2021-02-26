#ifndef VITEM_H
#define VITEM_H
#include "wxfb_project.h"
#include "Partida.h"
#include "Item.h"
#include "string_conv.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

class vItem : public Ventana_item {
	
private:
	Partida *m_partida;
	Item CargarInformacion();
	std::vector<wxSpinCtrlDouble*> vect{m_PuntosVida,m_Defenza,m_Fuerza,m_Agilidad,m_ResistenciaMagica,m_Inteligencia,m_Mana,m_Danio,m_Rango,m_Punteria,m_Bloqueo};
	bool manteniendoControl=false;
protected:
	void OnRueditaDanio( wxMouseEvent& event )  override;
	void OnActivarItem( wxActivateEvent& event )  override;
	void OnApretarTecla( wxKeyEvent& event )  override;
	void OnLevantarTecla( wxKeyEvent& event )  override;
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	void OnCtrlAltEspacio( wxCommandEvent& event );
public:
	vItem(wxWindow *parent, Partida *p);
	~vItem();
};

#endif

