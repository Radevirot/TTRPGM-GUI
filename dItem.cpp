#include "dItem.h"

dItem::dItem(wxWindow *parent, Partida *p, Item Im, int posc) : Dialogo_item(parent) {
	CrearTablaDeAtajos();
	
	m_partida=p;
	I=Im; pos=posc;
	
	ObtenerInformacion(I);
	Show();
}

dItem::dItem(wxWindow *parent, Partida *p, Item &Im, int posc, bool Uso) : Dialogo_item(parent) {
	CrearTablaDeAtajos();
	
	m_partida=p;
	I=Im; pos=posc;
	Ims=&Im; booleano=Uso;
	
	ObtenerInformacion(Im);
	Show();
}

void dItem::CrearTablaDeAtajos(){
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
	m_NombreItem->SetLabel(std_to_wx(Ite.ObtenerNombre()));
	m_Cantidad->SetValue(std_to_wx(std::to_string(Ite.ObtenerCant())));
	for(size_t i=0;i<vect.size();i++) { 
		vect[i]->SetValue(std_to_wx(std::to_string(Ite.ObtenerStat(i)))); 
	}
	m_Detalle->SetLabel(std_to_wx(Ite.ObtenerDetalle())); 
	m_Descripcion->SetLabel(std_to_wx(Ite.ObtenerDesc()));
}

void dItem::ActualizarInformacion(Item &Ite){
	Ite.NombrarItem(wx_to_std(m_NombreItem->GetValue()));
	Ite.ModificarCant(m_Cantidad->GetValue());
	for(size_t i=0;i<vect.size();i++) { 
		Ite.ModificarStat(i,(vect[i]->GetValue()));
	}
	Ite.ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	Ite.ModificarDesc(wx_to_std(m_Descripcion->GetValue()));
}


//BOTONES DE EDICION DE ITEM

void dItem::OnClickAplicar( wxCommandEvent& event )  {

	if(booleano){
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
	wxFileDialog exportarItem(this,wxT("Exportar item"),".\\datos",m_NombreItem->GetValue()+".ite","Archivos ITE (*.ite)|*.ite",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarItem.ShowModal()==wxID_OK){
		ActualizarInformacion(I);
		I.Exportar(wx_to_std(exportarItem.GetPath()));
	}
}

dItem::~dItem() {
	
}
