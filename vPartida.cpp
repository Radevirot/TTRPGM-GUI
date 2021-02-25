#include "vPartida.h"


vPartida::vPartida(wxWindow *parent, Partida *p) : Ventana_partida(parent) {
	/*
	Constructor de la ventana Partida, se le ingresan como parámetros un puntero
	a la ventana padre y otro a la partida actual.
	Guarda el valor del puntero, actualiza el nombre de la ventana, y la muestra.
	*/
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
	agregándole "TTRPGM: " al comienzo.
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
		std::string numerito=std::to_string(I.ObtenerStat(7));
		numerito.erase(numerito.end()-4,numerito.end());
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
		std::string numerito=std::to_string(P.ObtenerStat(0));
		numerito.erase(numerito.end()-4,numerito.end());
		nombrefinal += numerito;
		m_ListaPersonajes->Append(std_to_wx(nombrefinal));
	}
}

void vPartida::GuardarPartida(){
	wxFileDialog guardarPartida(this,wxT("Guardar partida"),".\\datos",m_partida->ObtenerNombre()+".part","Archivos PART (*.part)|*.part",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(guardarPartida.ShowModal()==wxID_OK){
		m_partida->Guardar(wx_to_std(guardarPartida.GetPath()));
	}
}
void vPartida::CargarPartida(){
	wxFileDialog cargarPartida(this,wxT("Elija un archivo de partida para cargar"),".\\datos","","Archivos PART (*.part)|*.part",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(cargarPartida.ShowModal()==wxID_OK){
		Partida b("");
		*m_partida=b;
		m_partida->Cargar(wx_to_std(cargarPartida.GetPath()));
		this->ActualizarNombre();
		this->ActualizarListas();
	}
}

void vPartida::NuevaPartida(){
	dNombrePartida NomPart(this,m_partida);
	wxBitmap nueva(wxT("imagenes/Nueva.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(nueva);
	NomPart.SetIcon(icon);
	NomPart.SetTitle(wxT("Nueva partida"));
	int valor = NomPart.ShowModal();
	if(valor==1){
		Partida b(m_partida->ObtenerNombre());
		*m_partida= b;
		this->ActualizarNombre();
		this->ActualizarListas();
	}
}

void vPartida::RenombrarPartida(){
	dNombrePartida NomPart(this,m_partida);
	wxBitmap renombrar(wxT("imagenes/renombrar.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(renombrar);
	NomPart.SetIcon(icon);
	NomPart.SetTitle(wxT("Renombrar partida"));
	int valor = NomPart.ShowModal();
	if (valor==1) this->ActualizarNombre();
}

void vPartida::AbrirCombate(){
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

void vPartida::AbrirDados(){
	vDados *Dados = new vDados(this,m_partida);
	wxBitmap dado(wxT("imagenes/dado.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(dado);
	Dados->SetIcon(icon);
}

// BARRA DE MENU 

void vPartida::OnMenuEditar( wxCommandEvent& event )  {
	this->RenombrarPartida();
}

void vPartida::OnMenuNueva( wxCommandEvent& event )  {
	this->NuevaPartida();
}

void vPartida::OnMenuGuardar( wxCommandEvent& event )  {
	this->GuardarPartida();
}

void vPartida::OnMenuCargar( wxCommandEvent& event )  {
	this->CargarPartida();
}

void vPartida::OnMenuAyuda( wxCommandEvent& event )  {
	event.Skip();
}

// TOOLBAR 

void vPartida::OnClickCombate( wxCommandEvent& event )  {
	this->AbrirCombate();
}

void vPartida::OnClickDado( wxCommandEvent& event )  {
	this->AbrirDados();
}

// BOTONES DE PERSONAJE 

void vPartida::OnClickCrearP( wxCommandEvent& event )  {
	vPersonaje *Pers = new vPersonaje(this, m_partida);
	Pers->SetIcon(_icon);
}

void vPartida::OnClickImportarP( wxCommandEvent& event )  {
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
	if(m_ListaPersonajes->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un personaje sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int pos = m_ListaPersonajes->GetSelection();
		m_partida->EliminarPersonaje(pos);
		m_ListaPersonajes->Delete(pos);
	}
}

void vPartida::OnClickVerInventario( wxCommandEvent& event )  {
	event.Skip();
}

// LISTA DE PERSONAJES

void vPartida::OnDobleClickListaPersonaje( wxCommandEvent& event )  {
	if(manteniendoControl){
		int pos = m_ListaPersonajes->GetSelection();
		Personaje P=m_partida->ObtenerPersonaje(pos);
		dInventario InvPer(this,P,m_partida);
		if (InvPer.ShowModal()==1){
			m_partida->EliminarPersonaje(pos);
			m_partida->AgregarPersonaje(P);
			m_partida->OrdenarPAlph();
		}
	} else {
		int pos = m_ListaPersonajes->GetSelection();
		Personaje P=m_partida->ObtenerPersonaje(pos);
		dPersonaje PersonajeMod(this,m_partida,P,pos);
		PersonajeMod.SetIcon(_icon);
		PersonajeMod.ShowModal();
	}
	
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
	dItem ItemMod(this,m_partida,I,pos/*,true*/);
	ItemMod.SetIcon(_icon);
	ItemMod.ShowModal();
}


// TECLAS

void vPartida::OnApretarTecla( wxKeyEvent& event )  {
	switch (event.GetKeyCode()){
	case WXK_DELETE:
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
	case WXK_CONTROL: manteniendoControl=true; break;
	case 83: case 71: if(manteniendoControl) this->GuardarPartida(); break; //		83=S,71=G | CTRL+S / CTRL+G para guardar
	case 79: case 65: if(manteniendoControl) this->CargarPartida(); break; //		79=O,65=A | CTRL+O / CTRL+A para cargar
	case 78: if(manteniendoControl) this->NuevaPartida(); break; //					78=N 	  | CTRL+N para crear nueva
	case 82: if(manteniendoControl) this->RenombrarPartida(); break; //				82=R 	  | CTRL+R para renombrar
	case 49: if(manteniendoControl) this->AbrirCombate(); break; //					49=1	  | CTRL+1 para abrir ventana de combate
	case 50: if(manteniendoControl) this->AbrirDados(); break; //					50=2	  | CTRL+2 para abrir ventana de dados
	}
}

void vPartida::OnLevantarTecla( wxKeyEvent& event )  {
	switch (event.GetKeyCode()){
		case WXK_CONTROL: manteniendoControl=false; break;
	}
}


// EVENTO DE ACTUALIZACIÓN

void vPartida::OnActivarPartida( wxActivateEvent& event )  {
	manteniendoControl=false;
	this->ActualizarListas();
}





