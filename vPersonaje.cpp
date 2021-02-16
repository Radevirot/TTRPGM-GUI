#include "vPersonaje.h"
#include "Personaje.h"
#include "Partida.h"
#include "string_conv.h"
#include "dInventario.h"

vPersonaje::vPersonaje(wxWindow *parent, Partida *p) : Ventana_personaje(parent) {
	m_partida=p;
	Show();
}

vPersonaje::~vPersonaje() {
	
}

void vPersonaje::OnClickAplicar( wxCommandEvent& event )  {
	Personaje P;
	P.NombrarPersonaje(wx_to_std(m_Nombre->GetValue()));
	P.ModificarNivel(m_Nivel->GetValue());
	P.ModificarXP(m_EXP->GetValue());
	P.ModificarStat(0,(m_PVb->GetValue()));
	P.ModificarStat(1,(m_DFNb->GetValue()));
	P.ModificarStat(2,(m_FRZb->GetValue()));
	P.ModificarStat(3,(m_AGLb->GetValue()));
	P.ModificarStat(4,(m_RMb->GetValue()));
	P.ModificarStat(5,(m_INTb->GetValue()));
	P.ModificarStat(6,(m_MNb->GetValue()));
	P.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	//HACER URGENTE CAPO inventario
	
}

void vPersonaje::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

void vPersonaje::OnClickAgregar( wxCommandEvent& event )  {
	dInventario Inv(this,m_partida);
	Inv.ShowModal();
}

