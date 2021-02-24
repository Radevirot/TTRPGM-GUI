#include "vPrincipal.h"

vPrincipal::vPrincipal(Partida *p) : Ventana_principal(NULL) {
	m_partida=p;
}

void vPrincipal::OnClickEmpezar( wxCommandEvent& event )  {
	dNombrePartida NomPart(this,m_partida);
	int valor = NomPart.ShowModal();
	if(valor==1){
		EndModal(1);
	}
}

void vPrincipal::OnClickCargar( wxCommandEvent& event )  {
	wxFileDialog cargarPartida(this,wxT("Elija un archivo de partida para cargar"),".\\datos","","Archivos PART (*.part)|*.part",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(cargarPartida.ShowModal()==wxID_OK){
		Partida b("");
		*m_partida=b;
		m_partida->Cargar(wx_to_std(cargarPartida.GetPath()));
		EndModal(1);
	}
}

void vPrincipal::OnClickSalir( wxCommandEvent& event )  {
	EndModal(0);
}

vPrincipal::~vPrincipal() {
	
}

