#include <wx/image.h>
#include "Application.h"
#include "vPrincipal.h"
#include "vPartida.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_partida = new Partida("");
	wxIcon *icon = new wxICON();
	icon->LoadFile("D:\\Repositorios\\OdioMiVida\\TTRPGM-GUI\\imagenes\\logo.ico");
	wxInitAllImageHandlers();
	vPrincipal Princ(m_partida);
	int valor = Princ.ShowModal();
	if(valor==1){
		vPartida *Part = new vPartida(NULL,m_partida);
		Part->SetIcon(wxICON(0));
	}else{
		return false;
	}
	
	return true;
}

