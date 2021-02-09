///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Ventana_principal::Ventana_principal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer3->Add( m_staticText2, 1, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Bienvenido al administrador de RPG de mesa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Empezar partida"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer5, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Cargar partida"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer7, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );
}

Ventana_principal::~Ventana_principal()
{
}

Ventana_partida::Ventana_partida( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	m_menu2 = new wxMenu();
	wxMenuItem* m_menu2Item = new wxMenuItem( m_menu1, wxID_ANY, wxT("Partida"), wxEmptyString, wxITEM_NORMAL, m_menu2 );
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Guardar") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Nueva") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem2 );

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Cargar") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem3 );

	m_menu1->Append( m_menu2Item );

	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Ayuda") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem7 );

	m_menubar1->Append( m_menu1, wxT("Opciones") );

	this->SetMenuBar( m_menubar1 );

	m_toolBar4 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_toolBar4->SetBackgroundColour( wxColour( 224, 224, 224 ) );

	m_tool1 = m_toolBar4->AddTool( wxID_ANY, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxT("Simulación de ataque"), wxEmptyString, NULL );

	m_tool2 = m_toolBar4->AddTool( wxID_ANY, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxT("Dado virtual"), wxEmptyString, NULL );

	m_toolBar4->Realize();

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer23->Add( m_staticText7, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Lista de Personajes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer13->Add( m_staticText5, 0, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer11->Add( bSizer13, 0, 0, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_listBox1 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_listBox1->Append( wxT("Personaje 1") );
	m_listBox1->Append( wxT("Personaje 2") );
	m_listBox1->Append( wxT("Personaje 3") );
	m_listBox1->Append( wxT("Personaje 4") );
	m_listBox1->Append( wxT("Personaje 5") );
	m_listBox1->Append( wxT("Personaje 6") );
	m_listBox1->Append( wxT("Personaje 7") );
	m_listBox1->Append( wxT("Personaje 8") );
	m_listBox1->Append( wxT("Personaje 9") );
	m_listBox1->Append( wxT("Personaje 10") );
	m_listBox1->Append( wxT("Personaje 11") );
	m_listBox1->Append( wxT("Personaje 12") );
	m_listBox1->Append( wxT("Personaje 1") );
	m_listBox1->Append( wxT("Personaje 2") );
	m_listBox1->Append( wxT("Personaje 3") );
	m_listBox1->Append( wxT("Personaje 4") );
	m_listBox1->Append( wxT("Personaje 5") );
	m_listBox1->Append( wxT("Personaje 6") );
	m_listBox1->Append( wxT("Personaje 7") );
	m_listBox1->Append( wxT("Personaje 8") );
	m_listBox1->Append( wxT("Personaje 9") );
	m_listBox1->Append( wxT("Personaje 10") );
	m_listBox1->Append( wxT("Personaje 11") );
	m_listBox1->Append( wxT("Personaje 12") );
	bSizer14->Add( m_listBox1, 1, wxEXPAND|wxALL, 5 );


	bSizer11->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Lista de Items"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer15->Add( m_staticText6, 0, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer11->Add( bSizer15, 0, 0, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_listBox2 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_listBox2->Append( wxT("Item 1") );
	m_listBox2->Append( wxT("Item 2") );
	m_listBox2->Append( wxT("Item 3") );
	m_listBox2->Append( wxT("Item 4") );
	m_listBox2->Append( wxT("Item 5") );
	m_listBox2->Append( wxT("Item 6") );
	m_listBox2->Append( wxT("Item 7") );
	m_listBox2->Append( wxT("Item 8") );
	m_listBox2->Append( wxT("Item 1") );
	m_listBox2->Append( wxT("Item 2") );
	m_listBox2->Append( wxT("Item 3") );
	m_listBox2->Append( wxT("Item 4") );
	m_listBox2->Append( wxT("Item 5") );
	m_listBox2->Append( wxT("Item 6") );
	m_listBox2->Append( wxT("Item 7") );
	m_listBox2->Append( wxT("Item 8") );
	bSizer16->Add( m_listBox2, 1, wxALL|wxEXPAND, 5 );


	bSizer11->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer22->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Crear nuevo personaje"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button7, 0, wxALL, 5 );

	m_button8 = new wxButton( this, wxID_ANY, wxT("Importar personaje existente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button8, 0, wxALL, 5 );

	m_button71 = new wxButton( this, wxID_ANY, wxT("Crear nuevo item"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button71, 0, wxALL, 5 );

	m_button72 = new wxButton( this, wxID_ANY, wxT("Importar item existente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button72, 0, wxALL, 5 );


	bSizer22->Add( bSizer12, 1, wxEXPAND, 5 );


	bSizer23->Add( bSizer22, 1, wxEXPAND, 5 );


	bSizer10->Add( bSizer23, 0, 0, 5 );


	this->SetSizer( bSizer10 );
	this->Layout();

	this->Centre( wxBOTH );
}

Ventana_partida::~Ventana_partida()
{
}

Ventana_personaje::Ventana_personaje( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_Personajename = new wxStaticText( this, wxID_ANY, wxT("Personaje:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Personajename->Wrap( -1 );
	bSizer10->Add( m_Personajename, 0, wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer10->Add( m_staticText3, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );


	bSizer8->Add( bSizer10, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_Nivel = new wxStaticText( this, wxID_ANY, wxT("Nivel:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Nivel->Wrap( -1 );
	bSizer12->Add( m_Nivel, 0, wxALL, 5 );

	m_spinCtrl1 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 10, 1 );
	bSizer12->Add( m_spinCtrl1, 0, wxALL, 5 );


	bSizer8->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer488;
	bSizer488 = new wxBoxSizer( wxVERTICAL );

	m_staticText94 = new wxStaticText( this, wxID_ANY, wxT("         Estadísticas base"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	bSizer488->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer488, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer487;
	bSizer487 = new wxBoxSizer( wxVERTICAL );

	m_staticText93 = new wxStaticText( this, wxID_ANY, wxT("    Total"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	bSizer487->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer487, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer13, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("PV  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer36->Add( m_staticText8, 1, wxALL, 5 );


	bSizer14->Add( bSizer36, 0, wxEXPAND|wxRIGHT, 5 );

	m_spinCtrlDouble1 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_spinCtrlDouble1->SetDigits( 0 );
	bSizer14->Add( m_spinCtrlDouble1, 0, wxALL, 5 );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("38"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer48->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer48, 1, 0, 5 );


	bSizer8->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("DFN  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer35->Add( m_staticText81, 1, wxTOP|wxBOTTOM|wxLEFT, 5 );


	bSizer141->Add( bSizer35, 0, wxEXPAND, 5 );

	m_spinCtrlDouble11 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_spinCtrlDouble11->SetDigits( 0 );
	bSizer141->Add( m_spinCtrlDouble11, 0, wxALL, 5 );

	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer( wxVERTICAL );

	m_staticText98 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText98->Wrap( -1 );
	bSizer481->Add( m_staticText98, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer141->Add( bSizer481, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer141, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText82 = new wxStaticText( this, wxID_ANY, wxT("FRZ  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	bSizer37->Add( m_staticText82, 0, wxALL, 5 );


	bSizer142->Add( bSizer37, 0, wxEXPAND, 5 );

	m_spinCtrlDouble12 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_spinCtrlDouble12->SetDigits( 0 );
	bSizer142->Add( m_spinCtrlDouble12, 0, wxALL, 5 );

	wxBoxSizer* bSizer482;
	bSizer482 = new wxBoxSizer( wxVERTICAL );

	m_staticText91 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	bSizer482->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer142->Add( bSizer482, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer142, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText83 = new wxStaticText( this, wxID_ANY, wxT("AGL  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer27->Add( m_staticText83, 0, wxALL, 5 );


	bSizer143->Add( bSizer27, 0, wxEXPAND, 5 );

	m_spinCtrlDouble13 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 2.000000, 1 );
	m_spinCtrlDouble13->SetDigits( 0 );
	bSizer143->Add( m_spinCtrlDouble13, 0, wxALL, 5 );

	wxBoxSizer* bSizer483;
	bSizer483 = new wxBoxSizer( wxVERTICAL );

	m_staticText92 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer483->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer143->Add( bSizer483, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer143, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText84 = new wxStaticText( this, wxID_ANY, wxT("RM   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer28->Add( m_staticText84, 0, wxALL, 5 );


	bSizer144->Add( bSizer28, 0, wxEXPAND, 5 );

	m_spinCtrlDouble14 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_spinCtrlDouble14->SetDigits( 0 );
	bSizer144->Add( m_spinCtrlDouble14, 0, wxALL, 5 );

	wxBoxSizer* bSizer484;
	bSizer484 = new wxBoxSizer( wxVERTICAL );

	m_staticText99 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	bSizer484->Add( m_staticText99, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer144->Add( bSizer484, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer144, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( this, wxID_ANY, wxT("INT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer29->Add( m_staticText85, 0, wxALL, 5 );


	bSizer145->Add( bSizer29, 0, wxEXPAND, 5 );

	m_spinCtrlDouble15 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_spinCtrlDouble15->SetDigits( 0 );
	bSizer145->Add( m_spinCtrlDouble15, 0, wxALL, 5 );

	wxBoxSizer* bSizer485;
	bSizer485 = new wxBoxSizer( wxVERTICAL );

	m_staticText910 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText910->Wrap( -1 );
	bSizer485->Add( m_staticText910, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer145->Add( bSizer485, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer145, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText86 = new wxStaticText( this, wxID_ANY, wxT("MN   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer30->Add( m_staticText86, 0, wxALL, 5 );


	bSizer146->Add( bSizer30, 0, wxEXPAND, 5 );

	m_spinCtrlDouble16 = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_spinCtrlDouble16->SetDigits( 0 );
	bSizer146->Add( m_spinCtrlDouble16, 0, wxALL, 5 );

	wxBoxSizer* bSizer486;
	bSizer486 = new wxBoxSizer( wxVERTICAL );

	m_staticText911 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText911->Wrap( -1 );
	bSizer486->Add( m_staticText911, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer146->Add( bSizer486, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer146, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText87 = new wxStaticText( this, wxID_ANY, wxT("DÑ     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	bSizer31->Add( m_staticText87, 0, wxALL, 5 );


	bSizer147->Add( bSizer31, 0, wxEXPAND, 5 );

	m_staticText97 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText97->Wrap( -1 );
	bSizer147->Add( m_staticText97, 0, wxALL, 5 );


	bSizer8->Add( bSizer147, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1471;
	bSizer1471 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText871 = new wxStaticText( this, wxID_ANY, wxT("RNG   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText871->Wrap( -1 );
	bSizer32->Add( m_staticText871, 0, wxALL, 5 );


	bSizer1471->Add( bSizer32, 0, wxEXPAND, 5 );

	m_staticText971 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText971->Wrap( -1 );
	bSizer1471->Add( m_staticText971, 0, wxALL, 5 );


	bSizer8->Add( bSizer1471, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14721;
	bSizer14721 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8721 = new wxStaticText( this, wxID_ANY, wxT("PNT    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8721->Wrap( -1 );
	bSizer331->Add( m_staticText8721, 0, wxALL, 5 );


	bSizer14721->Add( bSizer331, 0, wxEXPAND, 5 );

	m_staticText9721 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9721->Wrap( -1 );
	bSizer14721->Add( m_staticText9721, 0, wxALL, 5 );


	bSizer8->Add( bSizer14721, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1472;
	bSizer1472 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText872 = new wxStaticText( this, wxID_ANY, wxT("BLQ    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText872->Wrap( -1 );
	bSizer33->Add( m_staticText872, 0, wxALL, 5 );


	bSizer1472->Add( bSizer33, 0, wxEXPAND, 5 );

	m_staticText972 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText972->Wrap( -1 );
	bSizer1472->Add( m_staticText972, 0, wxALL, 5 );


	bSizer8->Add( bSizer1472, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Detalle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer341->Add( m_staticText43, 0, wxALL, 5 );


	bSizer8->Add( bSizer341, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	bSizer34->Add( m_textCtrl2, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Aplicar cambios"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button7, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Exportar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer11->Add( m_button4, 0, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer11, 0, wxALIGN_RIGHT, 5 );


	bSizer9->Add( 0, 200, 0, 0, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Inventario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer9->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	wxString m_checkList1Choices[] = { wxT("Pala"), wxT("Pico"), wxT("Espada del rey demonio") };
	int m_checkList1NChoices = sizeof( m_checkList1Choices ) / sizeof( wxString );
	m_checkList1 = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_checkList1NChoices, m_checkList1Choices, wxLB_SORT );
	bSizer41->Add( m_checkList1, 1, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer41, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button6, 0, wxALL, 5 );


	bSizer9->Add( bSizer40, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );
}

Ventana_personaje::~Ventana_personaje()
{
}

Ventana_item::Ventana_item( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );


	this->Centre( wxBOTH );
}

Ventana_item::~Ventana_item()
{
}
