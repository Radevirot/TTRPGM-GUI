#include <wx/image.h>
#include "Application.h"
#include "vPersonaje.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	vPersonaje *win = new vPersonaje(NULL);
	win->Show();
	return true;
}

