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
	bool manteniendoControl=false;
	void AgregarDado();
	void ArrojarDado();
protected:
	void OnActivarDado( wxActivateEvent& event )  override;
	void OnApretarTecla( wxKeyEvent& event )  override;
	void OnLevantarTecla( wxKeyEvent& event )  override;
	void OnApretarEnter( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickArrojar( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickCerrar( wxCommandEvent& event )  override;
	
public:
	vDados(wxWindow *parent, Partida *p);
	~vDados();
};

#endif

