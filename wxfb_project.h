///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/statline.h>
#include <wx/listbox.h>
#include <wx/frame.h>
#include <wx/spinctrl.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_principal
///////////////////////////////////////////////////////////////////////////////
class Ventana_principal : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText63;
		wxButton* m_Empezarpartida;
		wxButton* m_Cargarpartida;
		wxButton* m_Salir;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickEmpezar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCargar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_principal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 293,246 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Ventana_principal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Dialogo_NombrePartida
///////////////////////////////////////////////////////////////////////////////
class Dialogo_NombrePartida : public wxDialog
{
	private:

	protected:
		wxStaticText* m_TextoNombrePartida;
		wxTextCtrl* m_textCtrlNombrePart;
		wxButton* m_AceptarNombrePart;
		wxButton* m_CancelarNombrePart;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Dialogo_NombrePartida( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Nombre de partida"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 249,157 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Dialogo_NombrePartida();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_partida
///////////////////////////////////////////////////////////////////////////////
class Ventana_partida : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu2;
		wxToolBar* m_toolBar4;
		wxToolBarToolBase* m_Combate;
		wxToolBarToolBase* m_Dado;
		wxStaticLine* m_staticline41;
		wxStaticText* m_staticText5;
		wxListBox* m_ListaPersonajes;
		wxButton* m_CrearP;
		wxButton* m_button8;
		wxButton* m_button18;
		wxButton* m_button19;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText6;
		wxListBox* m_ListaItems;
		wxButton* m_CrearI;
		wxButton* m_button72;
		wxButton* m_button20;

		// Virtual event handlers, overide them in your derived class
		virtual void OnFocusPartida( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnMenuNueva( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCombate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDado( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCrearP( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCrearI( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_partida( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 586,604 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_partida();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_personaje
///////////////////////////////////////////////////////////////////////////////
class Ventana_personaje : public wxFrame
{
	private:

	protected:
		wxStaticLine* m_staticline4112;
		wxStaticText* m_Personajename;
		wxTextCtrl* m_Nombre;
		wxStaticText* m_asda;
		wxSpinCtrl* m_Nivel;
		wxStaticText* m_sdad;
		wxSpinCtrlDouble* m_EXP;
		wxStaticLine* m_staticline41;
		wxStaticText* m_staticText94;
		wxStaticText* m_staticText93;
		wxStaticText* m_staticText8;
		wxSpinCtrlDouble* m_PVb;
		wxStaticText* m_PVt;
		wxStaticText* m_staticText81;
		wxSpinCtrlDouble* m_DFNb;
		wxStaticText* m_DFNt;
		wxStaticText* m_staticText82;
		wxSpinCtrlDouble* m_FRZb;
		wxStaticText* m_FRZt;
		wxStaticText* m_staticText83;
		wxSpinCtrlDouble* m_AGLb;
		wxStaticText* m_AGLt;
		wxStaticText* m_staticText84;
		wxSpinCtrlDouble* m_RMb;
		wxStaticText* m_RMt;
		wxStaticText* m_staticText85;
		wxSpinCtrlDouble* m_INTb;
		wxStaticText* m_INTt;
		wxStaticText* m_staticText86;
		wxSpinCtrlDouble* m_MNb;
		wxStaticText* m_MNt;
		wxStaticText* m_staticText87;
		wxStaticText* m_DN;
		wxStaticText* m_staticText871;
		wxStaticText* m_RNG;
		wxStaticText* m_staticText8721;
		wxStaticText* m_PNT;
		wxStaticText* m_staticText872;
		wxStaticText* m_BLQ;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText43;
		wxTextCtrl* m_Detalle;
		wxStaticLine* m_staticline411;
		wxButton* m_aplicarcambios;
		wxButton* m_button4;
		wxStaticText* m_staticText32;
		wxCheckListBox* m_Inventario;
		wxButton* m_button6;
		wxStaticLine* m_staticline4111;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAplicar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickExportar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_personaje( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Creación/Modificación de Personaje"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 589,705 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_personaje();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_item
///////////////////////////////////////////////////////////////////////////////
class Ventana_item : public wxFrame
{
	private:

	protected:
		wxStaticText* m_Personajename;
		wxTextCtrl* m_NombreItem;
		wxButton* m_button7;
		wxButton* m_button4;
		wxStaticText* m_Nivel;
		wxSpinCtrl* m_Cantidad;
		wxStaticText* m_staticText94;
		wxStaticText* m_staticText87;
		wxSpinCtrlDouble* m_Danio;
		wxStaticText* m_staticText871;
		wxSpinCtrlDouble* m_Rango;
		wxStaticText* m_staticText8721;
		wxSpinCtrlDouble* m_Punteria;
		wxStaticText* m_staticText872;
		wxSpinCtrlDouble* m_Bloqueo;
		wxStaticText* m_staticText81;
		wxSpinCtrlDouble* m_Defenza;
		wxStaticText* m_staticText84;
		wxSpinCtrlDouble* m_ResistenciaMagica;
		wxStaticLine* m_staticline19;
		wxStaticText* m_staticText8;
		wxSpinCtrlDouble* m_PuntosVida;
		wxStaticText* m_staticText82;
		wxSpinCtrlDouble* m_Fuerza;
		wxStaticText* m_staticText83;
		wxSpinCtrlDouble* m_Agilidad;
		wxStaticText* m_staticText85;
		wxSpinCtrlDouble* m_Inteligencia;
		wxStaticText* m_staticText86;
		wxSpinCtrlDouble* m_Mana;
		wxStaticText* m_staticText43;
		wxTextCtrl* m_Detalle;
		wxStaticText* m_staticText431;
		wxTextCtrl* m_Descripcion;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAplicar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickExportar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_item( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Creación/Modificación de item"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 575,575 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_item();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_dados
///////////////////////////////////////////////////////////////////////////////
class Ventana_dados : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText96;
		wxListBox* m_Seleccionado;
		wxStaticText* m_staticText105;
		wxStaticText* m_staticText98;
		wxTextCtrl* m_Nombre;
		wxStaticText* m_staticText981;
		wxSpinCtrl* m_ValMin;
		wxStaticText* m_staticText982;
		wxSpinCtrl* m_ValMax;
		wxButton* m_Agregar;
		wxStaticLine* m_staticline20;
		wxButton* m_button21;
		wxStaticText* m_staticText102;
		wxStaticText* m_Numero;
		wxButton* m_Borrar;
		wxButton* m_Cerrar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickArrojar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBorrar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCerrar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_dados( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Dados virtuales"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 503,384 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_dados();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_combate
///////////////////////////////////////////////////////////////////////////////
class Ventana_combate : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText106;
		wxChoice* m_choice1;
		wxStaticText* m_staticText107;
		wxSpinCtrlDouble* m_Multiplicador;
		wxStaticLine* m_staticline22;
		wxStaticText* m_staticText108;
		wxStaticText* m_staticText109;
		wxChoice* m_Atacante;
		wxBitmapButton* m_bpButton2;
		wxChoice* m_Receptor;
		wxStaticText* m_staticText112;
		wxStaticText* m_staticText113;
		wxCheckBox* m_ModificarPV;
		wxButton* m_Cerrar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAtacar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCerrar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_combate( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Simulación de combate"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,273 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_combate();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Dialogo_ErrorArrojarsinSelec
///////////////////////////////////////////////////////////////////////////////
class Dialogo_ErrorArrojarsinSelec : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText63;
		wxButton* m_button23;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAceptar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Dialogo_ErrorArrojarsinSelec( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Error"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 252,122 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Dialogo_ErrorArrojarsinSelec();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Dialogo_Inventario
///////////////////////////////////////////////////////////////////////////////
class Dialogo_Inventario : public wxDialog
{
	private:

	protected:
		wxListBox* m_ListaItems;
		wxButton* m_Agregar;
		wxButton* m_Cancelar;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Dialogo_Inventario( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Inventario"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,420 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Dialogo_Inventario();

};

