#include "vDados.h"


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
	Show();
}

vDados::~vDados() {
	
}

void vDados::AgregarDado(){
	D.Modificar(wx_to_std(m_Nombre->GetValue()),m_ValMin->GetValue(),m_ValMax->GetValue());
	m_partida->AgregarDado(D);
	m_Seleccionado->Append(std_to_wx(D.ObtenerNombre()+" - Min: "+ std::to_string(D.ObtenerMin())+" - Max: "+ std::to_string(D.ObtenerMax())));
	m_Seleccionado->SetSelection(m_Seleccionado->GetCount()-1);
}

void vDados::ArrojarDado(){
	if(m_Seleccionado->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible arrojar un dado sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int Pos=m_Seleccionado->GetSelection();
		D=m_partida->ObtenerDado(Pos);
		m_Numero->SetLabel(std::to_string(D.TirarDado()));
	}
}


// BOTONES DE DADOS

void vDados::OnClickAgregar( wxCommandEvent& event )  {
	this->AgregarDado();
} 

void vDados::OnClickArrojar( wxCommandEvent& event )  {
	this->ArrojarDado();
}

void vDados::OnClickBorrar( wxCommandEvent& event )  {
	if(m_Seleccionado->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un dado sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int Pos=m_Seleccionado->GetSelection();
		m_partida->EliminarDado(Pos);
		m_Seleccionado->Delete(Pos);
		if(m_Seleccionado->GetSelection()!=wxNOT_FOUND) m_Seleccionado->SetSelection(Pos); else m_Seleccionado->SetSelection(Pos-1);
	}
	
}

void vDados::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}


// ATAJOS DE TECLADO

void vDados::OnApretarEnter( wxCommandEvent& event )  {
	this->AgregarDado();
}

void vDados::OnApretarTecla( wxKeyEvent& event )  {
	switch(event.GetKeyCode()){
	case WXK_CONTROL: manteniendoControl=true; m_Seleccionado->SetFocus(); break;
	case WXK_TAB:
		if(m_Nombre->HasFocus()){
			m_ValMin->SetFocus(); m_ValMin->SetSelection(-1,-1);
		} else if(m_ValMin->HasFocus()){
			m_ValMax->SetFocus(); m_ValMax->SetSelection(-1,-1);
		} else if(m_ValMax->HasFocus()||m_Seleccionado->HasFocus()||this->HasFocus()){
			m_Nombre->SetFocus(); m_Nombre->SetSelection(-1,-1);
		}
		break;
	case WXK_DELETE: 
		if(m_Seleccionado->HasFocus()){
			int pos = m_Seleccionado->GetSelection();
			if(pos!=wxNOT_FOUND){
				m_partida->EliminarDado(pos);
				m_Seleccionado->Delete(pos);
				if(m_Seleccionado->GetSelection()!=wxNOT_FOUND) m_Seleccionado->SetSelection(pos); else m_Seleccionado->SetSelection(pos-1);
			}
		} else event.Skip(); break;
	case WXK_ESCAPE: Close(true); break;
	case 84: if(manteniendoControl) this->ArrojarDado(); else event.Skip(); break;
	default: event.Skip(); break;
	}

}

void vDados::OnLevantarTecla( wxKeyEvent& event )  {
	switch(event.GetKeyCode()){
	case WXK_CONTROL: manteniendoControl=false; break;
	}
}


// ACTUALIZAR VENTANA

void vDados::OnActivarDado( wxActivateEvent& event )  {
	manteniendoControl=false;
}

