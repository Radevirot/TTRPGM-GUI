#ifndef VPARTIDA_H
#define VPARTIDA_H
#include "wxfb_project.h"

class vPartida : public Ventana_partida {
	
private:
	
protected:
	void OnClickCombate( wxCommandEvent& event )  override;
	void OnClickDado( wxCommandEvent& event )  override;
	void OnMenuNueva( wxCommandEvent& event )  override;
	void OnClickCrearP( wxCommandEvent& event )  override;
	void OnClickCrearI( wxCommandEvent& event )  override;
	
public:
	vPartida(wxWindow *parent=NULL);
	~vPartida();
};

#endif

