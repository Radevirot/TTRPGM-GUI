#include "vPersonaje.h"

vPersonaje::vPersonaje(wxWindow *parent, Partida *p) : Ventana_personaje(parent) {
	/*
	Constructor de la ventana Personaje, se le ingresan como parámetros un puntero
	a la ventana padre y otro a la partida actual.
	Guarda el puntero de la partida actual en el privado y muestra la ventana.
	*/
	m_partida=p;
	Show();

}

vPersonaje::~vPersonaje() {
	
}



//FUNCIONES PRIVADAS

void vPersonaje::Actualizacion(){
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

void vPersonaje::GuardarCambios(){
	/*
	Guarda las stats sumadas de los items en la stat base, togglea los items
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


//BOTONES DE CREACION DE PERSONAJE 

void vPersonaje::OnClickAplicar( wxCommandEvent& event )  {
	/*
	Guarda al personaje dentro del vector de partida.
	*/

	this->GuardarCambios();
	m_partida->AgregarPersonaje(m_Personaje);
	Close(true);
	
}

void vPersonaje::OnClickExportar( wxCommandEvent& event )  {
	/*
	Exporta al personaje con las stats e items actuales.
	*/
	wxFileDialog exportarPersonaje(this,wxT("Exportar personaje"),".\\datos",m_Nombre->GetValue()+".per","Archivos PER (*.per)|*.per",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarPersonaje.ShowModal()==wxID_OK){
		this->GuardarCambios();
		m_Personaje.Exportar(wx_to_std(exportarPersonaje.GetPath()));
	}
	
}

void vPersonaje::OnClickAgregar( wxCommandEvent& event )  {
	/*
	Abre la ventana dInventario para sacar un item, si se retorna uno, se guarda
	el mismo dentro del vector inventario del personaje.
	*/
	dInventario Inv(this, m_Personaje, m_partida);
	int val=Inv.ShowModal();
	if(val==1){
		Item I=m_Personaje.MostrarItem(it);
		m_Inventario->Append(std_to_wx(I.ObtenerNombre()));
		it++;
	}
	m_Personaje.OrdenarAlph();
}

void vPersonaje::OnClickBorrar( wxCommandEvent& event )  {
	/*
	Borra un item del inventario y ordena la misma.
	*/
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


//TILDADO DE ITEM EN INVENTARIO

void vPersonaje::OnCheckListInventario( wxCommandEvent& event )  {
	/*
	Actualiza los datos si un item es equipado.
	*/
	Actualizacion();
}


//ATAJO DE MOUSE

void vPersonaje::OnCheckListPersonaje( wxCommandEvent& event )  {
	/*
	Abre la ventana dItem al hacer doble-click en un item para poder editarlo.
	Si retorna un item, este se agrega a la lista, se borra la version vieja y 
	se ordena el inventario.
	*/
	int pos = m_Inventario->GetSelection();
	Item I=m_Personaje.MostrarItem(pos);
	dItem ItemMod(this,m_partida,I,pos,false);
	wxBitmap logo(wxT("imagenes/logo.bmp"), wxBITMAP_TYPE_ANY);
	wxIcon icon;
	icon.CopyFromBitmap(logo);
	ItemMod.SetIcon(icon);
	if(ItemMod.ShowModal()==1){
		m_Inventario->Delete(pos);
		m_Inventario->Append(std_to_wx(I.ObtenerNombre()));
	}
	m_Personaje.BorrarItem(pos);
	m_Personaje.AgregarInv(I);
	m_Personaje.OrdenarAlph();
	Actualizacion();
}


//ACTUALIZAR VENTANA

void vPersonaje::OnSpinCtrlPersonaje( wxSpinDoubleEvent& event )  {
	/*
	Actualiza los valores totales luego de modificar una stat base.
	*/
	Actualizacion();
}

