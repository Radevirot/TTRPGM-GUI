#ifndef APPLICATION_H
#define APPLICATION_H
#include "Partida.h"

#include <wx/app.h>

class Application : public wxApp {
private:
	Partida *m_partida;
public:
	virtual bool OnInit();
};

#endif
