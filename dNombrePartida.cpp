#include "dNombrePartida.h"
#include "Partida.h"
#include "string_conv.h"
#include "vPartida.h"

dNombrePartida::dNombrePartida(wxWindow *parent, Partida *p) : Dialogo_NombrePartida(parent) {
	m_partida=p;
}

dNombrePartida::~dNombrePartida() {
	
}

void dNombrePartida::OnClickAceptar( wxCommandEvent& event )  {
	m_partida->ModificarNombre(wx_to_std(m_textCtrlNombrePart->GetValue()));
	EndModal(1);
}

void dNombrePartida::OnClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}


void dNombrePartida::OnKeyDownEnter( wxKeyEvent& event )  {
	event.Skip();
}

