#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <iostream>
#include <random>
#include "libraries/lib_stack/stack.h"


class cMain : public wxFrame
{
	private:

	protected:
	wxGrid* m_grid2;
	wxButton* m_button2;
	wxButton* m_button3;
	wxButton* m_button4;


	// Virtual event handlers, override them in your derived class
	virtual void onNumbersClick( wxCommandEvent& event );
	virtual void onZerosClick( wxCommandEvent& event );
	virtual void OnButtonExitClick( wxCommandEvent& event );

	public:
	// Default constructor, no need to chage it. If need to add custom parameters, see Labworks.cpp
	cMain(wxWindow* parent, wxWindowID id = wxID_ANY, 
		const wxString& title = wxEmptyString, 
		const wxPoint& pos = wxDefaultPosition, 
		const wxSize& size = wxSize(100, 100), 
		long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);

		~cMain();

};

