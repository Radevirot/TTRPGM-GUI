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
#include <wx/listbox.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_principal
///////////////////////////////////////////////////////////////////////////////
class Ventana_principal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;

	public:

		Ventana_principal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 335,234 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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
		wxToolBarToolBase* m_tool1;
		wxToolBarToolBase* m_tool2;
		wxStaticText* m_staticText5;
		wxListBox* m_listBox1;
		wxButton* m_button7;
		wxButton* m_button8;
		wxStaticText* m_staticText6;
		wxListBox* m_listBox2;
		wxButton* m_button71;
		wxButton* m_button72;

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
		wxStaticText* m_Personajename;
		wxStaticText* m_staticText3;
		wxStaticText* m_Nivel;
		wxSpinCtrl* m_spinCtrl1;
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
		wxStaticText* m_staticText43;
		wxTextCtrl* m_textCtrl2;
		wxButton* m_button7;
		wxButton* m_button4;
		wxStaticText* m_staticText32;
		wxCheckListBox* m_checkList1;
		wxButton* m_button6;

	public:

		Ventana_personaje( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TTRPGM: Personaje -Nombre de personaje-"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 587,673 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_personaje();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_item
///////////////////////////////////////////////////////////////////////////////
class Ventana_item : public wxFrame
{
	private:

	protected:

	public:

		Ventana_item( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_item();

};

