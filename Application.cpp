#include <wx/image.h>
#include "Application.h"
#include "vPrincipal.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	vPrincipal *win = new vPrincipal(NULL);
	
	return true;
}

