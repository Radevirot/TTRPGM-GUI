#include "vPrincipal.h"

vPrincipal::vPrincipal(Partida *p) : Ventana_principal(NULL) {
	/*
	Constructor de la ventana Principal, se le ingresa como parámetro un puntero
	de una partida nueva.
	Guarda el puntero de la partida en el privado y monta el icono del programa.
	*/
	m_partida=p;
	wxBitmap prueba(wxT("imagenes/logo.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(prueba);
	_icon=icon;
	this->SetIcon(icon);
}


//BOTONES DE PRINCIPAL

void vPrincipal::OnClickEmpezar( wxCommandEvent& event )  {
	/*
	Abre la ventana dNombrePartida, si le da un nombre esta ventana Principal se
	cierra.
	*/
	dNombrePartida NomPart(this,m_partida);
	NomPart.SetIcon(_icon);
	int valor = NomPart.ShowModal();
	if(valor==1){
		EndModal(1);
	}
}

void vPrincipal::OnClickCargar( wxCommandEvent& event )  {
	/*
	Abre la ventana de archivos y carga una partida guardada con anterioridad.
	*/
	wxFileDialog cargarPartida(this,wxT("Elija un archivo de partida para cargar"),".\\datos","","Archivos PART (*.part)|*.part",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(cargarPartida.ShowModal()==wxID_OK){
		m_partida->Cargar(wx_to_std(cargarPartida.GetPath()));
		EndModal(1);
	}
}

void vPrincipal::OnClickSalir( wxCommandEvent& event )  {
	/*
	Cierra la ventana Principal.
	*/
	EndModal(0);
}

vPrincipal::~vPrincipal() {
	
}

