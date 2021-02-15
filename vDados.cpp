#include "vDados.h"
#include "Dado.h"
#include "string_conv.h"
#include <string>



vDados::vDados(wxWindow *parent, Partida *p) : Ventana_dados(parent) {
	m_partida=p;
	Show();
}

vDados::~vDados() {
	
}


void vDados::OnClickAgregar( wxCommandEvent& event )  {
	D.Modificar(wx_to_std(m_Nombre->GetValue()),m_ValMin->GetValue(),m_ValMax->GetValue());
	m_partida->AgregarDado(D);
	m_Seleccionado->Append(std_to_wx(D.ObtenerNombre()+" - Min: "+ std::to_string(D.ObtenerMin())+" - Max: "+ std::to_string(D.ObtenerMax())));
	int val=m_Seleccionado->GetCount();
	m_Seleccionado->SetSelection(val);
} 

void vDados::OnClickArrojar( wxCommandEvent& event )  {
	int Pos=m_Seleccionado->GetSelection();
	D=m_partida->ObtenerDado(Pos);
	m_Numero->SetLabel(std::to_string(D.TirarDado()));
}

void vDados::OnClickBorrar( wxCommandEvent& event )  {
	int Pos=m_Seleccionado->GetSelection();
	m_partida->EliminarDado(Pos);
	m_Seleccionado->Delete(Pos);
	m_Seleccionado->SetSelection(0);
}

void vDados::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

