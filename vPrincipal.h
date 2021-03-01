#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "wxfb_project.h"
#include "Partida.h"
#include "dNombrePartida.h"
#include "wx/icon.h"
	
class vPrincipal : public Ventana_principal {
	
private:
	Partida *m_partida;
protected:
	
	//BOTONES DE PRINCIPAL
	void OnClickEmpezar( wxCommandEvent& event )  override;
	void OnClickCargar( wxCommandEvent& event )  override;
	void OnClickSalir( wxCommandEvent& event )  override;
	
public:
	vPrincipal(Partida *p);
	~vPrincipal();
};

#endif

