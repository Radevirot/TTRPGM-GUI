#include <wx/image.h>
#include "Application.h"
#include "vPrincipal.h"
#include "vPartida.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxIcon *icon = new wxICON("imagenes/logo.ico");
	m_partida = new Partida("");
	wxInitAllImageHandlers();
	vPrincipal Princ(m_partida);
	int valor = Princ.ShowModal();
	if(valor==1){
		vPartida *Part = new vPartida(NULL,m_partida);
		Part->SetIcon(wxICON(icon));
	}else{
		return false;
	}
	
	return true;
}

