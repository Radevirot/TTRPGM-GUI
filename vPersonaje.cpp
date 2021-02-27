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
	m_PVt->SetLabel(std_to_wx(std::to_string(0)));
	m_DFNt->SetLabel(std_to_wx(std::to_string(0)));
	m_FRZt->SetLabel(std_to_wx(std::to_string(0)));
	m_AGLt->SetLabel(std_to_wx(std::to_string(0)));
	m_RMt->SetLabel(std_to_wx(std::to_string(0)));
	m_INTt->SetLabel(std_to_wx(std::to_string(0)));
	m_MNt->SetLabel(std_to_wx(std::to_string(0)));
	m_DN->SetLabel(std_to_wx(std::to_string(0)));
	m_RNG->SetLabel(std_to_wx(std::to_string(0)));
	m_PNT->SetLabel(std_to_wx(std::to_string(0)));
	m_BLQ->SetLabel(std_to_wx(std::to_string(0)));
	int Tam=m_Inventario->GetCheckedItems(W);
	for(int i=0;i<Tam;i++) { 
		int pos = W.Item(i);
		Item I=m_Personaje.MostrarItem(pos);
		m_Personaje.SumarStatsDeItem(I);
		std::string Stat=std::to_string(m_Personaje.ObtenerStat(0)+m_PVb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_PVt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(1)+m_DFNb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_DFNt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(2)+m_FRZb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_FRZt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(3)+m_AGLb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_AGLt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(4)+m_RMb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_RMt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(5)+m_INTb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_INTt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(6)+m_MNb->GetValue());
		Stat.erase(Stat.end()-4,Stat.end());
		m_MNt->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(7));
		Stat.erase(Stat.end()-4,Stat.end());
		m_DN->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(8));
		Stat.erase(Stat.end()-4,Stat.end());
		m_RNG->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(9));
		Stat.erase(Stat.end()-4,Stat.end());
		m_PNT->SetLabel(std_to_wx(Stat));
		Stat=std::to_string(m_Personaje.ObtenerStat(10));
		Stat.erase(Stat.end()-4,Stat.end());
		m_BLQ->SetLabel(std_to_wx(Stat));
	}
	W.empty();
}

void vPersonaje::GuardarCambios(){
	/*
	Guarda las stats sumadas de los items en la stat base, toggea los items
	tildados.
	*/
	m_Personaje.NombrarPersonaje(wx_to_std(m_Nombre->GetValue()));
	m_Personaje.ModificarNivel(m_Nivel->GetValue());
	m_Personaje.ModificarXP(m_EXP->GetValue());
	m_Personaje.ModificarStat(0,((m_PVb->GetValue()))+m_Personaje.ObtenerStat(0));
	m_Personaje.ModificarStat(1,((m_DFNb->GetValue()))+m_Personaje.ObtenerStat(1));
	m_Personaje.ModificarStat(2,((m_FRZb->GetValue()))+m_Personaje.ObtenerStat(2));
	m_Personaje.ModificarStat(3,((m_AGLb->GetValue()))+m_Personaje.ObtenerStat(3));
	m_Personaje.ModificarStat(4,((m_RMb->GetValue()))+m_Personaje.ObtenerStat(4));
	m_Personaje.ModificarStat(5,((m_INTb->GetValue()))+m_Personaje.ObtenerStat(5));
	m_Personaje.ModificarStat(6,((m_MNb->GetValue()))+m_Personaje.ObtenerStat(6));
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

