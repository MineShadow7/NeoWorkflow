// -*- C++ -*-
//
// generated by wxGlade 1.0.4 on Sun Feb 18 00:52:43 2024
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include <wx/wx.h>
#include "cMain.h"

// begin wxGlade: ::extracode
// end wxGlade


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: MyFrame::MyFrame
    SetSize(wxSize(400, 300));
    SetTitle(wxT("frame"));
    panel_1 = new wxPanel(this, wxID_ANY);
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    sizer_1->Add(0, 0, 0, 0, 0);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    sizer_1->Add(sizer_2, 1, wxALIGN_RIGHT|wxFIXED_MINSIZE, 0);
    button_1 = new wxButton(panel_1, wxID_ANY, wxT("button_1"));
    button_1->SetMinSize(wxSize(100, 50));
    sizer_2->Add(button_1, 100, wxALIGN_CENTER_VERTICAL, 0);
    button_2 = new wxButton(panel_1, wxID_ANY, wxT("button_2"));
    button_2->SetMinSize(wxSize(100, 50));
    sizer_2->Add(button_2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 10);
    
    panel_1->SetSizer(sizer_1);
    Layout();
    // end wxGlade
}

