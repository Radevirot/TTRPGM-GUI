#include "vItem.h"

vItem::vItem(wxWindow *parent, Partida *p, bool tipo) : Ventana_item(parent) {
	m_partida=p;
	m_tipo=tipo;
	if(tipo){
		m_button7->SetLabel(std_to_wx("Crear"));
		this->SetTitle(std_to_wx("TTRPGM: Creación de Item"));
	}else{
		m_button7->SetLabel(std_to_wx("Aplicar cambios"));
		this->SetTitle(std_to_wx("TTRPGM: Modificación de Item"));
	}
	Show();
}

vItem::~vItem() {
	
}

void vItem::OnClickAplicar( wxCommandEvent& event )  {
	Item I;
	I.NombrarItem(wx_to_std(m_NombreItem->GetValue()));
	I.ModificarCant(m_Cantidad->GetValue());
	I.ModificarStat(0,(m_PuntosVida->GetValue()));
	I.ModificarStat(1,(m_Defenza->GetValue()));
	I.ModificarStat(2,(m_Fuerza->GetValue()));
	I.ModificarStat(3,(m_Agilidad->GetValue()));
	I.ModificarStat(4,(m_ResistenciaMagica->GetValue()));
	I.ModificarStat(5,(m_Inteligencia->GetValue()));
	I.ModificarStat(6,(m_Mana->GetValue()));
	I.ModificarStat(7,(m_Danio->GetValue()));
	I.ModificarStat(8,(m_Rango->GetValue()));
	I.ModificarStat(9,(m_Punteria->GetValue()));
	I.ModificarStat(10,(m_Bloqueo->GetValue()));
	I.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	I.ModificarDesc(wx_to_std(m_Descripcion->GetValue()));
	m_partida->AgregarItem(I);
	if(m_tipo){
		Close(true);
	}
}

void vItem::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

