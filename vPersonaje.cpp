#include "vPersonaje.h"
#include "Personaje.h"
#include "Partida.h"
#include "string_conv.h"
#include "dInventario.h"

vPersonaje::vPersonaje(wxWindow *parent, Partida *p, bool tipo) : Ventana_personaje(parent) {
	m_partida=p;
	Personaje *per=new Personaje;
	m_Personaje=per;
	m_tipo=tipo;
	if(tipo){
		m_aplicarcambios->SetLabel(std_to_wx("Crear"));
		this->SetTitle(std_to_wx("TTRPGM: Creación de Item"));
	}else{
		m_aplicarcambios->SetLabel(std_to_wx("Aplicar cambios"));
		this->SetTitle(std_to_wx("TTRPGM: Modificación de Item"));
	}
	Show();

}

vPersonaje::~vPersonaje() {
	
}

void vPersonaje::OnClickAplicar( wxCommandEvent& event )  {
	m_Personaje->NombrarPersonaje(wx_to_std(m_Nombre->GetValue()));
	m_Personaje->ModificarNivel(m_Nivel->GetValue());
	m_Personaje->ModificarXP(m_EXP->GetValue());
	m_Personaje->ModificarStat(0,(m_PVb->GetValue()));
	m_Personaje->ModificarStat(1,(m_DFNb->GetValue()));
	m_Personaje->ModificarStat(2,(m_FRZb->GetValue()));
	m_Personaje->ModificarStat(3,(m_AGLb->GetValue()));
	m_Personaje->ModificarStat(4,(m_RMb->GetValue()));
	m_Personaje->ModificarStat(5,(m_INTb->GetValue()));
	m_Personaje->ModificarStat(6,(m_MNb->GetValue()));
	m_Personaje->ModificarDetalle(wx_to_std(m_Detalle->GetValue()));
	m_partida->AgregarPersonaje(*m_Personaje);
	if(m_tipo){
		Close(true);
	}
}

void vPersonaje::OnClickExportar( wxCommandEvent& event )  {
	event.Skip();
}

void vPersonaje::OnClickAgregar( wxCommandEvent& event )  {
	dInventario Inv(this, m_Personaje, m_partida);
	int val=Inv.ShowModal();
	if(val==1){
		Item I=m_Personaje->MostrarItem(i);
		m_Inventario->Append(std_to_wx(I.ObtenerNombre()));
		i++;
	}
}

void vPersonaje::OnCheckListInventario( wxCommandEvent& event )  {
	m_Personaje->ResetStat();
	m_DN->SetLabel(std_to_wx(std::to_string(0)));
	m_RNG->SetLabel(std_to_wx(std::to_string(0)));
	m_PNT->SetLabel(std_to_wx(std::to_string(0)));
	m_BLQ->SetLabel(std_to_wx(std::to_string(0)));
	int Tam=m_Inventario->GetCheckedItems(W);
	for(int i=0;i<Tam;i++) { 
		int pos = W.Item(i);
		Item I=m_Personaje->MostrarItem(pos);
		m_Personaje->SumarStatsDeItem(I);
		m_DN->SetLabel(std_to_wx(std::to_string(m_Personaje->ObtenerStat(7))));
		m_RNG->SetLabel(std_to_wx(std::to_string(m_Personaje->ObtenerStat(8))));
		m_PNT->SetLabel(std_to_wx(std::to_string(m_Personaje->ObtenerStat(9))));
		m_BLQ->SetLabel(std_to_wx(std::to_string(m_Personaje->ObtenerStat(10))));
	}
	W.empty();
}

