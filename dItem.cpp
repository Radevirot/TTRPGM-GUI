#include "dItem.h"

dItem::dItem(wxWindow *parent, Partida *p, Item Im, int posc) : Dialogo_item(parent) {
	/*
	Ctor. de dItem utilizado cuando se quiere
	modificar un objeto desde la ventana de Partida.
	
	Admite puntero a la ventana padre, a la partida, un Item y una posición.
	
	Crea la tabla de atajos, se guarda el puntero de partida, se 
	guarda el Item que se haya ingresado, y también la posición del item en
	la lista de Partida.
	Obtiene la información del Item ingresado para poder mostrarla en la
	ventana, y finalmente muestra la ventana.
	*/
	
	CrearTablaDeAtajos();
	
	m_partida=p;
	I=Im; pos=posc;
	
	ObtenerInformacion(I);
	Show();
}

dItem::dItem(wxWindow *parent, Partida *p, Item &Im, int posc, bool usadoPorPartida) : Dialogo_item(parent) {
	/*
	Ctor. de dItem utilizado cuando se quiere modificar un objeto
	desde la ventana de Personaje.
	
	Admite puntero a la ventana padre, a la partida, un Item por
	referencia (ya que es necesario modificar directamente el que se
	le pasa desde la ventana de Personaje), una posición, y un booleano
	para saber que no está siendo usado por la ventana Partida.
	
	Crea la tabla de atajos, se guarda el puntero a la partida, la posición
	se copia la dirección en memoria del Item ingresado, y también se guarda
	el booleano.
	Obtiene la información del Item ingresado para poder mostrarla en la
	ventana, y finalmente muestra la ventana.
	*/
	
	CrearTablaDeAtajos();
	
	m_partida=p; pos=posc;
	Ims=&Im; _usadoPorPartida=usadoPorPartida;
	
	ObtenerInformacion(*Ims);
	Show();
}

dItem::~dItem() {
	
}

// MÉTODOS PRIVADOS

void dItem::CrearTablaDeAtajos(){
	/*
	Crea una tabla de atajos con 3, CTRL+S/CTRL+G para exportar,
	ENTER para aplicar cambios.
	*/
	wxAcceleratorEntry entries[3];
	entries[0].Set(wxACCEL_CTRL,(int) 'S', wxID_HIGHEST+17);
	entries[1].Set(wxACCEL_CTRL,(int) 'G', wxID_HIGHEST+18);
	entries[2].Set(wxACCEL_NORMAL,WXK_RETURN, wxID_HIGHEST+19);
	wxAcceleratorTable accel(3, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+17 , wxEVT_MENU, wxCommandEventHandler( dItem::OnClickExportar ));
	Connect( wxID_HIGHEST+18 , wxEVT_MENU, wxCommandEventHandler( dItem::OnClickExportar ));
	Connect( wxID_HIGHEST+19 , wxEVT_MENU, wxCommandEventHandler( dItem::OnClickAplicar ));
}

void dItem::ObtenerInformacion(Item &Ite){
	/*
	Se le pasa un item por referencia, y de este se obtienen todas sus 
	estadísticas para luego ser mostradas en la ventana.
	*/
	m_NombreItem->SetLabel(std_to_wx(Ite.ObtenerNombre()));
	m_Cantidad->SetValue(std_to_wx(std::to_string(Ite.ObtenerCant())));
	for(size_t i=0;i<vect.size();i++) { 
		vect[i]->SetValue(std_to_wx(std::to_string(Ite.ObtenerStat(i)))); 
	}
	m_Detalle->SetLabel(std_to_wx(Ite.ObtenerDetalle())); 
	m_Descripcion->SetLabel(std_to_wx(Ite.ObtenerDesc()));
}

void dItem::ActualizarInformacion(Item &Ite){
	/*
	Se le pasa un item por referencia, y a dicho item se le modifican
	todos los valores utilizando los ingresados en la ventana.
	*/
	Ite.NombrarItem(wx_to_std(m_NombreItem->GetValue()));
	Ite.ModificarCant(m_Cantidad->GetValue());
	for(size_t i=0;i<vect.size();i++) { 
		Ite.ModificarStat(i,(vect[i]->GetValue()));
	}
	Ite.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	Ite.ModificarDesc(wx_to_std(m_Descripcion->GetValue()));
}


// BOTONES DE LA VENTANA

void dItem::OnClickAplicar( wxCommandEvent& event )  {
	/*
	Al presionar "Aplicar cambios", si la ventana se abrió desde
	Partida entonces se actualiza la información del item, se borra
	el existente en la lista de Partida y se agrega uno nuevo con 
	los datos actualizados.
	Si la ventana se abrió desde Personaje, se actualiza la info
	del item que se le pasó originalmente sin borrar ni agregar nada.
	*/

	if(_usadoPorPartida){
		ActualizarInformacion(I);
		m_partida->EliminarItem(pos);
		m_partida->AgregarItem(I);
		EndModal(1);
	}else{
		ActualizarInformacion(*Ims);
		EndModal(1);
	}
	
}

void dItem::OnClickExportar( wxCommandEvent& event )  {
	/*
	Al exportar, si se abrió desde Partida se guarda el item
	I, que es el que se modificó en el ctor. Si se abrió
	desde Personaje, se guarda el item al que apunta Ims, por
	la misma razón.
	*/
	
	wxFileDialog exportarItem(this,wxT("Exportar item"),".\\datos",m_NombreItem->GetValue()+".ite","Archivos ITE (*.ite)|*.ite",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarItem.ShowModal()==wxID_OK){
		if(_usadoPorPartida){
			ActualizarInformacion(I);
			I.Exportar(wx_to_std(exportarItem.GetPath()));
		} else {
			ActualizarInformacion(*Ims);
			Ims->Exportar(wx_to_std(exportarItem.GetPath()));
		}
	}

}

// ATAJOS EXTRA DE TECLADO

void dItem::OnApretarTecla( wxKeyEvent& event ){
	/*
	Este evento se encarga de procesar atajos de teclado que son muy sencillos
	como para crearles eventos propios, ya que lo único que hacen es seleccionar
	un objeto de wx diferente.
	*/
	switch (event.GetKeyCode()){
	case (int) 'D': if(event.ControlDown()){ m_Detalle->SetFocus(); m_Detalle->SetSelection(-1,-1);} else event.Skip(); break;			// CTRL+D
	case (int) 'F': if(event.ControlDown()){ m_Descripcion->SetFocus(); m_Descripcion->SetSelection(-1,-1);} else event.Skip(); break;	// CTRL+F
	case (int) 'N': if(event.ControlDown()){ m_NombreItem->SetFocus(); m_NombreItem->SetSelection(-1,-1);} else event.Skip(); break;	// CTRL+N
	case (int) 'Q': if(event.ControlDown()){ m_Cantidad->SetFocus(); m_Cantidad-> SetSelection(-1,-1);} else event.Skip(); break;		// CTRL+Q
	default: event.Skip(); break;
	}
}

// RUEDITAS

/*
Cada evento de ruedita modifica el valor del wxSpinCtrlDouble en el que el
cursor se encuentre posicionado de acuerdo al movimiento de dicha rueda
(hacia arriba suma, hacia abajo resta).
*/

void dItem::OnRueditaDanio( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[7]->SetValue(vect[7]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[7]->SetValue(vect[7]->GetValue()+1);
	}
}

void dItem::OnRueditaRango( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[8]->SetValue(vect[8]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[8]->SetValue(vect[8]->GetValue()+1);
	}
}

void dItem::OnRueditaPunt( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[9]->SetValue(vect[9]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[9]->SetValue(vect[9]->GetValue()+1);
	}
}

void dItem::OnRueditaBloq( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[10]->SetValue(vect[10]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[10]->SetValue(vect[10]->GetValue()+1);
	}
}

void dItem::OnRueditaDef( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[1]->SetValue(vect[1]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[1]->SetValue(vect[1]->GetValue()+1);
	}
}

void dItem::OnRueditaResM( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[4]->SetValue(vect[4]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[4]->SetValue(vect[4]->GetValue()+1);
	}
}

void dItem::OnRueditaVida( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[0]->SetValue(vect[0]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[0]->SetValue(vect[0]->GetValue()+1);
	}
}

void dItem::OnRueditaFuerza( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[2]->SetValue(vect[2]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[2]->SetValue(vect[2]->GetValue()+1);
	}
}

void dItem::OnRueditaAgi( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[3]->SetValue(vect[3]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[3]->SetValue(vect[3]->GetValue()+1);
	}
}

void dItem::OnRueditaInte( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[5]->SetValue(vect[5]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[5]->SetValue(vect[5]->GetValue()+1);
	}
}

void dItem::OnRueditaMana( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[6]->SetValue(vect[6]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[6]->SetValue(vect[6]->GetValue()+1);
	}
}

