#include "cMain.h"

cMain::cMain(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxGridSizer *gSizer1;
	gSizer1 = new wxGridSizer(0, 1, 0, 0);

	m_grid2 = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	m_grid2->CreateGrid(4, 5);
	m_grid2->EnableEditing(true);
	m_grid2->EnableGridLines(true);
	m_grid2->EnableDragGridSize(false);
	m_grid2->SetMargins(0, 0);

	// Columns
	m_grid2->EnableDragColMove(false);
	m_grid2->EnableDragColSize(true);
	m_grid2->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Rows
	m_grid2->EnableDragRowSize(true);
	m_grid2->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

	// Label Appearance

	// Cell Defaults
	m_grid2->SetDefaultCellAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
	gSizer1->Add(m_grid2, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	gSizer1->Add(0, 0, 0, wxALL, 5);

	m_button2 = new wxButton(this, wxID_ANY, wxT("Fill with Numbers"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_button2, 0, wxALIGN_BOTTOM | wxTOP | wxRIGHT | wxLEFT, 5);

	m_button3 = new wxButton(this, wxID_ANY, wxT("Fill with zeros"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_button3, 0, wxALL, 5);

	m_button4 = new wxButton(this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_button4, 0, wxALIGN_RIGHT | wxALIGN_BOTTOM | wxALL, 5);

	this->SetSizer(gSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_button2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::onNumbersClick), NULL, this);
	m_button3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::onZerosClick), NULL, this);
	m_button4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnButtonExitClick), NULL, this);
}

cMain::~cMain()
{
	// Disconnect Events
	m_button2->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::onNumbersClick), NULL, this);
	m_button3->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::onZerosClick), NULL, this);
	m_button4->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnButtonExitClick), NULL, this);
}

void cMain::OnButtonExitClick(wxCommandEvent &event)
{
	this->Close();
	// Example of usage of dynamically built libraries in func
	Stack<int> *st = new Stack<int>(2);
	st->push(3);
	std::cout << st->pop() << std::endl;

	event.Skip();
}

void cMain::onZerosClick(wxCommandEvent &event)
{
	m_grid2->ClearGrid();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m_grid2->SetCellValue({i, j}, "0");
		}
	}
	event.Skip();
}

void cMain::onNumbersClick(wxCommandEvent &event)
{
	int min = 1;
	int max = 25;
	m_grid2->ClearGrid();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int x = rand() % (max - min + 1) + min;
			m_grid2->SetCellValue({i, j}, std::to_string(x));
		}
	}
	event.Skip();
}
