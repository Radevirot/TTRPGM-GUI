#include "vDados.h"


vDados::vDados(wxWindow *parent, Partida *p) : Ventana_dados(parent) {
	/*
	Constructor de la ventana Dados, se le ingresan como parámetros un puntero
	a la ventana  y otro a la partida actual.
	Carga los dados anteriormente creados, autoselecciona el primero de estos
	y muestra la ventana.
	*/
	
	wxAcceleratorEntry entries[5];
	entries[0].Set(0,WXK_RETURN, wxID_HIGHEST+12);
	entries[1].Set(0,WXK_TAB, wxID_HIGHEST+13);
	entries[2].Set(wxACCEL_CTRL,(int) 'T', wxID_HIGHEST+14);
	entries[3].Set(0,WXK_DELETE, wxID_HIGHEST+15);
	entries[4].Set(0,WXK_ESCAPE, wxID_HIGHEST+16);
	wxAcceleratorTable accel(5, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+12 , wxEVT_MENU, wxCommandEventHandler( vDados::OnClickAgregar ));
	Connect( wxID_HIGHEST+13 , wxEVT_MENU, wxCommandEventHandler( vDados::OnApretarTab ));
	Connect( wxID_HIGHEST+14 , wxEVT_MENU, wxCommandEventHandler( vDados::OnClickArrojar ));
	Connect( wxID_HIGHEST+15 , wxEVT_MENU, wxCommandEventHandler( vDados::OnApretarSupr ));
	Connect( wxID_HIGHEST+16 , wxEVT_MENU, wxCommandEventHandler( vDados::OnClickCerrar ));
	
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



// BOTONES DE DADOS

void vDados::OnClickAgregar( wxCommandEvent& event )  {
	/*
	Agrega un dado a la lista de los mismos.
	*/
	D.Modificar(wx_to_std(m_Nombre->GetValue()),m_ValMin->GetValue(),m_ValMax->GetValue());
	m_partida->AgregarDado(D);
	m_Seleccionado->Append(std_to_wx(D.ObtenerNombre()+" - Min: "+ std::to_string(D.ObtenerMin())+" - Max: "+ std::to_string(D.ObtenerMax())));
	m_Seleccionado->SetSelection(m_Seleccionado->GetCount()-1);
} 

void vDados::OnClickArrojar( wxCommandEvent& event )  {
	/*
	"Arroja el dado", dando un numero alzar dependiendo el dado seleccionado
	en la lista.
	*/
	if(m_Seleccionado->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible arrojar un dado sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int Pos=m_Seleccionado->GetSelection();
		D=m_partida->ObtenerDado(Pos);
		m_Numero->SetLabel(std::to_string(D.TirarDado()));
	}
}

void vDados::OnClickBorrar( wxCommandEvent& event )  {
	/*
	Borra el dado seleccionado y deja la seleccion en ese lugar.
	*/
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
	/*
	Cierra la ventana dados.
	*/
	Close(true);
}


// ATAJOS DE TECLADO

void vDados::OnApretarTab( wxCommandEvent& event ){
	/*
	Con la tecla "TAB" cambia la seleccion entre nombre, valor maximo y minimo.
	*/
	if(m_Nombre->HasFocus()){
		m_ValMin->SetFocus(); m_ValMin->SetSelection(-1,-1);
	} else if(m_ValMin->HasFocus()){
		m_ValMax->SetFocus(); m_ValMax->SetSelection(-1,-1);
	} else if(m_ValMax->HasFocus()||m_Seleccionado->HasFocus()||this->HasFocus()){
		m_Nombre->SetFocus(); m_Nombre->SetSelection(-1,-1);
	}
}

void vDados::OnApretarSupr( wxCommandEvent& event ){
	/*
	Con la tecla "Supr" borra el dado seleccionado.
	*/
	if(m_Seleccionado->HasFocus()){
		int pos = m_Seleccionado->GetSelection();
		if(pos!=wxNOT_FOUND){
			m_partida->EliminarDado(pos);
			m_Seleccionado->Delete(pos);
			if(m_Seleccionado->GetSelection()!=wxNOT_FOUND) m_Seleccionado->SetSelection(pos); else m_Seleccionado->SetSelection(pos-1);
		}
	} else event.Skip();
}


void vDados::OnApretarTecla( wxKeyEvent& event )  {
	/*
	Detecta si toca control para focusear la lista.
	*/
	if(event.GetKeyCode()==WXK_CONTROL) m_Seleccionado->SetFocus(); else event.Skip();
}


