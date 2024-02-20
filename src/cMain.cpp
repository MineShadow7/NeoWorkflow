#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Starting Program Window", wxPoint(30, 30), wxSize(800, 600))
{
    btn = new wxButton*[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    nField = new int[nFieldWidth * nFieldHeight];

    for(int x = 0; x < nFieldWidth; x++){
        for(int y = 0; y < nFieldHeight; y++){
            btn[y*nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
            grid->Add(btn[y*nFieldWidth + x], 1, wxEXPAND | wxALL);

            btn[y*nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
            nField[y*nFieldWidth + x] = 0;
        }
    }

    this->SetSizer(grid);
    grid->Layout();
    // m_btn1 = new wxButton(this, 10001, "Click Me", wxPoint(10, 10), wxSize(150, 50));
    // m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
    // m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

cMain::~cMain(){
    delete[]btn;
}

void cMain::OnButtonClicked(wxCommandEvent &evt){
    //m_list1->AppendString(m_txt1->GetValue());

    // Get coordinate of button in field array
    int x = (evt.GetId() - 10000) % nFieldWidth;
    int y = (evt.GetId() - 10000) / nFieldHeight;

    if(bFirstClick){
        int mines = 30;
        while(mines){
            int rx = rand() % nFieldWidth;
            int ry = rand() % nFieldHeight;

            if(nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y){
                nField[ry * nFieldWidth + rx] = -1;
                mines--;
            }
        }
        bFirstClick = false;
    }
    // Disable button after clicked. MineSweeper.
    btn[y*nFieldWidth + x]->Enable(false);

    // Check if clicked a mine.
    if(nField[y*nFieldWidth + x] == -1){
        wxMessageBox("You got the bomb! It's game over.. GGs...");
        
        //Reset the game
        bFirstClick = true;
        for(int x = 0; x < nFieldWidth; x++){
            for(int y = 0; y < nFieldHeight; y++){
                nField[y * nFieldWidth + x] = 0;
                btn[y * nFieldWidth + x]->SetLabel("");
                btn[y * nFieldWidth + x]->Enable(true);
            }
        }

    }
    else
    {
        // Count neighbouring mines
        int mine_count = 0;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if(x + i >= 0 && x + i < nFieldWidth && y + j >= 0 && y + j < nFieldHeight){
                    if(nField[(y + j) * nFieldWidth + (x + i)] == -1)
                        mine_count++;
                }
            }
        }

        // If counted mines, then update buttons lables > 0
        if(mine_count > 0){
            btn[y * nFieldWidth + x]->SetLabel(std::to_string(mine_count));
        }
    }
    evt.Skip();
}