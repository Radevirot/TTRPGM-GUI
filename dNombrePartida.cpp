#include "dNombrePartida.h"

dNombrePartida::dNombrePartida(wxWindow *parent, Partida *p) : Dialogo_NombrePartida(parent) {
	/*
	Constructor de la ventana dNombrePartida, se le ingresan como parámetros un puntero
	a la ventana padre y otro a la partida actual.
	Guarda el puntero de la partida en el privado.
	*/
	m_partida=p;
}

dNombrePartida::~dNombrePartida() {
	
}



//BOTONES DE LA VENTANA

void dNombrePartida::OnClickAceptar( wxCommandEvent& event )  {
	/*
	Se modifica el nombre de la partida y se cierra la ventana actual
	retornando 1, que indica que el usuario presionó "Aceptar".
	*/
	m_partida->ModificarNombre(wx_to_std(m_textCtrlNombrePart->GetValue()));
	EndModal(1);
}

void dNombrePartida::OnClickCancelar( wxCommandEvent& event )  {
	/*
	Se cierra la ventana retornando 0, indicando que el usuario
	presionó "Cancelar".
	*/
	EndModal(0);
}


//ATAJO DE TECLADO

void dNombrePartida::OnTextEnter( wxCommandEvent& event )  {
	/* Hace lo mismo que OnClickAceptar. */
	m_partida->ModificarNombre(wx_to_std(m_textCtrlNombrePart->GetValue()));
	EndModal(1);
}

