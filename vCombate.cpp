#include "vCombate.h"

vCombate::vCombate(wxWindow *parent, Partida *p) : Ventana_combate(parent) {
	/*
	Constructor de la ventana Combate, se le ingresan como parámetros un puntero
	a la ventana padre y otro a la partida actual.
	Carga y muestra formulas de combate y la lista de personajes atacantes y receptores.
	*/
	m_partida=p;
	m_Formula->Append(std_to_wx("(50+DÑ*4*MULT)-(DFN*2)"));
	m_Formula->Append(std_to_wx("(DÑ*0.5*MULT)-(DFN*0.25)"));
	m_Formula->Append(std_to_wx("(FRZ*MULT)-(DFN*0.5)"));
	m_Formula->Append(std_to_wx("(FRZ+DÑ*0.5*MULT)-(DFN*0.25)"));
	m_Formula->Append(std_to_wx("(FRZ+DÑ*0.5*MULT)-(DFN*0.5)"));
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
	float DanioR=m_partida->Combate(posatc,posrecp,m_Formula->GetSelection(),m_Multiplicador->GetValue(),m_ModificarPV->IsChecked());
	m_DanioProvo->SetLabel(std_to_wx(std::to_string(DanioR)));
	
	m_Atacante->Clear();
	m_Receptor->Clear();
	int Tam=m_partida->ObtenerTamPersonajes();
	for(int i=0;i<Tam;i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		std::string Vida=std::to_string(P.ObtenerStat(0));
		Vida.erase(Vida.end()-4,Vida.end());
		std::string Danio=std::to_string(P.ObtenerStat(7));
		Danio.erase(Danio.end()-4,Danio.end());
		std::string Defen=std::to_string(P.ObtenerStat(1));
		Defen.erase(Defen.end()-4,Defen.end());
		m_Atacante->Append(std_to_wx(P.ObtenerNombre()));
		m_Receptor->Append(std_to_wx(P.ObtenerNombre()));
		
	}
	PosUAt=posatc;
	PosURc=posrecp;
	Personaje PA=m_partida->ObtenerPersonaje(PosUAt);
	Personaje PR=m_partida->ObtenerPersonaje(PosURc);
	
	m_Atacante->SetSelection(PosUAt);
	Seleccion(PR, true);
	if(Tam>1){ 
		m_Receptor->SetSelection(PosURc);
		Seleccion(PR, false);
	}else{ 
		m_Receptor->SetSelection(0);
		Seleccion(PR, false);
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
		std::string Defen=std::to_string(P.ObtenerStat(1));
		Defen.erase(Defen.end()-4,Defen.end());
		m_Atacante->Append(std_to_wx(P.ObtenerNombre()));
		m_Receptor->Append(std_to_wx(P.ObtenerNombre()));
	}
	Personaje PA=m_partida->ObtenerPersonaje(PosUAt);
	Personaje PR=m_partida->ObtenerPersonaje(PosURc);
	
	m_Atacante->SetSelection(PosUAt);
	Seleccion(PR, true);
	if(Tam>1){ 
		m_Receptor->SetSelection(PosURc);
		Seleccion(PR, false);
	}else{ 
		m_Receptor->SetSelection(0);
		Seleccion(PR, false);
	}
}

void vCombate::OnChoiceAtq( wxCommandEvent& event )  {
	int Atq=m_Atacante->GetSelection();
	Personaje PA=m_partida->ObtenerPersonaje(Atq);
	Seleccion(PA, true);
	
}

void vCombate::OnChoiceRecp( wxCommandEvent& event )  {
	int Rcp=m_Receptor->GetSelection();
	Personaje PR=m_partida->ObtenerPersonaje(Rcp);
	Seleccion(PR, false);
}

void vCombate::Seleccion(Personaje Ps, bool AtRc){
	std::string Vida=std::to_string(Ps.ObtenerStat(0));
	Vida.erase(Vida.end()-4,Vida.end());
	std::string Danio=std::to_string(Ps.ObtenerStat(7));
	Danio.erase(Danio.end()-4,Danio.end());
	std::string Defen=std::to_string(Ps.ObtenerStat(1));
	Defen.erase(Defen.end()-4,Defen.end());
	if(AtRc){
		m_Atacante->SetToolTip(std_to_wx((Ps.ObtenerNombre())+" - PV: "+Vida+" - DÑ: "+Danio+" - DFN: "+Defen));
	}else{
		m_Receptor->SetToolTip(std_to_wx((Ps.ObtenerNombre())+" - PV: "+Vida+" - DÑ: "+Danio+" - DFN: "+Defen));
	}
}
