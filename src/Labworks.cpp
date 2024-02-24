// Labworks.cpp: определяет точку входа для приложения.
//
#include "Labworks.h"

#define WinMain main

wxIMPLEMENT_APP(cApp);

cApp::cApp(){

}

cApp::~cApp(){

}

bool cApp::OnInit()
{
    wxWindow* parent = nullptr;
    const int window_ID = wxID_ANY;
    const wxString window_Title = "Main Program Window";
    const wxPoint& pos = {-1, -1};
    const wxSize& size = {511, 346};
    long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL;
    m_frame1 = new cMain(nullptr, window_ID, window_Title, pos, size, wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    m_frame1->Show();
    
    return true;
}
// We can use WxWidgets for native cross-platform UI.
// Todo: Add UI.
