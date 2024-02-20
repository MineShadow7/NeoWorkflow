// Labworks.cpp: определяет точку входа для приложения.
//

#include <wx/wx.h>
#include <wx/image.h>
#include "cMain.h"


class cMain: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(cMain)

bool cMain::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame* frame = new MyFrame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
