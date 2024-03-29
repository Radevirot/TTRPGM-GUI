#ifndef VPARTIDA_H
#define VPARTIDA_H
#include "wxfb_project.h"
#include "Partida.h"
#include "vItem.h"
#include <wx/filedlg.h>
#include "vPersonaje.h"
#include "vDados.h"
#include "vCombate.h"
#include "dItem.h"
#include "dPersonaje.h"
#include "dNombrePartida.h"
#include "string_conv.h"
#include <wx/msgdlg.h>


class vPartida : public Ventana_partida {
	
private:
	Partida *m_partida;
	void ActualizarNombre();
	void ActualizarListas();
protected:
	// Por encima de esta l�nea s�lo hay m�todos duplicados
	
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
	
	// BOTONES DE ITEM
	void OnClickCrearI( wxCommandEvent& event )  override;
	void OnClickImportarI( wxCommandEvent& event )  override;
	void OnClickBorrar( wxCommandEvent& event )  override;
	
	// LISTA DE ITEMS
	void OnDobleClickListaItem( wxCommandEvent& event )  override;
	
	// TECLAS
	void OnApretarSupr( wxCommandEvent& event );
	void OnApretarEnter( wxCommandEvent& event );
	
	// EVENTO DE ACTUALIZACI�N
	void OnActivarPartida( wxActivateEvent& event )  override;
	
	
public:
	vPartida(wxWindow *parent, Partida *p);
	~vPartida();
};

#endif

