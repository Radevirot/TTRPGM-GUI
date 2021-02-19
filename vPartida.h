#ifndef VPARTIDA_H
#define VPARTIDA_H
#include "wxfb_project.h"
#include "Partida.h"
#include "vItem.h"


class vPartida : public Ventana_partida {
	
private:
	Partida *m_partida;
	void ActualizarNombre();
protected:
	void OnEntrarPartida( wxMouseEvent& event )  override;
	void OnMenuEditar( wxCommandEvent& event )  override;
	void OnMenuGuardar( wxCommandEvent& event )  override;
	void OnMenuCargar( wxCommandEvent& event )  override;
	void OnMenuAyuda( wxCommandEvent& event )  override;
	void OnDobleClickListaPersonaje( wxCommandEvent& event )  override;
	void OnClickBorrarPersonaje( wxCommandEvent& event )  override;
	void OnClickVerInventario( wxCommandEvent& event )  override;
	void OnDobleClickListaItem( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	void OnClickCombate( wxCommandEvent& event )  override;
	void OnClickDado( wxCommandEvent& event )  override;
	void OnMenuNueva( wxCommandEvent& event )  override;
	void OnClickCrearP( wxCommandEvent& event )  override;
	void OnClickCrearI( wxCommandEvent& event )  override;
	
public:
	vPartida(wxWindow *parent, Partida *p);
	~vPartida();
};

#endif

