#ifndef VCOMBATE_H
#define VCOMBATE_H
#include "wxfb_project.h"
#include "Partida.h"
#include "string_conv.h"
#include "Personaje.h"

class vCombate : public Ventana_combate {
	
private:
	Partida *m_partida;
	int PosUAt=0, PosURc=1;
protected:
	void Seleccion(Personaje Prs);
	void Seleccion(Personaje Ps, bool AtRc);
	void OnChoiceAtq( wxCommandEvent& event )  override;
	void OnChoiceRecp( wxCommandEvent& event )  override;
	void OnActivetaCombate( wxActivateEvent& event )  override;
	void OnClickAtacar( wxCommandEvent& event )  override;
	void OnClickCerrar( wxCommandEvent& event )  override;
	
public:
	vCombate(wxWindow *parent, Partida *p);
	~vCombate();
};

#endif

