///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

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
#include "libraries/lib_stack/stack.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class cMain
///////////////////////////////////////////////////////////////////////////////
class cMain : public wxFrame
{
	private:

	protected:
		wxGrid* m_grid2;
		wxButton* m_button4;
		wxMenuBar* m_menubar1;

		// Virtual event handlers, override them in your derived class
		virtual void OnButtonExitClick( wxCommandEvent& event );


	public:

		cMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 501,323 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~cMain();

};

