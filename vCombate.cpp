#include "vCombate.h"

vCombate::vCombate(wxWindow *parent, Partida *p) : Ventana_combate(parent) {
	/*
	Constructor de la ventana Combate, se le ingresan como par�metros un puntero
	a la ventana padre y otro a la partida actual.
	Carga y muestra formulas de combate y la lista de personajes atacantes y receptores.
	*/
	m_partida=p;
	m_Formula->Append(std_to_wx("(50+(D�*4)*MULT)-(DFN*2)"));
	m_Formula->Append(std_to_wx("(((D�*0.5)*MULT)-(DFN*0.25))"));
	m_Formula->Append(std_to_wx("(((FRZ)*MULT)-(DFN*0.5))"));
	m_Formula->Append(std_to_wx("((FRZ+(D�*0.5)*MULT)-(DFN*0.25))"));
	m_Formula->Append(std_to_wx("((FRZ+(D�*0.5)*MULT)-(DFN*0.5))"));
	m_Formula->SetSelection(0);
	Show();
}

vCombate::~vCombate() {
	
}

// BOTONES
void vCombate::OnClickCerrar( wxCommandEvent& event )  {
	Close(true);
}

void vCombate::OnClickAtacar( wxCommandEvent& event )  {
	int posatc=m_Atacante->GetSelection();
	int posrecp=m_Receptor->GetSelection();
	int Danio=m_partida->Combate(posatc,posrecp,m_Formula->GetSelection(),m_Multiplicador->GetValue(),m_ModificarPV->IsChecked());
	m_DanioProvo->SetLabel(std_to_wx(std::to_string(Danio)));
	
	m_Atacante->Clear();
	m_Receptor->Clear();
	int Tam=m_partida->ObtenerTamPersonajes();
	for(int i=0;i<Tam;i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		std::string Vida=std::to_string(P.ObtenerStat(0));
		Vida.erase(Vida.end()-4,Vida.end());
		std::string Danio=std::to_string(P.ObtenerStat(7));
		Danio.erase(Danio.end()-4,Danio.end());
		m_Atacante->Append(std_to_wx((P.ObtenerNombre())+" - Vida: "+Vida+" - Da�o: "+Danio));
		m_Receptor->Append(std_to_wx((P.ObtenerNombre())+" - Vida: "+Vida+" - Da�o: "+Danio));
		
	}
	PosUAt=posatc;
	PosURc=posrecp;
	m_Atacante->SetSelection(PosUAt);
	if(Tam>1){ 
		m_Receptor->SetSelection(PosURc);
	}else{ 
		m_Receptor->SetSelection(0);
	}
}

// ACTUALIZAR
void vCombate::OnActivetaCombate( wxActivateEvent& event )  {
	m_Atacante->Clear();
	m_Receptor->Clear();
	int Tam=m_partida->ObtenerTamPersonajes();
	for(int i=0;i<Tam;i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		std::string Vida=std::to_string(P.ObtenerStat(0));
		Vida.erase(Vida.end()-4,Vida.end());
		std::string Danio=std::to_string(P.ObtenerStat(7));
		Danio.erase(Danio.end()-4,Danio.end());
		m_Atacante->Append(std_to_wx((P.ObtenerNombre())+" - Vida: "+Vida+" - Da�o: "+Danio));
		m_Receptor->Append(std_to_wx((P.ObtenerNombre())+" - Vida: "+Vida+" - Da�o: "+Danio));
	}
	m_Atacante->SetSelection(PosUAt);
	if(Tam>1){ 
		m_Receptor->SetSelection(PosURc);
	}else{ 
		m_Receptor->SetSelection(0);
	}
}

