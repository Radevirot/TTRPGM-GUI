#include "vCombate.h"

vCombate::vCombate(wxWindow *parent, Partida *p) : Ventana_combate(parent) {
	/*
	Constructor de la ventana Combate, se le ingresan como par�metros un puntero
	a la ventana padre y otro a la partida actual.
	Carga y muestra formulas de combate y la lista de personajes atacantes y receptores.
	*/
	m_partida=p;
	m_Formula->Append(std_to_wx("1. (50+D�*4*MULT)-(DFN*2)"));
	m_Formula->Append(std_to_wx("2. (D�*0.5*MULT)-(DFN*0.25)"));
	m_Formula->Append(std_to_wx("3. (FRZ*MULT)-(DFN*0.5)"));
	m_Formula->Append(std_to_wx("4. (FRZ+D�*0.5*MULT)-(DFN*0.25)"));
	m_Formula->Append(std_to_wx("5. (FRZ+D�*0.5*MULT)-(DFN*0.5)"));
	m_Formula->Append(std_to_wx("6. (50+INT*4*MULT)-(RM*2)"));
	m_Formula->Append(std_to_wx("7. (INT*0.5*MULT)-(RM*0.25)"));
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
	std::string DanioSt=std::to_string(DanioR);
	DanioSt.erase(DanioSt.end()-4,DanioSt.end());
	m_DanioProvo->SetLabel(std_to_wx(DanioSt));
	
	m_Atacante->Clear();
	m_Receptor->Clear();
	int Tam=m_partida->ObtenerTamPersonajes();
	for(int i=0;i<Tam;i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		Seleccion(P);
	}
	
	PosUAt=posatc;
	PosURc=posrecp;
	Personaje PA=m_partida->ObtenerPersonaje(PosUAt);
	
	m_Atacante->SetSelection(PosUAt);
	Seleccion(PA, true);
	if(Tam>1){ 
		Personaje PR=m_partida->ObtenerPersonaje(PosURc);
		m_Receptor->SetSelection(PosURc);
		Seleccion(PR, false);
	}else{ 
		Personaje PR=m_partida->ObtenerPersonaje(0);
		m_Receptor->SetSelection(0);
		Seleccion(PR, false);
	}
}


// ACTUALIZAR VENTANA

void vCombate::OnActivetaCombate( wxActivateEvent& event )  {
	m_Atacante->Clear();
	m_Receptor->Clear();
	int Tam=m_partida->ObtenerTamPersonajes();
	for(int i=0;i<Tam;i++) { 
		Personaje P=m_partida->ObtenerPersonaje(i);
		Seleccion(P);
	}
	Personaje PA=m_partida->ObtenerPersonaje(PosUAt);
	
	m_Atacante->SetSelection(PosUAt);
	Seleccion(PA, true);
	if(Tam>1){ 
		Personaje PR=m_partida->ObtenerPersonaje(PosURc);
		m_Receptor->SetSelection(PosURc);
		Seleccion(PR, false);
	}else{ 
		Personaje PR=m_partida->ObtenerPersonaje(0);
		m_Receptor->SetSelection(0);
		Seleccion(PR, false);
	}
}

void vCombate::OnChoiceAtq( wxCommandEvent& event )  {
	int posatc=m_Atacante->GetSelection();
	PosUAt=posatc;
	int Atq=m_Atacante->GetSelection();
	Personaje PAT=m_partida->ObtenerPersonaje(Atq);
	Seleccion(PAT, true);
	
}

void vCombate::OnChoiceRecp( wxCommandEvent& event )  {
	int posrecp=m_Receptor->GetSelection();
	PosURc=posrecp;
	int Rcp=m_Receptor->GetSelection();
	Personaje PRC=m_partida->ObtenerPersonaje(Rcp);
	Seleccion(PRC, false);
}

void vCombate::Seleccion(Personaje Ps, bool AtRc){
	std::string Fuerza=std::to_string(Ps.ObtenerStat(2)),Vida=std::to_string(Ps.ObtenerStat(0)),Danio=std::to_string(Ps.ObtenerStat(7)),Defen=std::to_string(Ps.ObtenerStat(1)),Inte=std::to_string(Ps.ObtenerStat(5)),ResM=std::to_string(Ps.ObtenerStat(4));
	Fuerza.erase(Fuerza.end()-4,Fuerza.end()); Vida.erase(Vida.end()-4,Vida.end()); Danio.erase(Danio.end()-4,Danio.end()); Defen.erase(Defen.end()-4,Defen.end()); Inte.erase(Inte.end()-4,Inte.end()); ResM.erase(ResM.end()-4,ResM.end());
	
	
	if(AtRc){
		m_Atacante->SetToolTip(std_to_wx((Ps.ObtenerNombre()+"\nPV: "+Vida+" - FRZ: "+Fuerza+"\nD�: "+Danio+" - DFN: "+Defen+"\nINT: "+Inte+" - RM: "+ResM)));
	}else{
		m_Receptor->SetToolTip(std_to_wx((Ps.ObtenerNombre()+"\nPV: "+Vida+" - FRZ: "+Fuerza+"\nD�: "+Danio+" - DFN: "+Defen+"\nINT: "+Inte+" - RM: "+ResM)));
	}
}

void vCombate::Seleccion(Personaje Prs){
	std::string Vida=std::to_string(Prs.ObtenerStat(0));
	Vida.erase(Vida.end()-4,Vida.end());
	m_Atacante->Append(std_to_wx((Prs.ObtenerNombre())+" - PV: "+Vida));
	m_Receptor->Append(std_to_wx((Prs.ObtenerNombre())+" - PV: "+Vida));
}


//ATAJOS DE TECLADO Y MOUSE

void vCombate::OnApretarTecla( wxKeyEvent& event )  {
	
	switch (event.GetKeyCode()){
	case WXK_SHIFT: m_ModificarPV->SetValue(true); break;
	case WXK_CONTROL: manteniendoControl=true; break;
	case WXK_ALT: manteniendoAlt=true; break;
	case WXK_ESCAPE: Close(true); break;
	}
	
}

void vCombate::OnLevantarTecla( wxKeyEvent& event )  {
	switch (event.GetKeyCode()){
	case WXK_SHIFT: m_ModificarPV->SetValue(false); break;
	case WXK_CONTROL: manteniendoControl=false; break;
	case WXK_ALT: manteniendoAlt=false; break;
	}
}

void vCombate::OnScrollFormula( wxMouseEvent& event )  {

	if(event.GetWheelRotation()<0){
		m_Formula->SetSelection(m_Formula->GetSelection()+1);
	} else if (event.GetWheelRotation()>0){
		if((m_Formula->GetSelection()-1)!=wxNOT_FOUND) m_Formula->SetSelection(m_Formula->GetSelection()-1);
	}
}

void vCombate::OnScrollMult( wxMouseEvent& event )  {

	if(event.GetWheelRotation()>0){
		m_Multiplicador->SetValue(m_Multiplicador->GetValue()+1);
	} else if (event.GetWheelRotation()<0){
		m_Multiplicador->SetValue(m_Multiplicador->GetValue()-1);
	}

}

void vCombate::OnScrollAtq( wxMouseEvent& event )  {

	if(event.GetWheelRotation()<0){
		m_Atacante->SetSelection(m_Atacante->GetSelection()+1);
	} else if (event.GetWheelRotation()>0){
		if((m_Atacante->GetSelection()-1)!=wxNOT_FOUND) m_Atacante->SetSelection(m_Atacante->GetSelection()-1);
	}
	Personaje PAt=m_partida->ObtenerPersonaje(m_Atacante->GetSelection()); Seleccion(PAt,true);
}

void vCombate::OnScrollRecp( wxMouseEvent& event )  {

	if(event.GetWheelRotation()<0){
		m_Receptor->SetSelection(m_Receptor->GetSelection()+1);
	} else if (event.GetWheelRotation()>0){
		if((m_Receptor->GetSelection()-1)!=wxNOT_FOUND) m_Receptor->SetSelection(m_Receptor->GetSelection()-1);
	}
	Personaje PRe=m_partida->ObtenerPersonaje(m_Receptor->GetSelection()); Seleccion(PRe,false);
}

void vCombate::OnClickVentana( wxMouseEvent& event )  {
	if(event.AltDown()){
		Personaje PAt=m_partida->ObtenerPersonaje(m_Atacante->GetSelection()),PRe=m_partida->ObtenerPersonaje(m_Receptor->GetSelection());
		int aux=m_Atacante->GetSelection();
		m_Atacante->SetSelection(m_Receptor->GetSelection());
		m_Receptor->SetSelection(aux);
		Seleccion(PAt,false); Seleccion(PRe,true);
	}
}

