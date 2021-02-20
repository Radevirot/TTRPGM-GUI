#ifndef VPARTIDA_H
#define VPARTIDA_H
#include "wxfb_project.h"
#include "Partida.h"
#include "vItem.h"


class vPartida : public Ventana_partida {
	
private:
	Partida *m_partida;
	void ActualizarNombre();
	void ActualizarListas();
protected:
	// Por encima de esta línea sólo hay métodos duplicados
	
	// BARRA DE MENU
	void OnMenuEditar( wxCommandEvent& event )  override;
	void OnMenuNueva( wxCommandEvent& event )  override;
	void OnMenuGuardar( wxCommandEvent& event )  override;
	void OnMenuCargar( wxCommandEvent& event )  override;
	void OnMenuAyuda( wxCommandEvent& event )  override;
	
	// TOOLBAR
	void OnClickCombate( wxCommandEvent& event )  override;
	void OnClickDado( wxCommandEvent& event )  override;
	
	// BOTONES DE PERSONAJE
	void OnClickCrearP( wxCommandEvent& event )  override;
	void OnClickImportarP( wxCommandEvent& event )  override;
	void OnClickBorrarPersonaje( wxCommandEvent& event )  override;
	void OnClickVerInventario( wxCommandEvent& event )  override;
	
	// LISTA DE PERSONAJES
	void OnDobleClickListaPersonaje( wxCommandEvent& event )  override;
	void OnApretarTeclaPList( wxKeyEvent& event )  override;
	
	// BOTONES DE ITEM
	void OnClickCrearI( wxCommandEvent& event )  override;
	void OnClickImportarI( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	
	// LISTA DE ITEMS
	void OnDobleClickListaItem( wxCommandEvent& event )  override;
	void OnApretarTeclaIList( wxKeyEvent& event )  override;
	
	// EVENTO DE ACTUALIZACIÓN
	void OnActivarPartida( wxActivateEvent& event )  override;
	
	
public:
	vPartida(wxWindow *parent, Partida *p);
	~vPartida();
};

#endif

