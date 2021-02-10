#include <wx/image.h>
#include "Application.h"
#include "vDados.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	vDados *win = new vDados(NULL);
	win->Show();
	return true;
}

