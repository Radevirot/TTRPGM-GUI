#ifndef VPARTIDA_H
#define VPARTIDA_H
#include "wxfb_project.h"
#include "Partida.h"

class vPartida : public Ventana_partida {
	
private:
	Partida *m_partida;
	void ActualizarNombre();
protected:
	void OnClickCombate( wxCommandEvent& event )  override;
	void OnClickDado( wxCommandEvent& event )  override;
	void OnMenuNueva( wxCommandEvent& event )  override;
	void OnClickCrearP( wxCommandEvent& event )  override;
	void OnClickCrearI( wxCommandEvent& event )  override;
	void OnFocusPartida( wxFocusEvent& event )  override;
	
public:
	vPartida(wxWindow *parent, Partida *p);
	~vPartida();
};

#endif

