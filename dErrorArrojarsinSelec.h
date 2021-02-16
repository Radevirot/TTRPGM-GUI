#ifndef DERRORARROJARSINSELEC_H
#define DERRORARROJARSINSELEC_H
#include "wxfb_project.h"
#include "string_conv.h"
#include <string>

class dErrorArrojarsinSelec : public Dialogo_ErrorArrojarsinSelec {
	
private:
	
protected:
	void OnClickAceptar( wxCommandEvent& event )  override;
	
public:
	dErrorArrojarsinSelec(wxWindow *parent,int tipo);
	~dErrorArrojarsinSelec();
};

#endif

