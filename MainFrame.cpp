//
// Created by m2 on 2/28/21.
//

#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/notebook.h>


MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Title") {
    wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                      wxSP_BORDER | wxSP_LIVE_UPDATE);
    wxSplitterWindow *right_splitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                      wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxPanel *left = new wxPanel(splitter);
    wxPanel *right = new wxPanel(right_splitter);
    wxPanel *bottom = new wxPanel(right_splitter);

    left->SetBackgroundColour(wxColour(20, 13, 48));
    right->SetBackgroundColour(wxColour(20, 13, 48));
    bottom->SetBackgroundColour(wxColour(20, 13, 48));

    right_splitter->SetMinimumPaneSize(100);
    right_splitter->SplitHorizontally(right, bottom);
    right_splitter->SetSashGravity(0.3);

    splitter->SetMinimumPaneSize(200);

    splitter->SplitVertically(left, right_splitter);

    wxTreeCtrl* tree_ctrl = new wxTreeCtrl(left, wxID_ANY, wxDefaultPosition, wxSize(250, 850));
    tree_ctrl->SetBackgroundColour(wxColour(23, 18, 36));
    tree_ctrl->SetForegroundColour(wxColour(255,255,255));
    wxTreeItemId root_id = tree_ctrl->AddRoot("root_1");
    tree_ctrl->AppendItem(root_id, "node_1");

    wxTreeItemId child_id = tree_ctrl->AppendItem(root_id, "node_2");
    tree_ctrl->AppendItem(child_id, "child_1");

    tree_ctrl->AppendItem(root_id, "node_3");
    tree_ctrl->AppendItem(root_id, "node_4");
    tree_ctrl->AppendItem(root_id, "node_5");
    tree_ctrl->AppendItem(root_id, "node_6");
    tree_ctrl->AppendItem(root_id, "node_7");
    tree_ctrl->AppendItem(root_id, "node_8");
    tree_ctrl->AppendItem(root_id, "node_9");
    tree_ctrl->AppendItem(root_id, "node_10");

    tree_ctrl->ExpandAll();

    wxTextCtrl* text_ctrl = new wxTextCtrl(right, wxID_ANY, "db.getCollection('').find({})", wxDefaultPosition, wxSize(250, 200), wxTE_MULTILINE);
    text_ctrl->SetBackgroundColour(wxColour(23, 18, 36));
    text_ctrl->SetForegroundColour(wxColour(255,255,255));
    wxTextCtrl* text_ctrl_bottom = new wxTextCtrl(bottom, wxID_ANY, "Query results", wxDefaultPosition, wxSize(250, 200), wxTE_MULTILINE | wxTE_READONLY);
    text_ctrl_bottom->SetBackgroundColour(wxColour(23, 18, 36));
    text_ctrl_bottom->SetForegroundColour(wxColour(255,255,255));

    wxDialog* dialog = new wxDialog(this, wxID_ANY, "Connections", wxDefaultPosition, wxDefaultSize);
    dialog->Show();

    
    wxNotebook* notebook = new wxNotebook(dialog, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    
    wxPanel *connection_panel = new wxPanel(notebook);
    connection_panel->SetBackgroundColour(wxColour(23, 18, 36));
    connection_panel->SetForegroundColour(wxColour(255,255,255));

    wxPanel *authentication_panel = new wxPanel(notebook);
    authentication_panel->SetBackgroundColour(wxColour(23, 18, 36));
    authentication_panel->SetForegroundColour(wxColour(255,255,255));
    
    notebook->AddPage(connection_panel, "Connection", true);
    notebook->AddPage(authentication_panel, "Authentication");

    wxStaticText* connection_name_label = new wxStaticText(connection_panel, wxID_ANY, "Name", wxDefaultPosition, wxDefaultSize);
    connection_name_label->SetForegroundColour(wxColour(255,255,255));
    wxTextCtrl* connection_name_input = new wxTextCtrl(connection_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);

    wxBoxSizer* connection_panel_main_sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* connection_panel_sizer = new wxBoxSizer(wxHORIZONTAL);
    connection_panel_sizer->Add(connection_name_label, 0, wxALL, 5);
    connection_panel_sizer->Add(connection_name_input, 0, wxALL, 5);

    connection_panel_main_sizer->Add(connection_panel_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    connection_panel->SetSizer(connection_panel_sizer);
}

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("bla");
}

void MainFrame::OnHello(wxCommandEvent &event) {
    wxMessageBox("box");
}