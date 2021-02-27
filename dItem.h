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
	bool booleano=true;
	std::vector<wxSpinCtrlDouble*> vect{m_PuntosVida,m_Defenza,m_Fuerza,m_Agilidad,m_ResistenciaMagica,m_Inteligencia,m_Mana,m_Danio,m_Rango,m_Punteria,m_Bloqueo};
	void CrearTablaDeAtajos();
	void ActualizarInformacion(Item &Ite);
	void ObtenerInformacion(Item &Ite);
	
protected:
	
	//BOTONES DE EDICION DE ITEM
	void OnClickAplicar( wxCommandEvent& event )  override;
	void OnClickExportar( wxCommandEvent& event )  override;
	
public:
	dItem(wxWindow *parent, Partida *p, Item Im, int posc);
	dItem(wxWindow *parent, Partida *p, Item &Im, int posc, bool Uso);
	~dItem();
};

#endif



