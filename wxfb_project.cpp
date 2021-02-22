///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Ventana_principal::Ventana_principal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText66 = new wxStaticText( this, wxID_ANY, wxT("¡Bienvenido al administrador\nde RPG de mesa!"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText66->Wrap( -1 );
	bSizer4->Add( m_staticText66, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer2->Add( bSizer4, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_Empezarpartida = new wxButton( this, wxID_ANY, wxT("Empezar partida"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_Empezarpartida, 1, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_Cargarpartida = new wxButton( this, wxID_ANY, wxT("Cargar partida"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_Cargarpartida, 1, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_Salir = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_Salir, 1, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer7, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_Empezarpartida->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_principal::OnClickEmpezar ), NULL, this );
	m_Cargarpartida->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_principal::OnClickCargar ), NULL, this );
	m_Salir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_principal::OnClickSalir ), NULL, this );
}

Ventana_principal::~Ventana_principal()
{
	// Disconnect Events
	m_Empezarpartida->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_principal::OnClickEmpezar ), NULL, this );
	m_Cargarpartida->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_principal::OnClickCargar ), NULL, this );
	m_Salir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_principal::OnClickSalir ), NULL, this );

}

Dialogo_NombrePartida::Dialogo_NombrePartida( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );

	m_TextoNombrePartida = new wxStaticText( this, wxID_ANY, wxT("Ingrese el nombre de la partida"), wxDefaultPosition, wxDefaultSize, 0 );
	m_TextoNombrePartida->Wrap( -1 );
	bSizer132->Add( m_TextoNombrePartida, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer131->Add( bSizer132, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrlNombrePart = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	#ifdef __WXGTK__
	if ( !m_textCtrlNombrePart->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlNombrePart->SetMaxLength( 256 );
	}
	#else
	m_textCtrlNombrePart->SetMaxLength( 256 );
	#endif
	bSizer133->Add( m_textCtrlNombrePart, 1, wxALL, 5 );


	bSizer131->Add( bSizer133, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer134;
	bSizer134 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer135;
	bSizer135 = new wxBoxSizer( wxVERTICAL );

	m_AceptarNombrePart = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer135->Add( m_AceptarNombrePart, 1, wxALL|wxEXPAND, 5 );


	bSizer134->Add( bSizer135, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer136;
	bSizer136 = new wxBoxSizer( wxVERTICAL );

	m_CancelarNombrePart = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer136->Add( m_CancelarNombrePart, 1, wxALL|wxEXPAND, 5 );


	bSizer134->Add( bSizer136, 1, wxEXPAND, 5 );


	bSizer131->Add( bSizer134, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer131 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_textCtrlNombrePart->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Dialogo_NombrePartida::OnTextEnter ), NULL, this );
	m_AceptarNombrePart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_NombrePartida::OnClickAceptar ), NULL, this );
	m_CancelarNombrePart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_NombrePartida::OnClickCancelar ), NULL, this );
}

Dialogo_NombrePartida::~Dialogo_NombrePartida()
{
	// Disconnect Events
	m_textCtrlNombrePart->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Dialogo_NombrePartida::OnTextEnter ), NULL, this );
	m_AceptarNombrePart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_NombrePartida::OnClickAceptar ), NULL, this );
	m_CancelarNombrePart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_NombrePartida::OnClickCancelar ), NULL, this );

}

Ventana_partida::Ventana_partida( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	m_menu2 = new wxMenu();
	wxMenuItem* m_menu2Item = new wxMenuItem( m_menu1, wxID_ANY, wxT("Partida"), wxEmptyString, wxITEM_NORMAL, m_menu2 );
	wxMenuItem* m_EditarNom;
	m_EditarNom = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Editar nombre") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_EditarNom );

	wxMenuItem* m_Guardar;
	m_Guardar = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Guardar") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_Guardar );

	wxMenuItem* m_Nueva;
	m_Nueva = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Nueva") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_Nueva );

	wxMenuItem* m_Cargar;
	m_Cargar = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Cargar") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_Cargar );

	m_menu1->Append( m_menu2Item );

	wxMenuItem* m_Ayuda;
	m_Ayuda = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Ayuda") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_Ayuda );

	m_menubar1->Append( m_menu1, wxT("Opciones") );

	this->SetMenuBar( m_menubar1 );

	m_toolBar4 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_toolBar4->SetBackgroundColour( wxColour( 224, 224, 224 ) );

	m_Combate = m_toolBar4->AddTool( wxID_ANY, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxT("Simulación de ataque"), wxEmptyString, NULL );

	m_Dado = m_toolBar4->AddTool( wxID_ANY, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxT("Dado virtual"), wxEmptyString, NULL );

	m_toolBar4->Realize();

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1641;
	bSizer1641 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline41 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline41->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer1641->Add( m_staticline41, 1, wxRIGHT|wxLEFT, 5 );


	bSizer11->Add( bSizer1641, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Lista de Personajes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_staticText5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer13->Add( m_staticText5, 0, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer11->Add( bSizer13, 0, 0, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_ListaPersonajes = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer14->Add( m_ListaPersonajes, 1, wxEXPAND|wxALL, 5 );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );

	m_CrearP = new wxButton( this, wxID_ANY, wxT("Crear nuevo personaje"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CrearP->SetToolTip( wxT("Abre una ventana nueva de personaje") );

	bSizer58->Add( m_CrearP, 0, wxALL|wxEXPAND, 5 );

	m_ImportarP = new wxButton( this, wxID_ANY, wxT("Importar personaje existente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_ImportarP, 0, wxALL|wxEXPAND, 5 );

	m_BorrarP = new wxButton( this, wxID_ANY, wxT("Borrar personaje"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_BorrarP, 0, wxALL|wxEXPAND, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Ver inventario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_button19, 0, wxALL|wxEXPAND, 5 );


	bSizer14->Add( bSizer58, 1, 0, 5 );


	bSizer11->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164->Add( m_staticline4, 1, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer11->Add( bSizer164, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Lista de Items"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_staticText6->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer15->Add( m_staticText6, 0, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer11->Add( bSizer15, 0, 0, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_ListaItems = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer16->Add( m_ListaItems, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	m_CrearI = new wxButton( this, wxID_ANY, wxT("Crear nuevo item"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CrearI->SetToolTip( wxT("Abre una ventana nueva de item") );

	bSizer59->Add( m_CrearI, 0, wxALL|wxEXPAND, 5 );

	m_ImportarI = new wxButton( this, wxID_ANY, wxT("Importar item existente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_ImportarI, 0, wxALL|wxEXPAND, 5 );

	m_BorrarI = new wxButton( this, wxID_ANY, wxT("Borrar item"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_BorrarI, 0, wxALL|wxEXPAND, 5 );


	bSizer16->Add( bSizer59, 1, wxEXPAND, 5 );


	bSizer11->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer22->Add( bSizer11, 1, wxEXPAND, 5 );


	bSizer23->Add( bSizer22, 1, wxEXPAND, 5 );


	bSizer10->Add( bSizer23, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer10 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( Ventana_partida::OnActivarPartida ) );
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Ventana_partida::OnMenuEditar ), this, m_EditarNom->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Ventana_partida::OnMenuGuardar ), this, m_Guardar->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Ventana_partida::OnMenuNueva ), this, m_Nueva->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Ventana_partida::OnMenuCargar ), this, m_Cargar->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Ventana_partida::OnMenuAyuda ), this, m_Ayuda->GetId());
	this->Connect( m_Combate->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickCombate ) );
	this->Connect( m_Dado->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickDado ) );
	m_ListaPersonajes->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( Ventana_partida::OnApretarTeclaPList ), NULL, this );
	m_ListaPersonajes->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( Ventana_partida::OnDobleClickListaPersonaje ), NULL, this );
	m_CrearP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickCrearP ), NULL, this );
	m_ImportarP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickImportarP ), NULL, this );
	m_BorrarP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickBorrarPersonaje ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickVerInventario ), NULL, this );
	m_ListaItems->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( Ventana_partida::OnApretarTeclaIList ), NULL, this );
	m_ListaItems->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( Ventana_partida::OnDobleClickListaItem ), NULL, this );
	m_CrearI->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickCrearI ), NULL, this );
	m_ImportarI->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickImportarI ), NULL, this );
	m_BorrarI->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickBorrar ), NULL, this );
}

Ventana_partida::~Ventana_partida()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( Ventana_partida::OnActivarPartida ) );
	this->Disconnect( m_Combate->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickCombate ) );
	this->Disconnect( m_Dado->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickDado ) );
	m_ListaPersonajes->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( Ventana_partida::OnApretarTeclaPList ), NULL, this );
	m_ListaPersonajes->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( Ventana_partida::OnDobleClickListaPersonaje ), NULL, this );
	m_CrearP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickCrearP ), NULL, this );
	m_ImportarP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickImportarP ), NULL, this );
	m_BorrarP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickBorrarPersonaje ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickVerInventario ), NULL, this );
	m_ListaItems->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( Ventana_partida::OnApretarTeclaIList ), NULL, this );
	m_ListaItems->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( Ventana_partida::OnDobleClickListaItem ), NULL, this );
	m_CrearI->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickCrearI ), NULL, this );
	m_ImportarI->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickImportarI ), NULL, this );
	m_BorrarI->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_partida::OnClickBorrar ), NULL, this );

}

Ventana_personaje::Ventana_personaje( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer164112;
	bSizer164112 = new wxBoxSizer( wxVERTICAL );

	m_staticline4112 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline4112->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164112->Add( m_staticline4112, 1, 0, 5 );


	bSizer7->Add( bSizer164112, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_Personajename = new wxStaticText( this, wxID_ANY, wxT("Personaje:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Personajename->Wrap( -1 );
	bSizer10->Add( m_Personajename, 0, wxALL, 5 );

	m_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_Nombre->HasFlag( wxTE_MULTILINE ) )
	{
	m_Nombre->SetMaxLength( 256 );
	}
	#else
	m_Nombre->SetMaxLength( 256 );
	#endif
	bSizer10->Add( m_Nombre, 1, wxALL, 5 );


	bSizer8->Add( bSizer10, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_asda = new wxStaticText( this, wxID_ANY, wxT("Nivel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_asda->Wrap( -1 );
	bSizer12->Add( m_asda, 0, wxALL, 5 );

	m_Nivel = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1000000, 0 );
	bSizer12->Add( m_Nivel, 0, wxALL, 5 );


	bSizer8->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );

	m_sdad = new wxStaticText( this, wxID_ANY, wxT("EXP  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_sdad->Wrap( -1 );
	bSizer121->Add( m_sdad, 0, wxALL, 5 );

	m_EXP = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_EXP->SetDigits( 0 );
	bSizer121->Add( m_EXP, 0, wxALL, 5 );


	bSizer8->Add( bSizer121, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1641;
	bSizer1641 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline41 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline41->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer1641->Add( m_staticline41, 1, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer1641, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer488;
	bSizer488 = new wxBoxSizer( wxVERTICAL );

	m_staticText94 = new wxStaticText( this, wxID_ANY, wxT("       Estadísticas base"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	m_staticText94->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_staticText94->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer488->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer488, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer487;
	bSizer487 = new wxBoxSizer( wxVERTICAL );

	m_staticText93 = new wxStaticText( this, wxID_ANY, wxT("Total "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	m_staticText93->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer487->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer487, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer13, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("PV  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer36->Add( m_staticText8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14->Add( bSizer36, 0, wxEXPAND|wxRIGHT, 5 );

	m_PVb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_PVb->SetDigits( 0 );
	bSizer14->Add( m_PVb, 0, wxALL, 5 );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	m_PVt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PVt->Wrap( -1 );
	bSizer48->Add( m_PVt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer48, 1, 0, 5 );


	bSizer8->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("DFN  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer35->Add( m_staticText81, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer141->Add( bSizer35, 0, wxEXPAND, 5 );

	m_DFNb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_DFNb->SetDigits( 0 );
	bSizer141->Add( m_DFNb, 0, wxALL, 5 );

	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer( wxVERTICAL );

	m_DFNt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DFNt->Wrap( -1 );
	bSizer481->Add( m_DFNt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer141->Add( bSizer481, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer141, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText82 = new wxStaticText( this, wxID_ANY, wxT("FRZ  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	bSizer37->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer142->Add( bSizer37, 0, wxEXPAND, 5 );

	m_FRZb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_FRZb->SetDigits( 0 );
	bSizer142->Add( m_FRZb, 0, wxALL, 5 );

	wxBoxSizer* bSizer482;
	bSizer482 = new wxBoxSizer( wxVERTICAL );

	m_FRZt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_FRZt->Wrap( -1 );
	bSizer482->Add( m_FRZt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer142->Add( bSizer482, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer142, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText83 = new wxStaticText( this, wxID_ANY, wxT("AGL  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer27->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer143->Add( bSizer27, 0, wxEXPAND, 5 );

	m_AGLb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_AGLb->SetDigits( 0 );
	bSizer143->Add( m_AGLb, 0, wxALL, 5 );

	wxBoxSizer* bSizer483;
	bSizer483 = new wxBoxSizer( wxVERTICAL );

	m_AGLt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AGLt->Wrap( -1 );
	bSizer483->Add( m_AGLt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer143->Add( bSizer483, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer143, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText84 = new wxStaticText( this, wxID_ANY, wxT("RM   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer28->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer144->Add( bSizer28, 0, wxEXPAND, 5 );

	m_RMb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_RMb->SetDigits( 0 );
	bSizer144->Add( m_RMb, 0, wxALL, 5 );

	wxBoxSizer* bSizer484;
	bSizer484 = new wxBoxSizer( wxVERTICAL );

	m_RMt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_RMt->Wrap( -1 );
	bSizer484->Add( m_RMt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer144->Add( bSizer484, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer144, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( this, wxID_ANY, wxT("INT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer29->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer145->Add( bSizer29, 0, wxEXPAND, 5 );

	m_INTb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_INTb->SetDigits( 0 );
	bSizer145->Add( m_INTb, 0, wxALL, 5 );

	wxBoxSizer* bSizer485;
	bSizer485 = new wxBoxSizer( wxVERTICAL );

	m_INTt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_INTt->Wrap( -1 );
	bSizer485->Add( m_INTt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer145->Add( bSizer485, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer145, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText86 = new wxStaticText( this, wxID_ANY, wxT("MN   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer30->Add( m_staticText86, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer146->Add( bSizer30, 0, wxEXPAND, 5 );

	m_MNb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_MNb->SetDigits( 0 );
	bSizer146->Add( m_MNb, 0, wxALL, 5 );

	wxBoxSizer* bSizer486;
	bSizer486 = new wxBoxSizer( wxVERTICAL );

	m_MNt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MNt->Wrap( -1 );
	bSizer486->Add( m_MNt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer146->Add( bSizer486, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer146, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText87 = new wxStaticText( this, wxID_ANY, wxT("DÑ     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	bSizer31->Add( m_staticText87, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer147->Add( bSizer31, 0, wxEXPAND, 5 );

	m_DN = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DN->Wrap( -1 );
	bSizer147->Add( m_DN, 0, wxALL, 5 );


	bSizer8->Add( bSizer147, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1471;
	bSizer1471 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText871 = new wxStaticText( this, wxID_ANY, wxT("RNG   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText871->Wrap( -1 );
	bSizer32->Add( m_staticText871, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1471->Add( bSizer32, 0, wxEXPAND, 5 );

	m_RNG = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_RNG->Wrap( -1 );
	bSizer1471->Add( m_RNG, 0, wxALL, 5 );


	bSizer8->Add( bSizer1471, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14721;
	bSizer14721 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8721 = new wxStaticText( this, wxID_ANY, wxT("PNT    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8721->Wrap( -1 );
	bSizer331->Add( m_staticText8721, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14721->Add( bSizer331, 0, wxEXPAND, 5 );

	m_PNT = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PNT->Wrap( -1 );
	bSizer14721->Add( m_PNT, 0, wxALL, 5 );


	bSizer8->Add( bSizer14721, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1472;
	bSizer1472 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText872 = new wxStaticText( this, wxID_ANY, wxT("BLQ    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText872->Wrap( -1 );
	bSizer33->Add( m_staticText872, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1472->Add( bSizer33, 0, wxEXPAND, 5 );

	m_BLQ = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BLQ->Wrap( -1 );
	bSizer1472->Add( m_BLQ, 0, wxALL, 5 );


	bSizer8->Add( bSizer1472, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164->Add( m_staticline4, 1, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer164, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Detalle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	m_staticText43->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer341->Add( m_staticText43, 0, wxALL, 5 );


	bSizer8->Add( bSizer341, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_Detalle = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_Detalle->HasFlag( wxTE_MULTILINE ) )
	{
	m_Detalle->SetMaxLength( 1000 );
	}
	#else
	m_Detalle->SetMaxLength( 1000 );
	#endif
	bSizer34->Add( m_Detalle, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16411;
	bSizer16411 = new wxBoxSizer( wxVERTICAL );

	m_staticline411 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline411->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer16411->Add( m_staticline411, 1, 0, 5 );


	bSizer7->Add( bSizer16411, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_aplicarcambios = new wxButton( this, wxID_ANY, wxT("Crear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_aplicarcambios, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Exportar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer11->Add( m_button4, 0, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer11, 0, wxALIGN_RIGHT, 5 );


	bSizer9->Add( 0, 40, 0, 0, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Inventario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer9->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	wxArrayString m_InventarioChoices;
	m_Inventario = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_InventarioChoices, wxLB_SORT );
	bSizer41->Add( m_Inventario, 1, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer41, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button6, 0, wxALL, 5 );

	m_button34 = new wxButton( this, wxID_ANY, wxT("Borrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button34, 0, wxALL, 5 );


	bSizer9->Add( bSizer40, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer164111;
	bSizer164111 = new wxBoxSizer( wxVERTICAL );

	m_staticline4111 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline4111->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164111->Add( m_staticline4111, 1, 0, 5 );


	bSizer7->Add( bSizer164111, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_aplicarcambios->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickAplicar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickExportar ), NULL, this );
	m_Inventario->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( Ventana_personaje::OnCheckListInventario ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickAgregar ), NULL, this );
	m_button34->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickBorrar ), NULL, this );
}

Ventana_personaje::~Ventana_personaje()
{
	// Disconnect Events
	m_aplicarcambios->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickAplicar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickExportar ), NULL, this );
	m_Inventario->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( Ventana_personaje::OnCheckListInventario ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickAgregar ), NULL, this );
	m_button34->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_personaje::OnClickBorrar ), NULL, this );

}

Ventana_item::Ventana_item( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1461;
	bSizer1461 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1451;
	bSizer1451 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_Personajename = new wxStaticText( this, wxID_ANY, wxT("Item:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Personajename->Wrap( -1 );
	bSizer10->Add( m_Personajename, 0, wxALL, 5 );

	m_NombreItem = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_NombreItem->HasFlag( wxTE_MULTILINE ) )
	{
	m_NombreItem->SetMaxLength( 256 );
	}
	#else
	m_NombreItem->SetMaxLength( 256 );
	#endif
	bSizer10->Add( m_NombreItem, 1, wxALL, 5 );


	bSizer1451->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Crear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button7, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Exportar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer11->Add( m_button4, 0, wxALL, 5 );


	bSizer1451->Add( bSizer11, 0, 0, 5 );


	bSizer1461->Add( bSizer1451, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer1461, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_Nivel = new wxStaticText( this, wxID_ANY, wxT("Cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Nivel->Wrap( -1 );
	bSizer12->Add( m_Nivel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_Cantidad = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 1, 1000, 1 );
	bSizer12->Add( m_Cantidad, 0, wxALL, 5 );


	bSizer158->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer488;
	bSizer488 = new wxBoxSizer( wxVERTICAL );

	m_staticText94 = new wxStaticText( this, wxID_ANY, wxT(" Modificadores de estadísticas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	m_staticText94->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer488->Add( m_staticText94, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer13->Add( bSizer488, 1, wxEXPAND, 5 );


	bSizer158->Add( bSizer13, 0, wxEXPAND, 5 );


	bSizer7->Add( bSizer158, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer157;
	bSizer157 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText87 = new wxStaticText( this, wxID_ANY, wxT("DÑ    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	bSizer31->Add( m_staticText87, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer147->Add( bSizer31, 0, wxEXPAND, 5 );

	m_Danio = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Danio->SetDigits( 0 );
	bSizer147->Add( m_Danio, 0, wxALL, 5 );


	bSizer156->Add( bSizer147, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer1471;
	bSizer1471 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText871 = new wxStaticText( this, wxID_ANY, wxT("RNG  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText871->Wrap( -1 );
	bSizer32->Add( m_staticText871, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1471->Add( bSizer32, 0, wxEXPAND, 5 );

	m_Rango = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Rango->SetDigits( 0 );
	bSizer1471->Add( m_Rango, 0, wxALL, 5 );


	bSizer156->Add( bSizer1471, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer14721;
	bSizer14721 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8721 = new wxStaticText( this, wxID_ANY, wxT("PNT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8721->Wrap( -1 );
	bSizer331->Add( m_staticText8721, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14721->Add( bSizer331, 0, wxEXPAND, 5 );

	m_Punteria = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Punteria->SetDigits( 0 );
	bSizer14721->Add( m_Punteria, 0, wxALL, 5 );


	bSizer156->Add( bSizer14721, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer1472;
	bSizer1472 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText872 = new wxStaticText( this, wxID_ANY, wxT("BLQ   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText872->Wrap( -1 );
	bSizer33->Add( m_staticText872, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1472->Add( bSizer33, 0, wxEXPAND, 5 );

	m_Bloqueo = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Bloqueo->SetDigits( 0 );
	bSizer1472->Add( m_Bloqueo, 0, wxALL, 5 );


	bSizer156->Add( bSizer1472, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("DFN    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer35->Add( m_staticText81, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer141->Add( bSizer35, 0, wxEXPAND, 5 );

	m_Defenza = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Defenza->SetDigits( 0 );
	bSizer141->Add( m_Defenza, 0, wxALL, 5 );


	bSizer156->Add( bSizer141, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText84 = new wxStaticText( this, wxID_ANY, wxT("RM    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer28->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer144->Add( bSizer28, 0, wxEXPAND, 5 );

	m_ResistenciaMagica = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_ResistenciaMagica->SetDigits( 0 );
	bSizer144->Add( m_ResistenciaMagica, 0, wxALL, 5 );


	bSizer156->Add( bSizer144, 1, wxALIGN_RIGHT, 5 );


	bSizer157->Add( bSizer156, 1, 0, 5 );

	wxBoxSizer* bSizer186;
	bSizer186 = new wxBoxSizer( wxVERTICAL );

	m_staticline19 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer186->Add( m_staticline19, 1, wxALL, 5 );


	bSizer157->Add( bSizer186, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("PV   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer36->Add( m_staticText8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14->Add( bSizer36, 0, wxEXPAND|wxRIGHT, 5 );

	m_PuntosVida = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_PuntosVida->SetDigits( 0 );
	bSizer14->Add( m_PuntosVida, 0, wxALL, 5 );


	bSizer8->Add( bSizer14, 1, 0, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText82 = new wxStaticText( this, wxID_ANY, wxT("FRZ  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	bSizer37->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer142->Add( bSizer37, 0, wxEXPAND, 5 );

	m_Fuerza = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Fuerza->SetDigits( 0 );
	bSizer142->Add( m_Fuerza, 0, wxALL, 5 );


	bSizer8->Add( bSizer142, 1, 0, 5 );

	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText83 = new wxStaticText( this, wxID_ANY, wxT("AGL  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer27->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer143->Add( bSizer27, 0, wxEXPAND, 5 );

	m_Agilidad = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Agilidad->SetDigits( 0 );
	bSizer143->Add( m_Agilidad, 0, wxALL, 5 );


	bSizer8->Add( bSizer143, 1, 0, 5 );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( this, wxID_ANY, wxT("INT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer29->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer145->Add( bSizer29, 0, wxEXPAND, 5 );

	m_Inteligencia = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Inteligencia->SetDigits( 0 );
	bSizer145->Add( m_Inteligencia, 0, wxALL, 5 );


	bSizer8->Add( bSizer145, 1, 0, 5 );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText86 = new wxStaticText( this, wxID_ANY, wxT("MN   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer30->Add( m_staticText86, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer146->Add( bSizer30, 0, wxEXPAND, 5 );

	m_Mana = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Mana->SetDigits( 0 );
	bSizer146->Add( m_Mana, 0, wxALL, 5 );


	bSizer8->Add( bSizer146, 1, 0, 5 );


	bSizer157->Add( bSizer8, 1, 0, 5 );


	bSizer7->Add( bSizer157, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1473;
	bSizer1473 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Detalle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	m_staticText43->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer341->Add( m_staticText43, 0, wxALL, 5 );


	bSizer1473->Add( bSizer341, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_Detalle = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_Detalle->HasFlag( wxTE_MULTILINE ) )
	{
	m_Detalle->SetMaxLength( 1000 );
	}
	#else
	m_Detalle->SetMaxLength( 1000 );
	#endif
	bSizer34->Add( m_Detalle, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer1473->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer148->Add( bSizer1473, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3411;
	bSizer3411 = new wxBoxSizer( wxVERTICAL );

	m_staticText431 = new wxStaticText( this, wxID_ANY, wxT("Descripción"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431->Wrap( -1 );
	m_staticText431->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer3411->Add( m_staticText431, 1, wxALIGN_CENTER|wxALL, 5 );


	bSizer149->Add( bSizer3411, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer342;
	bSizer342 = new wxBoxSizer( wxVERTICAL );

	m_Descripcion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_Descripcion->HasFlag( wxTE_MULTILINE ) )
	{
	m_Descripcion->SetMaxLength( 1000 );
	}
	#else
	m_Descripcion->SetMaxLength( 1000 );
	#endif
	bSizer342->Add( m_Descripcion, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer149->Add( bSizer342, 1, wxEXPAND, 5 );


	bSizer148->Add( bSizer149, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer148, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_item::OnClickAplicar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_item::OnClickExportar ), NULL, this );
}

Ventana_item::~Ventana_item()
{
	// Disconnect Events
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_item::OnClickAplicar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_item::OnClickExportar ), NULL, this );

}

Ventana_dados::Ventana_dados( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS") ) );
	this->SetForegroundColour( wxColour( 0, 0, 0 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer197;
	bSizer197 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer187;
	bSizer187 = new wxBoxSizer( wxVERTICAL );

	m_staticText96 = new wxStaticText( this, wxID_ANY, wxT("Lista de dados creados"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	m_staticText96->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer187->Add( m_staticText96, 0, wxALIGN_CENTER|wxALL, 5 );

	m_Seleccionado = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer187->Add( m_Seleccionado, 1, wxALL|wxEXPAND, 5 );


	bSizer197->Add( bSizer187, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer188;
	bSizer188 = new wxBoxSizer( wxVERTICAL );

	m_staticText105 = new wxStaticText( this, wxID_ANY, wxT("Creación de dados"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText105->Wrap( -1 );
	m_staticText105->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer188->Add( m_staticText105, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer189;
	bSizer189 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText98 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText98->Wrap( -1 );
	bSizer189->Add( m_staticText98, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_Nombre->HasFlag( wxTE_MULTILINE ) )
	{
	m_Nombre->SetMaxLength( 16 );
	}
	#else
	m_Nombre->SetMaxLength( 16 );
	#endif
	bSizer189->Add( m_Nombre, 1, wxALL, 5 );


	bSizer188->Add( bSizer189, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1891;
	bSizer1891 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText981 = new wxStaticText( this, wxID_ANY, wxT("Valor mínimo "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText981->Wrap( -1 );
	bSizer1891->Add( m_staticText981, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_ValMin = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 999, 1 );
	bSizer1891->Add( m_ValMin, 0, wxALL, 5 );


	bSizer188->Add( bSizer1891, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1892;
	bSizer1892 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText982 = new wxStaticText( this, wxID_ANY, wxT("Valor máximo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText982->Wrap( -1 );
	bSizer1892->Add( m_staticText982, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_ValMax = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 10000, 20 );
	bSizer1892->Add( m_ValMax, 0, wxALL, 5 );


	bSizer188->Add( bSizer1892, 0, wxEXPAND, 5 );

	m_Agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer188->Add( m_Agregar, 0, wxALL, 5 );

	m_staticline20 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer188->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Arrojar seleccionado"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer188->Add( m_button21, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer195;
	bSizer195 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText102 = new wxStaticText( this, wxID_ANY, wxT("Valor obtenido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	bSizer195->Add( m_staticText102, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_Numero = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Numero->Wrap( -1 );
	m_Numero->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_Numero->SetForegroundColour( wxColour( 128, 0, 0 ) );

	bSizer195->Add( m_Numero, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer188->Add( bSizer195, 0, wxALIGN_CENTER, 5 );


	bSizer197->Add( bSizer188, 1, wxEXPAND, 5 );


	bSizer162->Add( bSizer197, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer198;
	bSizer198 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer199;
	bSizer199 = new wxBoxSizer( wxVERTICAL );

	m_Borrar = new wxButton( this, wxID_ANY, wxT("Borrar seleccionado"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer199->Add( m_Borrar, 0, wxALL|wxEXPAND, 5 );


	bSizer198->Add( bSizer199, 1, 0, 5 );

	wxBoxSizer* bSizer196;
	bSizer196 = new wxBoxSizer( wxVERTICAL );

	m_Cerrar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer196->Add( m_Cerrar, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer198->Add( bSizer196, 1, 0, 5 );


	bSizer162->Add( bSizer198, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer162 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_Agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickAgregar ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickArrojar ), NULL, this );
	m_Borrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickBorrar ), NULL, this );
	m_Cerrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickCerrar ), NULL, this );
}

Ventana_dados::~Ventana_dados()
{
	// Disconnect Events
	m_Agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickAgregar ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickArrojar ), NULL, this );
	m_Borrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickBorrar ), NULL, this );
	m_Cerrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_dados::OnClickCerrar ), NULL, this );

}

Ventana_combate::Ventana_combate( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer200;
	bSizer200 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer201;
	bSizer201 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText106 = new wxStaticText( this, wxID_ANY, wxT("Utilizar la fórmula:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	bSizer201->Add( m_staticText106, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString m_FormulaChoices;
	m_Formula = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_FormulaChoices, 0 );
	m_Formula->SetSelection( 0 );
	bSizer201->Add( m_Formula, 0, wxALL, 5 );


	bSizer200->Add( bSizer201, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer202;
	bSizer202 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText107 = new wxStaticText( this, wxID_ANY, wxT("Con MULT ="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText107->Wrap( -1 );
	bSizer202->Add( m_staticText107, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_Multiplicador = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 1, 1 );
	m_Multiplicador->SetDigits( 0 );
	bSizer202->Add( m_Multiplicador, 0, wxALL, 5 );


	bSizer200->Add( bSizer202, 0, wxEXPAND, 5 );

	m_staticline22 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer200->Add( m_staticline22, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer204;
	bSizer204 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer203;
	bSizer203 = new wxBoxSizer( wxVERTICAL );

	m_staticText108 = new wxStaticText( this, wxID_ANY, wxT("Personaje atacante"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	bSizer203->Add( m_staticText108, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer204->Add( bSizer203, 1, 0, 5 );

	wxBoxSizer* bSizer205;
	bSizer205 = new wxBoxSizer( wxVERTICAL );

	m_staticText109 = new wxStaticText( this, wxID_ANY, wxT("Receptor de daño"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText109->Wrap( -1 );
	bSizer205->Add( m_staticText109, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer204->Add( bSizer205, 1, 0, 5 );


	bSizer200->Add( bSizer204, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer2031;
	bSizer2031 = new wxBoxSizer( wxHORIZONTAL );

	wxArrayString m_AtacanteChoices;
	m_Atacante = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_AtacanteChoices, 0 );
	m_Atacante->SetSelection( 0 );
	bSizer2031->Add( m_Atacante, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bpButton2 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 35,35 ), wxBU_AUTODRAW|0 );
	bSizer2031->Add( m_bpButton2, 0, wxALL, 5 );

	wxArrayString m_ReceptorChoices;
	m_Receptor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_ReceptorChoices, 0 );
	m_Receptor->SetSelection( 0 );
	bSizer2031->Add( m_Receptor, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer200->Add( bSizer2031, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer209;
	bSizer209 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText112 = new wxStaticText( this, wxID_ANY, wxT("Puntos de daño provocados:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112->Wrap( -1 );
	bSizer209->Add( m_staticText112, 0, wxALIGN_CENTER|wxALL, 5 );

	m_DanioProvo = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DanioProvo->Wrap( -1 );
	m_DanioProvo->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer209->Add( m_DanioProvo, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer200->Add( bSizer209, 0, wxALIGN_CENTER, 5 );

	wxBoxSizer* bSizer210;
	bSizer210 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxVERTICAL );

	m_ModificarPV = new wxCheckBox( this, wxID_ANY, wxT("Modificar PV del receptor"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_ModificarPV, 0, wxALL, 5 );


	bSizer210->Add( bSizer211, 1, wxALIGN_BOTTOM, 5 );

	wxBoxSizer* bSizer212;
	bSizer212 = new wxBoxSizer( wxVERTICAL );

	m_Cerrar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer212->Add( m_Cerrar, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer210->Add( bSizer212, 1, wxALIGN_BOTTOM, 5 );


	bSizer200->Add( bSizer210, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer200 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_bpButton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_combate::OnClickAtacar ), NULL, this );
	m_Cerrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_combate::OnClickCerrar ), NULL, this );
}

Ventana_combate::~Ventana_combate()
{
	// Disconnect Events
	m_bpButton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_combate::OnClickAtacar ), NULL, this );
	m_Cerrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_combate::OnClickCerrar ), NULL, this );

}

Dialogo_ErrorArrojarsinSelec::Dialogo_ErrorArrojarsinSelec( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer136;
	bSizer136 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer137;
	bSizer137 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText63 = new wxStaticText( this, wxID_ANY, wxT("No es posible arrojar un dado sin\nhaber seleccionado uno previamente"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText63->Wrap( -1 );
	bSizer137->Add( m_staticText63, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer136->Add( bSizer137, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer138;
	bSizer138 = new wxBoxSizer( wxHORIZONTAL );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer138->Add( m_button23, 0, wxALL, 5 );


	bSizer136->Add( bSizer138, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer136 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_ErrorArrojarsinSelec::OnClickAceptar ), NULL, this );
}

Dialogo_ErrorArrojarsinSelec::~Dialogo_ErrorArrojarsinSelec()
{
	// Disconnect Events
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_ErrorArrojarsinSelec::OnClickAceptar ), NULL, this );

}

Dialogo_Inventario::Dialogo_Inventario( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer139;
	bSizer139 = new wxBoxSizer( wxVERTICAL );

	m_ListaItems = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer139->Add( m_ListaItems, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_Agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer141->Add( m_Agregar, 1, wxALL, 5 );

	m_Cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer141->Add( m_Cancelar, 1, wxALL, 5 );


	bSizer139->Add( bSizer141, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer139 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_ListaItems->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( Dialogo_Inventario::OnListDobleClick ), NULL, this );
	m_Agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Inventario::OnClickAgregar ), NULL, this );
	m_Cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Inventario::OnClickCancelar ), NULL, this );
}

Dialogo_Inventario::~Dialogo_Inventario()
{
	// Disconnect Events
	m_ListaItems->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( Dialogo_Inventario::OnListDobleClick ), NULL, this );
	m_Agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Inventario::OnClickAgregar ), NULL, this );
	m_Cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Inventario::OnClickCancelar ), NULL, this );

}

Dialogo_item::Dialogo_item( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1461;
	bSizer1461 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1451;
	bSizer1451 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_Personajename = new wxStaticText( this, wxID_ANY, wxT("Item:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Personajename->Wrap( -1 );
	bSizer10->Add( m_Personajename, 0, wxALL, 5 );

	m_NombreItem = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_NombreItem->HasFlag( wxTE_MULTILINE ) )
	{
	m_NombreItem->SetMaxLength( 256 );
	}
	#else
	m_NombreItem->SetMaxLength( 256 );
	#endif
	bSizer10->Add( m_NombreItem, 1, wxALL, 5 );


	bSizer1451->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Aplicar cambios"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button7, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Exportar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer11->Add( m_button4, 0, wxALL, 5 );


	bSizer1451->Add( bSizer11, 0, 0, 5 );


	bSizer1461->Add( bSizer1451, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer1461, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_Nivel = new wxStaticText( this, wxID_ANY, wxT("Cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Nivel->Wrap( -1 );
	bSizer12->Add( m_Nivel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_Cantidad = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 1, 1000, 1 );
	bSizer12->Add( m_Cantidad, 0, wxALL, 5 );


	bSizer158->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer488;
	bSizer488 = new wxBoxSizer( wxVERTICAL );

	m_staticText94 = new wxStaticText( this, wxID_ANY, wxT(" Modificadores de estadísticas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	m_staticText94->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer488->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer488, 1, wxEXPAND, 5 );


	bSizer158->Add( bSizer13, 0, wxEXPAND, 5 );


	bSizer7->Add( bSizer158, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer157;
	bSizer157 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText87 = new wxStaticText( this, wxID_ANY, wxT("DÑ    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	bSizer31->Add( m_staticText87, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer147->Add( bSizer31, 0, wxEXPAND, 5 );

	m_Danio = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Danio->SetDigits( 0 );
	bSizer147->Add( m_Danio, 0, wxALL, 5 );


	bSizer156->Add( bSizer147, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer1471;
	bSizer1471 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText871 = new wxStaticText( this, wxID_ANY, wxT("RNG  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText871->Wrap( -1 );
	bSizer32->Add( m_staticText871, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1471->Add( bSizer32, 0, wxEXPAND, 5 );

	m_Rango = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Rango->SetDigits( 0 );
	bSizer1471->Add( m_Rango, 0, wxALL, 5 );


	bSizer156->Add( bSizer1471, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer14721;
	bSizer14721 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8721 = new wxStaticText( this, wxID_ANY, wxT("PNT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8721->Wrap( -1 );
	bSizer331->Add( m_staticText8721, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14721->Add( bSizer331, 0, wxEXPAND, 5 );

	m_Punteria = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Punteria->SetDigits( 0 );
	bSizer14721->Add( m_Punteria, 0, wxALL, 5 );


	bSizer156->Add( bSizer14721, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer1472;
	bSizer1472 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText872 = new wxStaticText( this, wxID_ANY, wxT("BLQ   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText872->Wrap( -1 );
	bSizer33->Add( m_staticText872, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1472->Add( bSizer33, 0, wxEXPAND, 5 );

	m_Bloqueo = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Bloqueo->SetDigits( 0 );
	bSizer1472->Add( m_Bloqueo, 0, wxALL, 5 );


	bSizer156->Add( bSizer1472, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("DFN    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer35->Add( m_staticText81, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer141->Add( bSizer35, 0, wxEXPAND, 5 );

	m_Defenza = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Defenza->SetDigits( 0 );
	bSizer141->Add( m_Defenza, 0, wxALL, 5 );


	bSizer156->Add( bSizer141, 1, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText84 = new wxStaticText( this, wxID_ANY, wxT("RM    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer28->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer144->Add( bSizer28, 0, wxEXPAND, 5 );

	m_ResistenciaMagica = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_ResistenciaMagica->SetDigits( 0 );
	bSizer144->Add( m_ResistenciaMagica, 0, wxALL, 5 );


	bSizer156->Add( bSizer144, 1, wxALIGN_RIGHT, 5 );


	bSizer157->Add( bSizer156, 1, 0, 5 );

	wxBoxSizer* bSizer186;
	bSizer186 = new wxBoxSizer( wxVERTICAL );

	m_staticline19 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer186->Add( m_staticline19, 1, wxALL, 5 );


	bSizer157->Add( bSizer186, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("PV   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer36->Add( m_staticText8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14->Add( bSizer36, 0, wxEXPAND|wxRIGHT, 5 );

	m_PuntosVida = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_PuntosVida->SetDigits( 0 );
	bSizer14->Add( m_PuntosVida, 0, wxALL, 5 );


	bSizer8->Add( bSizer14, 1, 0, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText82 = new wxStaticText( this, wxID_ANY, wxT("FRZ  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	bSizer37->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer142->Add( bSizer37, 0, wxEXPAND, 5 );

	m_Fuerza = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Fuerza->SetDigits( 0 );
	bSizer142->Add( m_Fuerza, 0, wxALL, 5 );


	bSizer8->Add( bSizer142, 1, 0, 5 );

	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText83 = new wxStaticText( this, wxID_ANY, wxT("AGL  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer27->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer143->Add( bSizer27, 0, wxEXPAND, 5 );

	m_Agilidad = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Agilidad->SetDigits( 0 );
	bSizer143->Add( m_Agilidad, 0, wxALL, 5 );


	bSizer8->Add( bSizer143, 1, 0, 5 );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( this, wxID_ANY, wxT("INT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer29->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer145->Add( bSizer29, 0, wxEXPAND, 5 );

	m_Inteligencia = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Inteligencia->SetDigits( 0 );
	bSizer145->Add( m_Inteligencia, 0, wxALL, 5 );


	bSizer8->Add( bSizer145, 1, 0, 5 );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText86 = new wxStaticText( this, wxID_ANY, wxT("MN   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer30->Add( m_staticText86, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer146->Add( bSizer30, 0, wxEXPAND, 5 );

	m_Mana = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_Mana->SetDigits( 0 );
	bSizer146->Add( m_Mana, 0, wxALL, 5 );


	bSizer8->Add( bSizer146, 1, 0, 5 );


	bSizer157->Add( bSizer8, 1, 0, 5 );


	bSizer7->Add( bSizer157, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1473;
	bSizer1473 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Detalle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	m_staticText43->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer341->Add( m_staticText43, 0, wxALL, 5 );


	bSizer1473->Add( bSizer341, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_Detalle = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_Detalle->HasFlag( wxTE_MULTILINE ) )
	{
	m_Detalle->SetMaxLength( 1000 );
	}
	#else
	m_Detalle->SetMaxLength( 1000 );
	#endif
	bSizer34->Add( m_Detalle, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer1473->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer148->Add( bSizer1473, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3411;
	bSizer3411 = new wxBoxSizer( wxVERTICAL );

	m_staticText431 = new wxStaticText( this, wxID_ANY, wxT("Descripción"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431->Wrap( -1 );
	m_staticText431->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer3411->Add( m_staticText431, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer149->Add( bSizer3411, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer342;
	bSizer342 = new wxBoxSizer( wxVERTICAL );

	m_Descripcion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_Descripcion->HasFlag( wxTE_MULTILINE ) )
	{
	m_Descripcion->SetMaxLength( 1000 );
	}
	#else
	m_Descripcion->SetMaxLength( 1000 );
	#endif
	bSizer342->Add( m_Descripcion, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer149->Add( bSizer342, 1, wxEXPAND, 5 );


	bSizer148->Add( bSizer149, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer148, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_item::OnClickAplicar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_item::OnClickExportar ), NULL, this );
}

Dialogo_item::~Dialogo_item()
{
	// Disconnect Events
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_item::OnClickAplicar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_item::OnClickExportar ), NULL, this );

}

Dialogo_Personaje::Dialogo_Personaje( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer164112;
	bSizer164112 = new wxBoxSizer( wxVERTICAL );

	m_staticline4112 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline4112->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164112->Add( m_staticline4112, 1, 0, 5 );


	bSizer7->Add( bSizer164112, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_Personajename = new wxStaticText( this, wxID_ANY, wxT("Personaje:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Personajename->Wrap( -1 );
	bSizer10->Add( m_Personajename, 0, wxALL, 5 );

	m_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_Nombre->HasFlag( wxTE_MULTILINE ) )
	{
	m_Nombre->SetMaxLength( 256 );
	}
	#else
	m_Nombre->SetMaxLength( 256 );
	#endif
	bSizer10->Add( m_Nombre, 1, wxALL, 5 );


	bSizer8->Add( bSizer10, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_asda = new wxStaticText( this, wxID_ANY, wxT("Nivel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_asda->Wrap( -1 );
	bSizer12->Add( m_asda, 0, wxALL, 5 );

	m_Nivel = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1000000, 0 );
	bSizer12->Add( m_Nivel, 0, wxALL, 5 );


	bSizer8->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );

	m_sdad = new wxStaticText( this, wxID_ANY, wxT("EXP  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_sdad->Wrap( -1 );
	bSizer121->Add( m_sdad, 0, wxALL, 5 );

	m_EXP = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_EXP->SetDigits( 0 );
	bSizer121->Add( m_EXP, 0, wxALL, 5 );


	bSizer8->Add( bSizer121, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1641;
	bSizer1641 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline41 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline41->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer1641->Add( m_staticline41, 1, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer1641, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer488;
	bSizer488 = new wxBoxSizer( wxVERTICAL );

	m_staticText94 = new wxStaticText( this, wxID_ANY, wxT("       Estadísticas base"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	m_staticText94->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_staticText94->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer488->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer488, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer487;
	bSizer487 = new wxBoxSizer( wxVERTICAL );

	m_staticText93 = new wxStaticText( this, wxID_ANY, wxT("Total "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	m_staticText93->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer487->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( bSizer487, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer13, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("PV  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer36->Add( m_staticText8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14->Add( bSizer36, 0, wxEXPAND|wxRIGHT, 5 );

	m_PVb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_PVb->SetDigits( 0 );
	bSizer14->Add( m_PVb, 0, wxALL, 5 );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	m_PVt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PVt->Wrap( -1 );
	bSizer48->Add( m_PVt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer48, 1, 0, 5 );


	bSizer8->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("DFN  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer35->Add( m_staticText81, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer141->Add( bSizer35, 0, wxEXPAND, 5 );

	m_DFNb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_DFNb->SetDigits( 0 );
	bSizer141->Add( m_DFNb, 0, wxALL, 5 );

	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer( wxVERTICAL );

	m_DFNt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DFNt->Wrap( -1 );
	bSizer481->Add( m_DFNt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer141->Add( bSizer481, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer141, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText82 = new wxStaticText( this, wxID_ANY, wxT("FRZ  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	bSizer37->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer142->Add( bSizer37, 0, wxEXPAND, 5 );

	m_FRZb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_FRZb->SetDigits( 0 );
	bSizer142->Add( m_FRZb, 0, wxALL, 5 );

	wxBoxSizer* bSizer482;
	bSizer482 = new wxBoxSizer( wxVERTICAL );

	m_FRZt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_FRZt->Wrap( -1 );
	bSizer482->Add( m_FRZt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer142->Add( bSizer482, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer142, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer143;
	bSizer143 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText83 = new wxStaticText( this, wxID_ANY, wxT("AGL  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer27->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer143->Add( bSizer27, 0, wxEXPAND, 5 );

	m_AGLb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_AGLb->SetDigits( 0 );
	bSizer143->Add( m_AGLb, 0, wxALL, 5 );

	wxBoxSizer* bSizer483;
	bSizer483 = new wxBoxSizer( wxVERTICAL );

	m_AGLt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AGLt->Wrap( -1 );
	bSizer483->Add( m_AGLt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer143->Add( bSizer483, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer143, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText84 = new wxStaticText( this, wxID_ANY, wxT("RM   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer28->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer144->Add( bSizer28, 0, wxEXPAND, 5 );

	m_RMb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_RMb->SetDigits( 0 );
	bSizer144->Add( m_RMb, 0, wxALL, 5 );

	wxBoxSizer* bSizer484;
	bSizer484 = new wxBoxSizer( wxVERTICAL );

	m_RMt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_RMt->Wrap( -1 );
	bSizer484->Add( m_RMt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer144->Add( bSizer484, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer144, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText85 = new wxStaticText( this, wxID_ANY, wxT("INT   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer29->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer145->Add( bSizer29, 0, wxEXPAND, 5 );

	m_INTb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_INTb->SetDigits( 0 );
	bSizer145->Add( m_INTb, 0, wxALL, 5 );

	wxBoxSizer* bSizer485;
	bSizer485 = new wxBoxSizer( wxVERTICAL );

	m_INTt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_INTt->Wrap( -1 );
	bSizer485->Add( m_INTt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer145->Add( bSizer485, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer145, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer146;
	bSizer146 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText86 = new wxStaticText( this, wxID_ANY, wxT("MN   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer30->Add( m_staticText86, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer146->Add( bSizer30, 0, wxEXPAND, 5 );

	m_MNb = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 1e+06, 0.000000, 1 );
	m_MNb->SetDigits( 0 );
	bSizer146->Add( m_MNb, 0, wxALL, 5 );

	wxBoxSizer* bSizer486;
	bSizer486 = new wxBoxSizer( wxVERTICAL );

	m_MNt = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MNt->Wrap( -1 );
	bSizer486->Add( m_MNt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer146->Add( bSizer486, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer146, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer147;
	bSizer147 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText87 = new wxStaticText( this, wxID_ANY, wxT("DÑ     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	bSizer31->Add( m_staticText87, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer147->Add( bSizer31, 0, wxEXPAND, 5 );

	m_DN = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DN->Wrap( -1 );
	bSizer147->Add( m_DN, 0, wxALL, 5 );


	bSizer8->Add( bSizer147, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1471;
	bSizer1471 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText871 = new wxStaticText( this, wxID_ANY, wxT("RNG   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText871->Wrap( -1 );
	bSizer32->Add( m_staticText871, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1471->Add( bSizer32, 0, wxEXPAND, 5 );

	m_RNG = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_RNG->Wrap( -1 );
	bSizer1471->Add( m_RNG, 0, wxALL, 5 );


	bSizer8->Add( bSizer1471, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14721;
	bSizer14721 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8721 = new wxStaticText( this, wxID_ANY, wxT("PNT    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8721->Wrap( -1 );
	bSizer331->Add( m_staticText8721, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14721->Add( bSizer331, 0, wxEXPAND, 5 );

	m_PNT = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PNT->Wrap( -1 );
	bSizer14721->Add( m_PNT, 0, wxALL, 5 );


	bSizer8->Add( bSizer14721, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1472;
	bSizer1472 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText872 = new wxStaticText( this, wxID_ANY, wxT("BLQ    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText872->Wrap( -1 );
	bSizer33->Add( m_staticText872, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1472->Add( bSizer33, 0, wxEXPAND, 5 );

	m_BLQ = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BLQ->Wrap( -1 );
	bSizer1472->Add( m_BLQ, 0, wxALL, 5 );


	bSizer8->Add( bSizer1472, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164->Add( m_staticline4, 1, wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer164, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Detalle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	m_staticText43->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer341->Add( m_staticText43, 0, wxALL, 5 );


	bSizer8->Add( bSizer341, 0, wxALIGN_CENTER, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_Detalle = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE );
	#ifdef __WXGTK__
	if ( !m_Detalle->HasFlag( wxTE_MULTILINE ) )
	{
	m_Detalle->SetMaxLength( 1000 );
	}
	#else
	m_Detalle->SetMaxLength( 1000 );
	#endif
	bSizer34->Add( m_Detalle, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	bSizer8->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16411;
	bSizer16411 = new wxBoxSizer( wxVERTICAL );

	m_staticline411 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline411->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer16411->Add( m_staticline411, 1, 0, 5 );


	bSizer7->Add( bSizer16411, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_aplicarcambios = new wxButton( this, wxID_ANY, wxT("Aplicar cambios"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_aplicarcambios, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Exportar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer11->Add( m_button4, 0, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer11, 0, wxALIGN_RIGHT, 5 );


	bSizer9->Add( 0, 40, 0, 0, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Inventario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer9->Add( m_staticText32, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	wxArrayString m_InventarioChoices;
	m_Inventario = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_InventarioChoices, wxLB_SORT );
	bSizer41->Add( m_Inventario, 1, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer41, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button6, 0, wxALL, 5 );

	m_button34 = new wxButton( this, wxID_ANY, wxT("Borrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button34, 0, wxALL, 5 );


	bSizer9->Add( bSizer40, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer164111;
	bSizer164111 = new wxBoxSizer( wxVERTICAL );

	m_staticline4111 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline4111->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	bSizer164111->Add( m_staticline4111, 1, 0, 5 );


	bSizer7->Add( bSizer164111, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_aplicarcambios->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickAplicar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickExportar ), NULL, this );
	m_Inventario->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( Dialogo_Personaje::OnCheckListInventario ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickAgregar ), NULL, this );
	m_button34->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickBorrar ), NULL, this );
}

Dialogo_Personaje::~Dialogo_Personaje()
{
	// Disconnect Events
	m_aplicarcambios->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickAplicar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickExportar ), NULL, this );
	m_Inventario->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( Dialogo_Personaje::OnCheckListInventario ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickAgregar ), NULL, this );
	m_button34->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Dialogo_Personaje::OnClickBorrar ), NULL, this );

}
