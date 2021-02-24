#include "vPersonaje.h"

vPersonaje::vPersonaje(wxWindow *parent, Partida *p) : Ventana_personaje(parent) {
	m_partida=p;
	Show();

}

vPersonaje::~vPersonaje() {
	
}

void vPersonaje::GuardarCambios(){
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

void vPersonaje::OnClickAplicar( wxCommandEvent& event )  {

	this->GuardarCambios();
	m_partida->AgregarPersonaje(m_Personaje);
	Close(true);
	
}

void vPersonaje::OnClickExportar( wxCommandEvent& event )  {
	wxFileDialog exportarPersonaje(this,wxT("Exportar personaje"),".\\datos",m_Nombre->GetValue()+".per","Archivos PER (*.per)|*.per",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(exportarPersonaje.ShowModal()==wxID_OK){
		this->GuardarCambios();
		m_Personaje.Exportar(wx_to_std(exportarPersonaje.GetPath()));
	}
	
}

void vPersonaje::OnClickAgregar( wxCommandEvent& event )  {
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

void vPersonaje::OnCheckListInventario( wxCommandEvent& event )  {
	Actualizacion();
}

void vPersonaje::Actualizacion(){
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

void vPersonaje::OnSpinCtrlPersonaje( wxSpinDoubleEvent& event )  {
	Actualizacion();
}

