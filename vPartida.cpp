#include "vPartida.h"


vPartida::vPartida(wxWindow *parent, Partida *p) : Ventana_partida(parent) {
	/*
	Constructor de la ventana Partida, se le ingresan como parámetros un puntero
	a la ventana padre y otro a la partida actual.
	Guarda el valor del puntero, actualiza el nombre de la ventana, y la muestra.
	*/
	m_partida=p;
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
	std::string name = "TTRPGM: " + m_partida->ObtenerNombre();
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

// BARRA DE MENU 

void vPartida::OnMenuEditar( wxCommandEvent& event )  {
	dNombrePartida NomPart(this,m_partida);
	int valor = NomPart.ShowModal();
	if (valor==1) this->ActualizarNombre();
}

void vPartida::OnMenuNueva( wxCommandEvent& event )  {
	dNombrePartida NomPart(this,m_partida);
	int valor = NomPart.ShowModal();
	if(valor==1){
		Partida b(m_partida->ObtenerNombre());
		*m_partida= b;
		this->ActualizarNombre();
		this->ActualizarListas();
	}
}

void vPartida::OnMenuGuardar( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnMenuCargar( wxCommandEvent& event )  {
	event.Skip();
}

void vPartida::OnMenuAyuda( wxCommandEvent& event )  {
	event.Skip();
}

// TOOLBAR 

void vPartida::OnClickCombate( wxCommandEvent& event )  {
	if (m_partida->ObtenerTamPersonajes()==0){
		wxMessageBox(wxT("Debe tener al menos un personaje creado."),wxT("Error"),wxICON_ERROR);
	} else {
		vCombate *Combate = new vCombate(this, m_partida);
	}
	
}

void vPartida::OnClickDado( wxCommandEvent& event )  {
	vDados *Dados = new vDados(this,m_partida);
}

// BOTONES DE PERSONAJE 

void vPartida::OnClickCrearP( wxCommandEvent& event )  {
	vPersonaje *Pers = new vPersonaje(this, m_partida);
}

void vPartida::OnClickImportarP( wxCommandEvent& event )  {
	event.Skip();
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
	int pos = m_ListaPersonajes->GetSelection();
	Personaje P=m_partida->ObtenerPersonaje(pos);
	dPersonaje PersonajeMod(this,m_partida,P,pos);
	PersonajeMod.ShowModal();
}

void vPartida::OnApretarTeclaPList( wxKeyEvent& event )  {
	if(event.GetKeyCode()==WXK_DELETE){
		if(m_ListaPersonajes->HasFocus()){
			int pos = m_ListaPersonajes->GetSelection();
			if(pos!=wxNOT_FOUND){
				m_partida->EliminarPersonaje(pos);
				m_ListaPersonajes->Delete(pos);
				m_ListaPersonajes->SetSelection(pos);
			}
			
		}
	} else {
		event.Skip();
	}
}

// BOTONES DE ITEM 

void vPartida::OnClickCrearI( wxCommandEvent& event )  {
	vItem *Item = new vItem(this, m_partida);
	
}

void vPartida::OnClickImportarI( wxCommandEvent& event )  {
	wxFileDialog exportarItem(this,wxT("Elija un archivo de item para importar"),"","","Archivos DAT (*.dat)|*.dat",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (exportarItem.ShowModal()==wxID_OK){
		
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
	ItemMod.ShowModal();
}

void vPartida::OnApretarTeclaIList( wxKeyEvent& event )  {
	if(event.GetKeyCode()==WXK_DELETE){
		if(m_ListaItems->HasFocus()){
			int pos = m_ListaItems->GetSelection();
			if(pos!=wxNOT_FOUND){
				m_partida->EliminarItem(pos);
				m_ListaItems->Delete(pos);
				m_ListaItems->SetSelection(pos);
			}
			
		}
	} else{
		event.Skip();
	}
}

// EVENTO DE ACTUALIZACIÓN

void vPartida::OnActivarPartida( wxActivateEvent& event )  {
	this->ActualizarListas();
}
