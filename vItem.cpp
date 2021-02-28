#include "vItem.h"


vItem::vItem(wxWindow *parent, Partida *p) : Ventana_item(parent) {
	/*
	Admite el puntero a la ventana padre y el puntero a la partida.
	Crea una tabla de atajos donde van solo aquellos que puedan
	utilizar métodos que ya existan en la ventana. Además, copia
	el puntero en la parte privada para poder modificar la partida.
	También muestra la ventana.
	*/
	
	wxAcceleratorEntry entries[3];
	entries[0].Set(wxACCEL_CTRL,(int) 'S', wxID_HIGHEST+1);
	entries[1].Set(wxACCEL_CTRL,(int) 'G', wxID_HIGHEST+2);
	entries[2].Set(wxACCEL_NORMAL,WXK_RETURN, wxID_HIGHEST+3);
	wxAcceleratorTable accel(3, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+1 , wxEVT_MENU, wxCommandEventHandler( vItem::OnClickExportar ));
	Connect( wxID_HIGHEST+2 , wxEVT_MENU, wxCommandEventHandler( vItem::OnClickExportar ));
	Connect( wxID_HIGHEST+3 , wxEVT_MENU, wxCommandEventHandler( vItem::OnClickAplicar ));
	
	m_partida=p;
	Show();
}

vItem::~vItem(){
	
}



Item vItem::CargarInformacion(){
	/*
	Método privado que retorna un item, lo que hace es crear uno y
	asignarle todas las variables que hayan sido modificadas en
	la ventana (nombre, cantidad, stats, etc.).
	*/
	
	Item I;
	
	I.NombrarItem(wx_to_std(m_NombreItem->GetValue()));
	I.ModificarCant(m_Cantidad->GetValue());
	for(size_t i=0;i<vect.size();i++) { 
		I.ModificarStat(i,(vect[i]->GetValue()));
	}
	I.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	I.ModificarDesc(wx_to_std(m_Descripcion->GetValue()));
	
	return I;
}

void vItem::OnClickAplicar( wxCommandEvent& event )  {
	/*
	Al presionar el botón "Aplicar", se crea un item utilizando
	el método privado CargarInformacion. Posteriormente se agrega
	el item a la lista de items de partida y esta última se ordena
	alfabéticamente, para finalmente cerrar la ventana.
	*/
	Item I=CargarInformacion();
	m_partida->AgregarItem(I);
	m_partida->OrdenarIAlph();
	Close(true);

}

void vItem::OnClickExportar( wxCommandEvent& event )  {
	/*
	Abre una ventana de archivos que sólo muestra los de extensión
	.ite, al aceptar utiliza el método CargarInformacion y luego de
	eso, el método Exportar de Item, que guarda el archivo en la ruta
	que devuelva la ventana de archivos.
	*/
	wxFileDialog exportarItem(this,wxT("Exportar item"),".\\datos",m_NombreItem->GetValue()+".ite","Archivos ITE (*.ite)|*.ite",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarItem.ShowModal()==wxID_OK){
		Item I=CargarInformacion();
		I.Exportar(wx_to_std(exportarItem.GetPath()));
	}
}

// ATAJOS EXTRA

void vItem::OnApretarTecla( wxKeyEvent& event )  {
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


// RUEDITAS (quisimos hacer esto con un for usando "HasFocus()", pero el método no funciona)

/*
Cada evento de ruedita modifica el valor del wxSpinCtrlDouble en el que el
cursor se encuentre posicionado de acuerdo al movimiento de dicha rueda
(hacia arriba suma, hacia abajo resta).
*/

void vItem::OnRueditaDanio( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[7]->SetValue(vect[7]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[7]->SetValue(vect[7]->GetValue()+1);
	}
}

void vItem::OnRueditaRango( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[8]->SetValue(vect[8]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[8]->SetValue(vect[8]->GetValue()+1);
	}
}

void vItem::OnRueditaPunt( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[9]->SetValue(vect[9]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[9]->SetValue(vect[9]->GetValue()+1);
	}
}

void vItem::OnRueditaBloq( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[10]->SetValue(vect[10]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[10]->SetValue(vect[10]->GetValue()+1);
	}
}

void vItem::OnRueditaDef( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[1]->SetValue(vect[1]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[1]->SetValue(vect[1]->GetValue()+1);
	}
}

void vItem::OnRueditaResM( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[4]->SetValue(vect[4]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[4]->SetValue(vect[4]->GetValue()+1);
	}
}

void vItem::OnRueditaVida( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[0]->SetValue(vect[0]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[0]->SetValue(vect[0]->GetValue()+1);
	}
}

void vItem::OnRueditaFuerza( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[2]->SetValue(vect[2]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[2]->SetValue(vect[2]->GetValue()+1);
	}
}

void vItem::OnRueditaAgi( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[3]->SetValue(vect[3]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[3]->SetValue(vect[3]->GetValue()+1);
	}
}

void vItem::OnRueditaInte( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[5]->SetValue(vect[5]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[5]->SetValue(vect[5]->GetValue()+1);
	}
}

void vItem::OnRueditaMana( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		vect[6]->SetValue(vect[6]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		vect[6]->SetValue(vect[6]->GetValue()+1);
	}
}


