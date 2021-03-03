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
	
	SetIcon(wxIcon("imagenes\\logo.ico",wxBITMAP_TYPE_ICO));
	
	ActualizarNombre();
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
	/* Opcion que permite modificar el nombre de la partida en curso. */
	dNombrePartida NomPart(this,m_partida);
	NomPart.SetIcon(wxIcon("imagenes\\renombrar.ico",wxBITMAP_TYPE_ICO));
	NomPart.SetTitle(wxT("Renombrar partida"));
	int valor = NomPart.ShowModal();
	if (valor==1) this->ActualizarNombre();
}

void vPartida::OnMenuNueva( wxCommandEvent& event )  {
	/* Opcion que permite crear una nueva partida. */
	dNombrePartida NomPart(this,m_partida);
	NomPart.SetIcon(wxIcon("imagenes\\Nueva.ico",wxBITMAP_TYPE_ICO));
	NomPart.SetTitle(wxT("Nueva partida"));
	int valor = NomPart.ShowModal();
	if(valor==1){
		Partida b(m_partida->ObtenerNombre());
		*m_partida= b;
		this->ActualizarNombre();
		this->ActualizarListas();
	}
}

void vPartida::OnMenuGuardar( wxCommandEvent& event )  {
	/* Opcion que permite guardar la partida actual. */
	wxFileDialog guardarPartida(this,wxT("Guardar partida"),".\\datos",m_partida->ObtenerNombre()+".part","Archivos PART (*.part)|*.part",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(guardarPartida.ShowModal()==wxID_OK){
		m_partida->Guardar(wx_to_std(guardarPartida.GetPath()));
	}
}

void vPartida::OnMenuCargar( wxCommandEvent& event )  {
	/* Opcion que permite cargar una partida guardada con anterioridad. */
	wxFileDialog cargarPartida(this,wxT("Elija un archivo de partida para cargar"),".\\datos","","Archivos PART (*.part)|*.part",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(cargarPartida.ShowModal()==wxID_OK){
		Partida b("");
		if(b.Cargar(wx_to_std(cargarPartida.GetPath()))){
			*m_partida=b;
			this->ActualizarNombre();
			this->ActualizarListas();
		} else{
			wxMessageBox(wxT("No se pudo abrir el archivo."),wxT("Error"),wxICON_ERROR);
		}
	}
}

void vPartida::OnMenuAyuda( wxCommandEvent& event )  {
	/* Opcion que envia al pdf donde se muestra una guia y los atajos. */
	if (!wxLaunchDefaultApplication(wxT(".\\ayuda.pdf"))){
		wxMessageBox(wxT("No se pudo abrir el archivo. Puede abrirlo manualmente\ndirigi\u00e9ndose al directorio de instalaci\u00F3n y abriendo \"ayuda.pdf\"."),wxT("Error"),wxICON_ERROR);
	}
}


// TOOLBAR 

void vPartida::OnClickCombate( wxCommandEvent& event )  {
	/* Abre la ventana de combate. */
	if (m_partida->ObtenerTamPersonajes()==0){
		wxMessageBox(wxT("Debe tener al menos un personaje creado."),wxT("Error"),wxICON_ERROR);
	} else {
		vCombate *Combate = new vCombate(this, m_partida);
		Combate->SetIcon(wxIcon("imagenes\\combate.ico",wxBITMAP_TYPE_ICO));
	}
}

void vPartida::OnClickDado( wxCommandEvent& event )  {
	/* Abre la ventana de dados. */
	vDados *Dados = new vDados(this,m_partida);
	Dados->SetIcon(wxIcon("imagenes\\dado.ico",wxBITMAP_TYPE_ICO));
}


// BOTONES DE PERSONAJE 

void vPartida::OnClickCrearP( wxCommandEvent& event )  {
	/* Abre la ventana de creacion de personaje. */
	vPersonaje *Pers = new vPersonaje(this, m_partida);
	Pers->SetIcon(wxIcon("imagenes\\agregar.ico",wxBITMAP_TYPE_ICO));
}

void vPartida::OnClickImportarP( wxCommandEvent& event )  {
	/*
	Abre una ventana de archivos para poder cargar un personaje, actualizando la lista.
	*/
	wxFileDialog importarPersonaje(this,wxT("Elija un archivo de personaje para importar"),".\\datos","","Archivos PER (*.per)|*.per",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (importarPersonaje.ShowModal()==wxID_OK){
		Personaje P;
		if (P.Importar(wx_to_std(importarPersonaje.GetPath()))){
			m_partida->AgregarPersonaje(P);
			m_partida->OrdenarPAlph();
			this->ActualizarListas();
		} else {
			wxMessageBox(wxT("No se pudo abrir el archivo."),wxT("Error"),wxICON_ERROR);
		}

	}
}

void vPartida::OnClickBorrarPersonaje( wxCommandEvent& event )  {
	/* Borra un personaje seleccionado y actualiza la lista. */
	if(m_ListaPersonajes->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un personaje sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int pos = m_ListaPersonajes->GetSelection();
		m_partida->EliminarPersonaje(pos);
		m_ListaPersonajes->Delete(pos);
	}
}

void vPartida::OnClickVerInventario( wxCommandEvent& event )  {
	/*
	Abre la ventana dInventario para poder
	agregar un item al personaje seleccionado.
	*/
	int pos = m_ListaPersonajes->GetSelection();
	if(pos==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible agregar un item a un personaje\nsin haber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		Personaje P=m_partida->ObtenerPersonaje(pos);
		dInventario InvPer(this,P,m_partida);
		InvPer.SetIcon(wxIcon("imagenes\\agregar.ico",wxBITMAP_TYPE_ICO));
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
	/*
	Con el Doble-Click abre la ventana
	dPersonaje para editar el seleccionado.
	*/
	int pos = m_ListaPersonajes->GetSelection();
	Personaje P=m_partida->ObtenerPersonaje(pos);
	dPersonaje PersonajeMod(this,m_partida,P,pos);
	PersonajeMod.SetIcon(wxIcon("imagenes\\modificar.ico",wxBITMAP_TYPE_ICO));
	PersonajeMod.ShowModal();
}


// BOTONES DE ITEM 

void vPartida::OnClickCrearI( wxCommandEvent& event )  {
	/* Abre la ventana de creacion del item. */
	vItem *Item = new vItem(this, m_partida);
	Item->SetIcon(wxIcon("imagenes\\agregar.ico",wxBITMAP_TYPE_ICO));
	
}

void vPartida::OnClickImportarI( wxCommandEvent& event )  {
	/*
	Abre la ventana de archivos para cargar un item, actualiza la lista.
	*/
	wxFileDialog importarItem(this,wxT("Elija un archivo de item para importar"),".\\datos","","Archivos ITE (*.ite)|*.ite",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (importarItem.ShowModal()==wxID_OK){
		Item I;
		if (I.Importar(wx_to_std(importarItem.GetPath()))){
			m_partida->AgregarItem(I);
			m_partida->OrdenarIAlph();
			this->ActualizarListas();
		} else {
			wxMessageBox(wxT("No se pudo abrir el archivo."),wxT("Error"),wxICON_ERROR);
		}
	}
}

void vPartida::OnClickBorrar( wxCommandEvent& event )  {
	/* Borra un item seleccionado. */
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
	/*
	Con Doble-Click abre la ventana dItem para editar el seleccionado.
	*/
	int pos = m_ListaItems->GetSelection();
	Item I=m_partida->ObtenerItem(pos);
	dItem ItemMod(this,m_partida,I,pos);
	ItemMod.SetIcon(wxIcon("imagenes\\modificar.ico",wxBITMAP_TYPE_ICO));
	ItemMod.ShowModal();
}


// TECLAS

void vPartida::OnApretarSupr( wxCommandEvent& event ){
	/*
	Revisa cuál de las listas está enfocada y, en ambos casos,
	borra lo que esté seleccionado en dicha lista.
	*/
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
	/*
	Revisa cuál de las listas está enfocada y, en ambos casos,
	abre la ventana de modificación correspondiente.
	*/
	if(m_ListaItems->HasFocus()){
		int pos = m_ListaItems->GetSelection();
		if(pos!=wxNOT_FOUND){
			Item I=m_partida->ObtenerItem(pos);
			dItem ItemMod(this,m_partida,I,pos);
			ItemMod.SetIcon(wxIcon("imagenes\\modificar.ico",wxBITMAP_TYPE_ICO));
			ItemMod.ShowModal();
		}
	} else if(m_ListaPersonajes->HasFocus()) {
		int pos = m_ListaPersonajes->GetSelection();
		if(pos!=wxNOT_FOUND){
			Personaje P=m_partida->ObtenerPersonaje(pos);
			dPersonaje PersonajeMod(this,m_partida,P,pos);
			PersonajeMod.SetIcon(wxIcon("imagenes\\modificar.ico",wxBITMAP_TYPE_ICO));
			PersonajeMod.ShowModal();
		}
	}
}

// EVENTO DE ACTUALIZACIÓN

void vPartida::OnActivarPartida( wxActivateEvent& event )  {
	/*
	Actualiza las listas al tocar la ventana Partida.
	*/
	this->ActualizarListas();
}





