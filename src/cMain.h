#pragma once
#include <wx/wx.h>

#define WinMain main

class cMain : public wxFrame
{
public:
    cMain();
    ~cMain();

public:
    int nFieldWidth = 10;
    int nFieldHeight = 10;
    wxButton **btn;
    int *nField = nullptr;
    bool bFirstClick = true;

    // wxButton *m_btn1 = nullptr;
    // wxTextCtrl *m_txt1 = nullptr;
    // wxListBox *m_list1 = nullptr;

    void OnButtonClicked(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};