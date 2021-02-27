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
protected:

	// BOTONES
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
	// ATAJOS EXTRA
	void OnApretarTecla( wxKeyEvent& event )  override;
	
	// MOVER LA RUEDA DEL MOUSE
	void OnRueditaDanio( wxMouseEvent& event )  override;
	void OnRueditaRango( wxMouseEvent& event )  override;
	void OnRueditaPunt( wxMouseEvent& event )  override;
	void OnRueditaBloq( wxMouseEvent& event )  override;
	void OnRueditaDef( wxMouseEvent& event )  override;
	void OnRueditaResM( wxMouseEvent& event )  override;
	void OnRueditaVida( wxMouseEvent& event )  override;
	void OnRueditaFuerza( wxMouseEvent& event )  override;
	void OnRueditaAgi( wxMouseEvent& event )  override;
	void OnRueditaInte( wxMouseEvent& event )  override;
	void OnRueditaMana( wxMouseEvent& event )  override;
	
public:
	vItem(wxWindow *parent, Partida *p);
	~vItem();
};

#endif

