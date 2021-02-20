#include "dItem.h"

dItem::dItem(wxWindow *parent, Partida *p, Item Im, int posc) : Dialogo_item(parent) {
	m_partida=p;
	I=Im;
	pos=posc;
	m_NombreItem->SetLabel(std_to_wx(I.ObtenerNombre()));
	m_Cantidad->SetValue(std_to_wx(std::to_string(I.ObtenerCant())));
	m_PuntosVida->SetValue(std_to_wx(std::to_string(I.ObtenerStat(0)))); 
	m_Defenza->SetValue(std_to_wx(std::to_string(I.ObtenerStat(1)))); 
	m_Fuerza->SetValue(std_to_wx(std::to_string(I.ObtenerStat(2)))); 
	m_Agilidad->SetValue(std_to_wx(std::to_string(I.ObtenerStat(3)))); 
	m_ResistenciaMagica->SetValue(std_to_wx(std::to_string(I.ObtenerStat(4))));
	m_Inteligencia->SetValue(std_to_wx(std::to_string(I.ObtenerStat(5))));
	m_Mana->SetValue(std_to_wx(std::to_string(I.ObtenerStat(6))));
	m_Danio->SetValue(std_to_wx(std::to_string(I.ObtenerStat(7)))); 
	m_Rango->SetValue(std_to_wx(std::to_string(I.ObtenerStat(8)))); 
	m_Punteria->SetValue(std_to_wx(std::to_string(I.ObtenerStat(9)))); 
	m_Bloqueo->SetValue(std_to_wx(std::to_string(I.ObtenerStat(10)))); 
	m_Detalle->SetLabel(std_to_wx(I.ObtenerDetalle())); 
	m_Descripcion->SetLabel(std_to_wx(I.ObtenerDesc()));
	Show();
}

void dItem::OnClickAplicar( wxCommandEvent& event )  {

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
	m_partida->EliminarItem(pos);
	m_partida->AgregarItem(I);
	EndModal(1);
	
}

void dItem::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

dItem::~dItem() {
	
}