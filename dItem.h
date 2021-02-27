#ifndef DITEM_H
#define DITEM_H
#include "wxfb_project.h"
#include "Partida.h"
#include "string_conv.h"
#include "Item.h"
#include <wx/filedlg.h>


class dItem : public Dialogo_item {
	
private:
	Partida *m_partida;
	Item I, *Ims;
	int pos;
	bool _usadoPorPartida=true;
	std::vector<wxSpinCtrlDouble*> vect{m_PuntosVida,m_Defenza,m_Fuerza,m_Agilidad,m_ResistenciaMagica,m_Inteligencia,m_Mana,m_Danio,m_Rango,m_Punteria,m_Bloqueo};
	void CrearTablaDeAtajos();
	void ActualizarInformacion(Item &Ite);
	void ObtenerInformacion(Item &Ite);
	
protected:
	
	// BOTONES DE LA VENTANA
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
	// ATAJOS EXTRA DE TECLADO
	void OnApretarTecla( wxKeyEvent& event )  override;
	
	// RUEDITAS
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
	dItem(wxWindow *parent, Partida *p, Item Im, int posc);
	dItem(wxWindow *parent, Partida *p, Item &Im, int posc, bool Uso);
	~dItem();
};

#endif



