// Labworks.h : Класс объявления приложения cApp.
// cApp является основным классом приложения.

#include <wx/wx.h>
#include "cMain.h"

class cApp : public wxApp
{
public:
    cApp();
    ~cApp();

private:
    cMain *m_frame1 = nullptr;

public:
    virtual bool OnInit();
};
