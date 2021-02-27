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
	void Seleccion(Personaje Prs);
	void Seleccion(Personaje Ps, bool AtRc);
protected:
	
	//BOTONES DE LA VENTANA
	void OnClickAtacar( wxCommandEvent& event )  override;
	void OnClickCerrar( wxCommandEvent& event )  override;
	
	//ACTUALIZAR VENTANA
	void OnActivetaCombate( wxActivateEvent& event )  override;
	void OnChoiceAtq( wxCommandEvent& event )  override;
	void OnChoiceRecp( wxCommandEvent& event )  override;
	
	//ATAJOS DE TECLADO Y MOUSE
	void OnApretarTecla( wxKeyEvent& event )  override;
	void OnLevantarTecla( wxKeyEvent& event )  override;
	void OnClickVentana( wxMouseEvent& event )  override;
	
	// RUEDITA
	void OnScrollMult( wxMouseEvent& event )  override;
	void OnScrollAtq( wxMouseEvent& event )  override;
	void OnScrollRecp( wxMouseEvent& event )  override;
	void OnScrollFormula( wxMouseEvent& event )  override;

	
public:
	vCombate(wxWindow *parent, Partida *p);
	~vCombate();
};

#endif

