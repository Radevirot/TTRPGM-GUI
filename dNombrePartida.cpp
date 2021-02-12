#include "dNombrePartida.h"
#include "Partida.h"
#include "string_conv.h"
#include "Application.h"

dNombrePartida::dNombrePartida(wxWindow *parent) : Dialogo_NombrePartida(parent) {
	
}

dNombrePartida::~dNombrePartida() {
	
}

void dNombrePartida::OnClickAceptar( wxCommandEvent& event )  {
	Destroy();
	Partida p(wx_to_std(m_textCtrlNombrePart->GetValue()));
}

void dNombrePartida::OnClickCancelar( wxCommandEvent& event )  {
	Close(true);
}

