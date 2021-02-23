#ifndef APPLICATION_H
#define APPLICATION_H
#include "Partida.h"
#include "vPrincipal.h"
#include "vPartida.h"

#include <wx/app.h>
#include <wx/image.h>

class Application : public wxApp {
private:
	Partida *m_partida;
public:
	virtual bool OnInit();
};

#endif
