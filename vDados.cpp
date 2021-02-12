#include "vDados.h"
#include "Partida.h"
#include "Dado.h"
#include "string_conv.h"


vDados::vDados(wxWindow *parent) : Ventana_dados(parent) {
	Show();
}

vDados::~vDados() {
	
}

void vDados::OnClickSeleccionado( wxCommandEvent& event )  {
	event.Skip();
}

void vDados::OnClickAgregar( wxCommandEvent& event )  {
	Dado D;
	D.Modificar(wx_to_std(m_Nombre->GetValue()),m_ValMin->GetValue(),m_ValMax->GetValue());
} 

void vDados::OnClickArrojar( wxCommandEvent& event )  {
	event.Skip();
}

void vDados::OnClickBorrar( wxCommandEvent& event )  {
	event.Skip();
}

void vDados::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

