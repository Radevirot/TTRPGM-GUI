#include "vPartida.h"


vPartida::vPartida(wxWindow *parent, Partida *p) : Ventana_partida(parent) {
	/*
	Constructor de la ventana Partida, se le ingresan como parámetros un puntero
	a la ventana padre y otro a la partida actual.
	Crea una tabla de atajos de teclado.
	Guarda el valor del puntero, actualiza el nombre de la ventana, y la muestra.
	*/
	
	wxAcceleratorEntry entries[8];
	entries[0].Set(wxACCEL_CTRL,(int) 'O', wxID_HIGHEST+4);
	entries[1].Set(wxACCEL_CTRL,(int) 'S', wxID_HIGHEST+5);
	entries[2].Set(wxACCEL_CTRL,(int) '1', wxID_HIGHEST+6);
	entries[3].Set(wxACCEL_CTRL,(int) '2', wxID_HIGHEST+7);
	entries[4].Set(wxACCEL_CTRL,(int) 'P', wxID_HIGHEST+8);
	entries[5].Set(wxACCEL_CTRL,(int) 'I', wxID_HIGHEST+9);
	entries[6].Set(0,WXK_DELETE, wxID_HIGHEST+10);
	entries[7].Set(0,WXK_RETURN, wxID_HIGHEST+11);
	wxAcceleratorTable accel(8, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+4 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnMenuCargar ));
	Connect( wxID_HIGHEST+5 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnMenuGuardar ));
	Connect( wxID_HIGHEST+6 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnClickCombate ));
	Connect( wxID_HIGHEST+7 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnClickDado ));
	Connect( wxID_HIGHEST+8 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnClickCrearP ));
	Connect( wxID_HIGHEST+9 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnClickCrearI ));
	Connect( wxID_HIGHEST+10 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnApretarSupr ));
	Connect( wxID_HIGHEST+11 , wxEVT_MENU, wxCommandEventHandler( vPartida::OnApretarEnter ));
	
	m_partida=p;
	wxBitmap prueba(wxT("imagenes/logo.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(prueba);
	_icon=icon;
	this->SetIcon(icon);
	this->ActualizarNombre();
	Show();
}

vPartida::~vPartida() {
	
}


// MÉTODOS PRIVADOS AUXILIARES PARA EVITAR REPETIR CÓDIGO

void vPartida::ActualizarNombre() {
	/*
	Actualiza el nombre de la ventana pidiendo el actual de partida y
	agregándole " - Administrador de RPG de mesa" al final.
	*/
	std::string name = m_partida->ObtenerNombre()+" - Administrador de RPG de mesa";
	this->SetTitle(std_to_wx(name));
}

void vPartida::ActualizarListas(){
	/*
	Limpia ambas listas visualmente, ordena alfabéticamente las de Partida, y
	las carga visualmente nuevamente, añadiendo el daño de cada Item y los puntos
	de vida de cada Personaje. Además, si el nombre excede los 30 caracteres, se
	colocan puntos suspensivos para evitar el redimensionamiento de la ventana.
	*/
	m_ListaItems->Clear();
	m_ListaPersonajes->Clear();
	m_partida->OrdenarIAlph();
	m_partida->OrdenarPAlph();
	for(int i=0;i<m_partida->ObtenerCantidadDeItems();i++) { 
		Item I=m_partida->ObtenerItem(i);
		std::string nombrefinal = I.ObtenerNombre().substr(0,30);
		if(I.ObtenerNombre().length()>30){
			nombrefinal += "... - DÑ: ";
		} else{
			nombrefinal += " - DÑ: ";
		}
		wxString numerito; numerito.Printf("%.2f",I.ObtenerStat(7));
		nombrefinal += numerito;
		m_ListaItems->Append(std_to_wx(nombrefinal));
	}
	for(int i=0;i<m_partida->ObtenerTamPersonajes();i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		std::string nombrefinal = P.ObtenerNombre().substr(0,30);
		if(P.ObtenerNombre().length()>30){
			nombrefinal += "... - PV: ";
		} else{
			nombrefinal += " - PV: ";
		}
		wxString numerito; numerito.Printf("%.2f",P.ObtenerStat(0));
		nombrefinal += numerito;
		m_ListaPersonajes->Append(std_to_wx(nombrefinal));
	}
}


// BARRA DE MENU 

void vPartida::OnMenuEditar( wxCommandEvent& event )  {
	/*
	Abre una ventana de cambio de nombre de partida, le
	coloca el icono del botón "renombrar", le cambia el nombre
	a la ventana por "Renombrar partida", y si el usuario
	aceptó en vez de cancelar se le cambia el nombre a la partida.
	*/
	dNombrePartida NomPart(this,m_partida);
	wxBitmap renombrar(wxT("imagenes/renombrar.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(renombrar);
	NomPart.SetIcon(icon);
	NomPart.SetTitle(wxT("Renombrar partida"));
	if (NomPart.ShowModal()==1) this->ActualizarNombre();
}

void vPartida::OnMenuNueva( wxCommandEvent& event )  {
	/*
	Abre una ventana de creación de partida, le
	coloca el icono del botón "Nueva", le cambia el nombre
	a la ventana por "Nueva partida", y si el usuario
	aceptó en vez de cancelar, se crea una partida nueva y
	se hace que el puntero apunte a esa nueva partida.
	Posteriormente se actualiza el nombre y las listas visualmente.
	*/
	dNombrePartida NomPart(this,m_partida);
	wxBitmap nueva(wxT("imagenes/Nueva.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(nueva);
	NomPart.SetIcon(icon);
	NomPart.SetTitle(wxT("Nueva partida"));
	if(NomPart.ShowModal()==1){
		Partida b(m_partida->ObtenerNombre());
		*m_partida= b;
		this->ActualizarNombre();
		this->ActualizarListas();
	}
}

void vPartida::OnMenuGuardar( wxCommandEvent& event )  {
	/*
	Se muestra una ventana 
	de archivos que sólo muestra los de extensión .part,
	si el usuario elije un nombre, se guarda la partida con 
	la ruta especificada.
	*/
	wxFileDialog guardarPartida(this,wxT("Guardar partida"),".\\datos",m_partida->ObtenerNombre()+".part","Archivos PART (*.part)|*.part",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(guardarPartida.ShowModal()==wxID_OK){
		m_partida->Guardar(wx_to_std(guardarPartida.GetPath()));
	}
}

void vPartida::OnMenuCargar( wxCommandEvent& event )  {
	/*
	Se muestra una ventana 
	de archivos que sólo muestra los de extensión .part,
	si el usuario selecciona uno, se carga la partida con 
	la ruta especificada y se actualiza el nombre y las
	listas visualmente.
	*/
	wxFileDialog cargarPartida(this,wxT("Elija un archivo de partida para cargar"),".\\datos","","Archivos PART (*.part)|*.part",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(cargarPartida.ShowModal()==wxID_OK){
		Partida b("");
		*m_partida=b;
		m_partida->Cargar(wx_to_std(cargarPartida.GetPath()));
		this->ActualizarNombre();
		this->ActualizarListas();
	}
}

void vPartida::OnMenuAyuda( wxCommandEvent& event )  {
	/* Abre el PDF de ayuda */
	wxLaunchDefaultApplication(wxT(".\\ayuda.pdf"));
}


// TOOLBAR 

void vPartida::OnClickCombate( wxCommandEvent& event )  {
	/*
	Si el jugador no tiene personajes creados muestra un error, si tiene
	se crea una ventana de combate y se le coloca su respectivo icono.
	*/
	if (m_partida->ObtenerTamPersonajes()==0){
		wxMessageBox(wxT("Debe tener al menos un personaje creado."),wxT("Error"),wxICON_ERROR);
	} else {
		vCombate *Combate = new vCombate(this, m_partida);
		wxBitmap combat(wxT("imagenes/combate.bmp"), wxBITMAP_TYPE_ANY);
		wxIcon icon;
		icon.CopyFromBitmap(combat);
		Combate->SetIcon(icon);
	}
}

void vPartida::OnClickDado( wxCommandEvent& event )  {
	/* Se crea una ventana de dados y se le coloca su respectivo icono. */
	vDados *Dados = new vDados(this,m_partida);
	wxBitmap dado(wxT("imagenes/dado.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(dado);
	Dados->SetIcon(icon);
}


// BOTONES DE PERSONAJE 

void vPartida::OnClickCrearP( wxCommandEvent& event )  {
	/*
	Se crea una ventana de creación de personaje
	y se le coloca su respectivo icono.
	*/
	vPersonaje *Pers = new vPersonaje(this, m_partida);
	Pers->SetIcon(_icon);
}

void vPartida::OnClickImportarP( wxCommandEvent& event )  {
	/*
	Ventana de archivos, extensión .per, si aceptó se crea un Personaje,
	se importa, se agrega a la partida, se ordena alfabeticamente y se
	actualiza la lista.
	*/
	wxFileDialog importarPersonaje(this,wxT("Elija un archivo de personaje para importar"),".\\datos","","Archivos PER (*.per)|*.per",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (importarPersonaje.ShowModal()==wxID_OK){
		Personaje P;
		P.Importar(wx_to_std(importarPersonaje.GetPath()));
		m_partida->AgregarPersonaje(P);
		m_partida->OrdenarPAlph();
		this->ActualizarListas();
	}
}

void vPartida::OnClickBorrarPersonaje( wxCommandEvent& event )  {
	/*
	Si no hay nada seleccionado muestra un error, si lo hay borra un personaje de
	la lista y de la partida.
	*/
	if(m_ListaPersonajes->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un personaje sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int pos = m_ListaPersonajes->GetSelection();
		m_partida->EliminarPersonaje(pos);
		m_ListaPersonajes->Delete(pos);
	}
}

void vPartida::OnClickVerInventario( wxCommandEvent& event )  {
	int pos = m_ListaPersonajes->GetSelection();
	if(pos==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible agregar un item a un personaje\nsin haber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		Personaje P=m_partida->ObtenerPersonaje(pos);
		dInventario InvPer(this,P,m_partida);
		if (InvPer.ShowModal()==1){
			m_partida->EliminarPersonaje(pos);
			P.OrdenarAlph();
			m_partida->AgregarPersonaje(P);
			m_partida->OrdenarPAlph();
		}
	}
}


// LISTA DE PERSONAJES

void vPartida::OnDobleClickListaPersonaje( wxCommandEvent& event )  {
	int pos = m_ListaPersonajes->GetSelection();
	Personaje P=m_partida->ObtenerPersonaje(pos);
	dPersonaje PersonajeMod(this,m_partida,P,pos);
	PersonajeMod.SetIcon(_icon);
	PersonajeMod.ShowModal();
}


// BOTONES DE ITEM 

void vPartida::OnClickCrearI( wxCommandEvent& event )  {
	vItem *Item = new vItem(this, m_partida);
	Item->SetIcon(_icon);
	
}

void vPartida::OnClickImportarI( wxCommandEvent& event )  {
	wxFileDialog importarItem(this,wxT("Elija un archivo de item para importar"),".\\datos","","Archivos ITE (*.ite)|*.ite",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (importarItem.ShowModal()==wxID_OK){
		Item I;
		I.Importar(wx_to_std(importarItem.GetPath()));
		m_partida->AgregarItem(I);
		m_partida->OrdenarIAlph();
		this->ActualizarListas();
	}
}

void vPartida::OnClickBorrar( wxCommandEvent& event )  {
	if(m_ListaItems->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un item sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int pos = m_ListaItems->GetSelection();
		m_partida->EliminarItem(pos);
		m_ListaItems->Delete(pos);
	}
	
}


// LISTA DE ITEMS 

void vPartida::OnDobleClickListaItem( wxCommandEvent& event )  {
	
	int pos = m_ListaItems->GetSelection();
	Item I=m_partida->ObtenerItem(pos);
	dItem ItemMod(this,m_partida,I,pos);
	ItemMod.SetIcon(_icon);
	ItemMod.ShowModal();
}


// TECLAS

void vPartida::OnApretarSupr( wxCommandEvent& event ){
	if(m_ListaItems->HasFocus()){
		int pos = m_ListaItems->GetSelection();
		if(pos!=wxNOT_FOUND){
			m_partida->EliminarItem(pos);
			m_ListaItems->Delete(pos);
			if(m_ListaItems->GetSelection()!=wxNOT_FOUND) m_ListaItems->SetSelection(pos); else m_ListaItems->SetSelection(pos-1);
		}
	} else if(m_ListaPersonajes->HasFocus()) {
		int pos = m_ListaPersonajes->GetSelection();
		if(pos!=wxNOT_FOUND){
			m_partida->EliminarPersonaje(pos);
			m_ListaPersonajes->Delete(pos);
			if(m_ListaPersonajes->GetSelection()!=wxNOT_FOUND) m_ListaPersonajes->SetSelection(pos); else m_ListaPersonajes->SetSelection(pos-1);
		}
	}
}

void vPartida::OnApretarEnter( wxCommandEvent& event ){
	if(m_ListaItems->HasFocus()){
		int pos = m_ListaItems->GetSelection();
		if(pos!=wxNOT_FOUND){
			Item I=m_partida->ObtenerItem(pos);
			dItem ItemMod(this,m_partida,I,pos);
			ItemMod.SetIcon(_icon);
			ItemMod.ShowModal();
		}
	} else if(m_ListaPersonajes->HasFocus()) {
		int pos = m_ListaPersonajes->GetSelection();
		if(pos!=wxNOT_FOUND){
			Personaje P=m_partida->ObtenerPersonaje(pos);
			dPersonaje PersonajeMod(this,m_partida,P,pos);
			PersonajeMod.SetIcon(_icon);
			PersonajeMod.ShowModal();
		}
	}
}

// EVENTO DE ACTUALIZACIÓN

void vPartida::OnActivarPartida( wxActivateEvent& event )  {
	this->ActualizarListas();
}





