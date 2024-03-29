#include "vPrincipal.h"

vPrincipal::vPrincipal(Partida *p) : Ventana_principal(NULL) {
	/*
	Constructor de la ventana Principal, se le ingresa como par�metro un puntero
	de una partida nueva.
	Guarda el puntero de la partida en el privado y monta el icono del programa.
	*/
	SetIcon(wxIcon("imagenes\\logo.ico",wxBITMAP_TYPE_ICO));
	m_partida=p;
	
}

vPrincipal::~vPrincipal() {
	
}



//BOTONES DE PRINCIPAL

void vPrincipal::OnClickEmpezar( wxCommandEvent& event )  {
	/*
	Al presionar "Empezar partida", se crea una ventana que
	pide el nombre de la partida, se le coloca el icono, y
	si dicha ventana se cierra con "Aceptar" o ENTER, la
	ventana actual tambi�n lo hace.
	*/
	dNombrePartida NomPart(this,m_partida);
	NomPart.SetIcon(GetIcon());
	if(NomPart.ShowModal()==1){
		EndModal(1);
	}
}

void vPrincipal::OnClickCargar( wxCommandEvent& event )  {
	/*
	Al presionar "Cargar partida" se muestra una ventana 
	de archivos que s�lo muestra los de extensi�n .part,
	si el usuario selecciona uno, se carga la partida con 
	la ruta especificada.
	*/
	wxFileDialog cargarPartida(this,wxT("Elija un archivo de partida para cargar"),".\\datos","","Archivos PART (*.part)|*.part",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(cargarPartida.ShowModal()==wxID_OK){
		if(m_partida->Cargar(wx_to_std(cargarPartida.GetPath()))){
			EndModal(1);
		} else{
			wxMessageBox(wxT("No se pudo abrir el archivo."),wxT("Error"),wxICON_ERROR);
		}
		
	}
}

void vPrincipal::OnClickSalir( wxCommandEvent& event )  {
	/* Se cierra la ventana */
	EndModal(0);
}

