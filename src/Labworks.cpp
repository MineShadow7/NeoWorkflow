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
    m_frame1 = new cMain();
    m_frame1->Show();
    
    return true;
}
// We can use WxWidgets for native cross-platform UI.
// Todo: Add UI.
