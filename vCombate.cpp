#include "vCombate.h"

vCombate::vCombate(wxWindow *parent, Partida *p) : Ventana_combate(parent) {
	m_partida=p;
	m_Formula->Append(std_to_wx("(50+(DÑ*4)*MULT)-(DFN*2)"));
	m_Formula->Append(std_to_wx("(((DÑ*0.5)*MULT)-(DFN*0.25))"));
	m_Formula->Append(std_to_wx("(((FRZ)*MULT)-(DFN*0.5))"));
	m_Formula->Append(std_to_wx("((FRZ+(DÑ*0.5)*MULT)-(DFN*0.25))"));
	m_Formula->Append(std_to_wx("((FRZ+(DÑ*0.5)*MULT)-(DFN*0.5))"));
	m_Formula->SetSelection(0);
	int Tam=m_partida->ObtenerTamPersonajes();
	for(int i=0;i<Tam;i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		m_Atacante->Append(std_to_wx((P.ObtenerNombre())+"-"+std::to_string(P.ObtenerStat(0))));
		m_Receptor->Append(std_to_wx((P.ObtenerNombre())+"-"+std::to_string(P.ObtenerStat(0))));
	}
	m_Atacante->SetSelection(0);
	if(Tam>1){ 
		m_Receptor->SetSelection(1);
	}else{ 
		m_Receptor->SetSelection(0);
	}
	Show();
}

vCombate::~vCombate() {
	
}

void vCombate::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

void vCombate::OnClickAtacar( wxCommandEvent& event )  {
	int posatc=m_Atacante->GetSelection();
	int posrecp=m_Receptor->GetSelection();
	int Danio=m_partida->Combate(posatc,posrecp,m_Formula->GetSelection(),m_Multiplicador->GetValue(),m_ModificarPV->IsChecked());
	m_DanioProvo->SetLabel(std_to_wx(std::to_string(Danio)));
}


