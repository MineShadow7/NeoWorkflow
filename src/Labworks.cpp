// Labworks.cpp: определяет точку входа для приложения.
//
#include "Labworks.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp(){

}

cApp::~cApp(){

}

bool cApp::OnInit()
{
    wxWindow* parent = nullptr;
    const wxSize& size = {800, 600};
    long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL;
    m_frame1 = new cMain(nullptr, wxID_ANY, "Title",  {-1, -1}, size, wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    m_frame1->Show();
    
    return true;
}
// We can use WxWidgets for native cross-platform UI.
// Todo: Add UI.
