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
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText5;
		wxListBox* m_listBox1;
		wxStaticText* m_staticText6;
		wxListBox* m_listBox2;
		wxButton* m_button7;
		wxButton* m_button8;
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
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxButton* m_button4;

	public:

		Ventana_personaje( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 590,634 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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

