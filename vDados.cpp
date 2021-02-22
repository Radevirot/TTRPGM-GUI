#include "vDados.h"
#include "Dado.h"
#include "dErrorArrojarsinSelec.h"
#include "string_conv.h"
#include <string>
#include <wx/msgdlg.h>



vDados::vDados(wxWindow *parent, Partida *p) : Ventana_dados(parent) {
	/*
	Constructor de la ventana Dados, se le ingresan como parámetros un puntero
	a la ventana  y otro a la partida actual.
	Carga los dados anteriormente creados, autoselecciona el primero de estos
	y muestra la ventana.
	*/
	m_partida=p;
	for(int i=0;i<m_partida->ObtenerCantidadDeDados();i++) { 
		D=m_partida->ObtenerDado(i);
		m_Seleccionado->Append(std_to_wx(D.ObtenerNombre()+" - Min: "+ std::to_string(D.ObtenerMin())+" - Max: "+ std::to_string(D.ObtenerMax())));
		m_Seleccionado->SetSelection(0);
	}
	m_Seleccionado->SetSelection(0);
	Show();
}

vDados::~vDados() {
	
}

// BOTONES

void vDados::OnClickAgregar( wxCommandEvent& event )  {
	D.Modificar(wx_to_std(m_Nombre->GetValue()),m_ValMin->GetValue(),m_ValMax->GetValue());
	m_partida->AgregarDado(D);
	m_Seleccionado->Append(std_to_wx(D.ObtenerNombre()+" - Min: "+ std::to_string(D.ObtenerMin())+" - Max: "+ std::to_string(D.ObtenerMax())));
	m_Seleccionado->SetSelection(m_Seleccionado->GetCount()-1);
} 

void vDados::OnClickArrojar( wxCommandEvent& event )  {
	if(m_Seleccionado->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible arrojar un dado sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int Pos=m_Seleccionado->GetSelection();
		D=m_partida->ObtenerDado(Pos);
		m_Numero->SetLabel(std::to_string(D.TirarDado()));
	}

}

void vDados::OnClickBorrar( wxCommandEvent& event )  {
	if(m_Seleccionado->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un dado sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int Pos=m_Seleccionado->GetSelection();
		m_partida->EliminarDado(Pos);
		m_Seleccionado->Delete(Pos);
		m_Seleccionado->SetSelection(0);
	}

}

void vDados::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

