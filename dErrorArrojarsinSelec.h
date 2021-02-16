#ifndef DERRORARROJARSINSELEC_H
#define DERRORARROJARSINSELEC_H
#include "wxfb_project.h"

class dErrorArrojarsinSelec : public Dialogo_ErrorArrojarsinSelec {
	
private:
	
protected:
	void OnClickAceptar( wxCommandEvent& event )  override;
	
public:
	dErrorArrojarsinSelec(wxWindow *parent=NULL);
	~dErrorArrojarsinSelec();
};

#endif

