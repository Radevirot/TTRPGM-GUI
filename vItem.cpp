#include "vItem.h"


vItem::vItem(wxWindow *parent, Partida *p) : Ventana_item(parent) {
	
	
	wxAcceleratorEntry entries[2];
	entries[0].Set(wxACCEL_CTRL|wxACCEL_ALT, WXK_SPACE, wxID_HIGHEST+1);
	entries[1].Set(wxACCEL_CTRL,WXK_CONTROL,wxID_HIGHEST+2);
	wxAcceleratorTable accel(2, entries);
	SetAcceleratorTable(accel);
	Connect( wxID_HIGHEST+1, wxEVT_MENU, wxCommandEventHandler( vItem::OnCtrlAltEspacio ));
	
//	std::vector<wxSpinCtrlDouble*> vect{m_PuntosVida,m_Defenza,m_Fuerza,m_Agilidad,m_ResistenciaMagica,
//										m_Inteligencia,m_Mana,m_Danio,m_Rango,m_Punteria,m_Bloqueo};
	
	
	m_partida=p;
	Show();
}

vItem::~vItem() {
	
}




Item vItem::CargarInformacion(){
	Item I;
	I.NombrarItem(wx_to_std(m_NombreItem->GetValue()));
	I.ModificarCant(m_Cantidad->GetValue());
	
	for(size_t i=0;i<vect.size();i++) { 
		I.ModificarStat(i,(vect[i]->GetValue()));
	}
//	I.ModificarStat(0,(m_PuntosVida->GetValue()));
//	I.ModificarStat(1,(m_Defenza->GetValue()));
//	I.ModificarStat(2,(m_Fuerza->GetValue()));
//	I.ModificarStat(3,(m_Agilidad->GetValue()));
//	I.ModificarStat(4,(m_ResistenciaMagica->GetValue()));
//	I.ModificarStat(5,(m_Inteligencia->GetValue()));
//	I.ModificarStat(6,(m_Mana->GetValue()));
//	I.ModificarStat(7,(m_Danio->GetValue()));
//	I.ModificarStat(8,(m_Rango->GetValue()));
//	I.ModificarStat(9,(m_Punteria->GetValue()));
//	I.ModificarStat(10,(m_Bloqueo->GetValue()));
	I.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	I.ModificarDesc(wx_to_std(m_Descripcion->GetValue()));
	return I;
}

void vItem::OnClickAplicar( wxCommandEvent& event )  {
	
	Item I=this->CargarInformacion();
	m_partida->AgregarItem(I);
	m_partida->OrdenarIAlph();
	Close(true);

}

void vItem::OnClickExportar( wxCommandEvent& event )  {
	wxFileDialog exportarItem(this,wxT("Exportar item"),".\\datos",m_NombreItem->GetValue()+".ite","Archivos ITE (*.ite)|*.ite",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarItem.ShowModal()==wxID_OK){
		Item I=this->CargarInformacion();
		I.Exportar(wx_to_std(exportarItem.GetPath()));
	}
}

void vItem::OnCtrlAltEspacio( wxCommandEvent& event ){
	wxMessageBox(wxT("Apretaste CTRL+ALT+ESPACIO"));
}


void vItem::OnActivarItem( wxActivateEvent& event )  {
/*	manteniendoControl=false;*/
	event.Skip();
}

void vItem::OnApretarTecla( wxKeyEvent& event )  {
//	switch (event.GetKeyCode()){
//	case WXK_CONTROL: manteniendoControl=true; break;
//	}
	event.Skip();
}

void vItem::OnLevantarTecla( wxKeyEvent& event )  {
	/*if(event.GetKeyCode()==WXK_CONTROL) manteniendoControl=false; else event.Skip();*/
	event.Skip();
}

void vItem::OnRueditaDanio( wxMouseEvent& event )  {
	if(event.GetWheelRotation()<0){
		m_Danio->SetValue(m_Danio->GetValue()-1);
	} else if (event.GetWheelRotation()>0){
		m_Danio->SetValue(m_Danio->GetValue()+1);
	}
}

