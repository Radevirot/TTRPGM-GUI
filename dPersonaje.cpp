#include "dPersonaje.h"


dPersonaje::dPersonaje(wxWindow *parent, Partida *p, Personaje &P, int posc) : Dialogo_Personaje(parent) {
	/*
	Constructor de la ventana dPersonaje, se le ingresan como parámetros un puntero
	a la ventana padre, otro a la partida actual, un personaje por referencia y 
	un entero que indica la posicion en la lista de partida.
	Carga y muestra los datos del personaje. Modifica los toggle de los items
	y tilda los casilleros corespondientes.
	*/
	
	wxAcceleratorEntry entries[5];
	entries[0].Set(wxACCEL_CTRL,(int) 'S', wxID_HIGHEST+25);
	entries[1].Set(wxACCEL_CTRL,(int) 'G', wxID_HIGHEST+26);
	entries[2].Set(wxACCEL_NORMAL,WXK_RETURN, wxID_HIGHEST+27);
	entries[3].Set(wxACCEL_CTRL,(int) 'I', wxID_HIGHEST+28);
	entries[4].Set(wxACCEL_NORMAL,WXK_DELETE, wxID_HIGHEST+29);
	wxAcceleratorTable accel(5, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+25 , wxEVT_MENU, wxCommandEventHandler( dPersonaje::OnClickExportar ));
	Connect( wxID_HIGHEST+26 , wxEVT_MENU, wxCommandEventHandler( dPersonaje::OnClickExportar ));
	Connect( wxID_HIGHEST+27 , wxEVT_MENU, wxCommandEventHandler( dPersonaje::OnClickAplicar ));
	Connect( wxID_HIGHEST+28 , wxEVT_MENU, wxCommandEventHandler( dPersonaje::OnClickAgregar ));
	Connect( wxID_HIGHEST+29 , wxEVT_MENU, wxCommandEventHandler( dPersonaje::OnApretarSupr ));
	
	
	m_partida=p;
	pos=posc;
	
	
	int tam=P.TamInv();
	it=tam;
	std::vector<int> equipados;
	for(int i=0;i<tam;i++) { 
		Item I=P.MostrarItem(i);
		m_Personaje.AgregarInv(I);
		m_Inventario->Append(std_to_wx(I.ObtenerNombre()));
		bool Equip=I.Equipado();
		if(Equip){ 
			I.EquiparToggle();
			equipados.push_back(i);
			m_Personaje.AgregarInv(I);
			m_Personaje.RestarStatsDeItem(I);
			P.RestarStatsDeItem(I);
		}
	}
	for(int i=0;i<equipados.size();i++) { 
		m_Inventario->Check(equipados[i],true);
		m_Personaje.BorrarItem(equipados[i]);
		m_Personaje.OrdenarAlph();
	}

	int Tam=m_Inventario->GetCheckedItems(W);
	for(int i=0;i<Tam;i++) {
		int pos = W.Item(i);
		Item I=m_Personaje.MostrarItem(pos);
		m_Personaje.RestarStatsDeItem(I);
	}
	W.empty();
	
	m_Nombre->SetLabel(std_to_wx(P.ObtenerNombre()));
	m_Nivel->SetValue(std_to_wx(std::to_string(P.ObtenerNivel())));
	m_EXP->SetValue(std_to_wx(std::to_string(P.ObtenerXP())));
	for(size_t i=0;i<spins.size();i++) { 
		spins[i]->SetValue(P.ObtenerStat(i));
	}
	m_Detalle->SetLabel(std_to_wx(P.ObtenerDetalle()));
	
	Actualizacion();

	Show();
}

dPersonaje::~dPersonaje() {
	
}



//FUNCIONES PRIVADAS

void dPersonaje::Actualizacion(){
	/*
	Actualiza los valores totales del personaje por cada item que se encuentre
	tildado en su inventario. 
	Primero los deja en 0 tanto visual como en sus stats, luego vuelve 
	a sumarlas mientras comprueba los tildados.
	*/
	m_Personaje.ResetStat();
	for(int i=0;i<textos.size();i++) { 
		textos[i]->SetLabel("0");
	}
	int Tam=m_Inventario->GetCheckedItems(W);
	for(int i=0;i<Tam;i++) { 
		int pos = W.Item(i);
		Item I=m_Personaje.MostrarItem(pos);
		m_Personaje.SumarStatsDeItem(I);
		for(int i=0;i<textos.size();i++) { 
			wxString Stat;
			if(i<spins.size()){
				Stat.Printf("%.2f",m_Personaje.ObtenerStat(i)+spins[i]->GetValue()); textos[i]->SetLabel(Stat);
			} else {
				Stat.Printf("%.2f",m_Personaje.ObtenerStat(i)); textos[i]->SetLabel(Stat);
			}
		}
	}
	W.empty();
	
}

void dPersonaje::GuardarCambios(){
	/*
	Guarda las stats sumadas de los items en la stat base, toggea los items
	tildados.
	*/
	m_Personaje.NombrarPersonaje(wx_to_std(m_Nombre->GetValue()));
	m_Personaje.ModificarNivel(m_Nivel->GetValue());
	m_Personaje.ModificarXP(m_EXP->GetValue());
	for(size_t i=0;i<spins.size();i++) { 
		m_Personaje.ModificarStat(i,((spins[i]->GetValue()))+m_Personaje.ObtenerStat(i));
	}
	m_Personaje.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	int Tam=m_Inventario->GetCheckedItems(W);
	for(int i=0;i<Tam;i++) {
		int pos = W.Item(i);
		Item I=m_Personaje.MostrarItem(pos);
		I.EquiparToggle();
		m_Personaje.BorrarItem(pos);
		m_Personaje.AgregarInv(I);
		m_Personaje.OrdenarAlph();
	}
	W.empty();
}


// BOTONES DE LA VENTANA

void dPersonaje::OnClickAplicar( wxCommandEvent& event )  {
	/* Guarda al personaje dentro del vector de partida. */
	this->GuardarCambios();
	m_partida->EliminarPersonaje(pos);
	m_partida->AgregarPersonaje(m_Personaje);
	EndModal(1);
}

void dPersonaje::OnClickAgregar( wxCommandEvent& event )  {
	/*
	Abre la ventana dInventario para sacar un item, si se retorna uno, se guarda
	el mismo dentro del vector inventario del personaje.
	*/
	dInventario Inv(this, m_Personaje, m_partida);
	Inv.SetIcon(wxIcon("imagenes\\agregar.ico",wxBITMAP_TYPE_ICO));
	int val=Inv.ShowModal();
	if(val==1){
		Item I=m_Personaje.MostrarItem(it);
		m_Inventario->Append(std_to_wx(I.ObtenerNombre()));
		it++;
	}
	m_Personaje.OrdenarAlph();
}

void dPersonaje::OnClickBorrar( wxCommandEvent& event )  {
	/* Borra un item del inventario y ordena el mismo. */
	if(m_Inventario->GetSelection()==wxNOT_FOUND){
		wxMessageBox(wxT("No es posible borrar un item sin\nhaber seleccionado uno previamente."),wxT("Error"),wxICON_ERROR);
	} else {
		int pos = m_Inventario->GetSelection();
		m_Inventario->Delete(pos);
		m_Personaje.BorrarItem(pos);
		m_Personaje.OrdenarAlph();
		it--;
		Actualizacion();
	}
}

void dPersonaje::OnClickExportar( wxCommandEvent& event )  {
	/* Exporta al personaje con las stats e items actuales. */
	wxFileDialog exportarPersonaje(this,wxT("Exportar personaje"),".\\datos",m_Nombre->GetValue()+".per","Archivos PER (*.per)|*.per",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarPersonaje.ShowModal()==wxID_OK){
		this->GuardarCambios();
		m_Personaje.Exportar(wx_to_std(exportarPersonaje.GetPath()));
	}
}


// TILDADO DE ITEM EN INVENTARIO

void dPersonaje::OnCheckListInventario( wxCommandEvent& event )  {
	/* Actualiza los datos si un item es equipado. */
	Actualizacion();
}


// ATAJO DE MOUSE

void dPersonaje::OnCheckListPersonaje( wxCommandEvent& event )  {
	/*
	Abre la ventana dItem al hacer doble-click en un item para poder editarlo.
	Si retorna un item, este se agrega a la lista, se borra la version vieja y 
	se ordena el inventario.
	*/
	int pos = m_Inventario->GetSelection();
	Item I=m_Personaje.MostrarItem(pos);
	dItem ItemMod(this,m_partida,I,pos,false);
	ItemMod.SetIcon(GetIcon());
	if(ItemMod.ShowModal()==1){
		m_Inventario->Delete(pos);
		m_Inventario->Append(std_to_wx(I.ObtenerNombre()));
	}
	m_Personaje.BorrarItem(pos);
	m_Personaje.AgregarInv(I);
	m_Personaje.OrdenarAlph();
	Actualizacion();
}

// ATAJOS DE TECLADO

void dPersonaje::OnApretarSupr( wxCommandEvent& event ){
	/*
	Si hay un item del inventario seleccionado, lo borra.
	*/
	if (m_Inventario->HasFocus()){
		int pos = m_Inventario->GetSelection();
		if(pos!=wxNOT_FOUND){
			m_Inventario->Delete(pos);
			m_partida->EliminarItem(pos);
			m_Personaje.BorrarItem(pos);
			m_Personaje.OrdenarAlph();
			it--;
			Actualizacion();
			if(m_Inventario->GetSelection()!=wxNOT_FOUND) m_Inventario->SetSelection(pos); else m_Inventario->SetSelection(pos-1);
		}
	} else event.Skip();
}

void dPersonaje::OnApretarTecla( wxKeyEvent& event )  {
	/*
	Este evento se encarga de procesar atajos de teclado que son muy sencillos
	como para crearles eventos propios, ya que lo único que hacen es seleccionar
	un objeto de wx diferente.
	*/
	switch (event.GetKeyCode()){
	case (int) 'D': if(event.ControlDown()){ m_Detalle->SetFocus(); m_Detalle->SetSelection(-1,-1);} else event.Skip(); break;	// CTRL+D
	case (int) 'W': if(event.ControlDown()){ m_EXP->SetFocus(); m_EXP->SetSelection(-1,-1);} else event.Skip(); break;			// CTRL+W
	case (int) 'N': if(event.ControlDown()){ m_Nombre->SetFocus(); m_Nombre->SetSelection(-1,-1);} else event.Skip(); break;	// CTRL+N
	case (int) 'Q': if(event.ControlDown()){ m_Nivel->SetFocus(); m_Nivel-> SetSelection(-1,-1);} else event.Skip(); break;		// CTRL+Q
	default: event.Skip(); break;
	}
}


// ACTUALIZAR VENTANA

void dPersonaje::OnSpinCtrlPersonaje( wxSpinDoubleEvent& event )  {
	/* Actualiza los valores totales luego de modificar una stat base. */
	Actualizacion();
}

// RUEDITAS

/*
Cada evento de ruedita modifica el valor del wxSpinCtrlDouble en el que el
cursor se encuentre posicionado de acuerdo al movimiento de dicha rueda
(hacia arriba suma, hacia abajo resta).
*/

void dPersonaje::OnRueditaEXP( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		m_EXP->SetValue(m_EXP->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		m_EXP->SetValue(m_EXP->GetValue()+1);
	}
}

void dPersonaje::OnRueditaVida( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[0]->SetValue(spins[0]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[0]->SetValue(spins[0]->GetValue()+1);
	}
}

void dPersonaje::OnRueditaDef( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[1]->SetValue(spins[1]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[1]->SetValue(spins[1]->GetValue()+1);
	}
}

void dPersonaje::OnRueditaFuerza( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[2]->SetValue(spins[2]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[2]->SetValue(spins[2]->GetValue()+1);
	}
}

void dPersonaje::OnRueditaAgi( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[3]->SetValue(spins[3]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[3]->SetValue(spins[3]->GetValue()+1);
	}
}

void dPersonaje::OnRueditaResM( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[4]->SetValue(spins[4]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[4]->SetValue(spins[4]->GetValue()+1);
	}
}

void dPersonaje::OnRueditaInte( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[5]->SetValue(spins[5]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[5]->SetValue(spins[5]->GetValue()+1);
	}
}

void dPersonaje::OnRueditaMana( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		spins[6]->SetValue(spins[6]->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		spins[6]->SetValue(spins[6]->GetValue()+1);
	}
}


