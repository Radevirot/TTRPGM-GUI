#ifndef VDADOS_H
#define VDADOS_H
#include "wxfb_project.h"
#include "Partida.h"
#include <string>
#include "Dado.h"
#include "string_conv.h"
#include <wx/msgdlg.h>


class vDados : public Ventana_dados {
	
private:
	Partida *m_partida;
	Dado D;
protected:
	
	//BOTONES DE DADOS
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickArrojar( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickCerrar( wxCommandEvent& event )  override;
	
	//ATAJOS DE TECLADO
	void OnApretarTecla( wxKeyEvent& event )  override;
	void OnApretarTab( wxCommandEvent& event );
	void OnApretarSupr( wxCommandEvent& event );

	
public:
	vDados(wxWindow *parent, Partida *p);
	~vDados();
};

#endif

