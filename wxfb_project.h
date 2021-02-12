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
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/statline.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_principal
///////////////////////////////////////////////////////////////////////////////
class Ventana_principal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText63;
		wxButton* m_Empezarpartida;
		wxButton* m_Cargarpartida;
		wxButton* m_Salir;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickEmpezar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCargar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_principal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 335,234 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_principal();

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
		wxListBox* m_listBox1;
		wxButton* m_CrearP;
		wxButton* m_button8;
		wxButton* m_button18;
		wxButton* m_button19;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText6;
		wxListBox* m_listBox2;
		wxButton* m_CrearI;
		wxButton* m_button72;
		wxButton* m_button20;

		// Virtual event handlers, overide them in your derived class
		virtual void OnMenuNueva( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCombate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDado( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCrearP( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCrearI( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_partida( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: -Nombre de partida-"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 586,604 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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
		wxTextCtrl* m_textCtrl4;
		wxStaticText* m_Nivel;
		wxSpinCtrl* m_spinCtrl1;
		wxStaticText* m_Nivel1;
		wxSpinCtrlDouble* m_spinCtrlDouble17;
		wxStaticLine* m_staticline41;
		wxStaticText* m_staticText94;
		wxStaticText* m_staticText93;
		wxStaticText* m_staticText8;
		wxSpinCtrlDouble* m_spinCtrlDouble1;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText81;
		wxSpinCtrlDouble* m_spinCtrlDouble11;
		wxStaticText* m_staticText98;
		wxStaticText* m_staticText82;
		wxSpinCtrlDouble* m_spinCtrlDouble12;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText83;
		wxSpinCtrlDouble* m_spinCtrlDouble13;
		wxStaticText* m_staticText92;
		wxStaticText* m_staticText84;
		wxSpinCtrlDouble* m_spinCtrlDouble14;
		wxStaticText* m_staticText99;
		wxStaticText* m_staticText85;
		wxSpinCtrlDouble* m_spinCtrlDouble15;
		wxStaticText* m_staticText910;
		wxStaticText* m_staticText86;
		wxSpinCtrlDouble* m_spinCtrlDouble16;
		wxStaticText* m_staticText911;
		wxStaticText* m_staticText87;
		wxStaticText* m_staticText97;
		wxStaticText* m_staticText871;
		wxStaticText* m_staticText971;
		wxStaticText* m_staticText8721;
		wxStaticText* m_staticText9721;
		wxStaticText* m_staticText872;
		wxStaticText* m_staticText972;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText43;
		wxTextCtrl* m_textCtrl2;
		wxStaticLine* m_staticline411;
		wxButton* m_button7;
		wxButton* m_button4;
		wxStaticText* m_staticText32;
		wxCheckListBox* m_checkList1;
		wxButton* m_button6;
		wxStaticLine* m_staticline4111;

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
		wxTextCtrl* m_textCtrl7;
		wxButton* m_button7;
		wxButton* m_button4;
		wxStaticText* m_Nivel;
		wxSpinCtrl* m_spinCtrl1;
		wxStaticText* m_staticText94;
		wxStaticText* m_staticText87;
		wxSpinCtrlDouble* m_spinCtrlDouble161;
		wxStaticText* m_staticText871;
		wxSpinCtrlDouble* m_spinCtrlDouble162;
		wxStaticText* m_staticText8721;
		wxSpinCtrlDouble* m_spinCtrlDouble163;
		wxStaticText* m_staticText872;
		wxSpinCtrlDouble* m_spinCtrlDouble164;
		wxStaticText* m_staticText81;
		wxSpinCtrlDouble* m_spinCtrlDouble11;
		wxStaticText* m_staticText84;
		wxSpinCtrlDouble* m_spinCtrlDouble14;
		wxStaticLine* m_staticline19;
		wxStaticText* m_staticText8;
		wxSpinCtrlDouble* m_spinCtrlDouble1;
		wxStaticText* m_staticText82;
		wxSpinCtrlDouble* m_spinCtrlDouble12;
		wxStaticText* m_staticText83;
		wxSpinCtrlDouble* m_spinCtrlDouble13;
		wxStaticText* m_staticText85;
		wxSpinCtrlDouble* m_spinCtrlDouble15;
		wxStaticText* m_staticText86;
		wxSpinCtrlDouble* m_spinCtrlDouble16;
		wxStaticText* m_staticText43;
		wxTextCtrl* m_textCtrl2;
		wxStaticText* m_staticText431;
		wxTextCtrl* m_textCtrl21;

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
		virtual void OnClickSeleccionado( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickArrojar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBorrar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCerrar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_dados( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Dados virtuales"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 503,321 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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

