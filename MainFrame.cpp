//
// Created by m2 on 2/28/21.
//

#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/textctrl.h>

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Title") {
    wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                      wxSP_BORDER | wxSP_LIVE_UPDATE);
    wxSplitterWindow *right_splitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                      wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxPanel *left = new wxPanel(splitter);
    wxPanel *right = new wxPanel(right_splitter);
    wxPanel *bottom = new wxPanel(right_splitter);

    left->SetBackgroundColour(wxColour(27, 38, 59));
    right->SetBackgroundColour(wxColour(65, 90, 119));
    bottom->SetBackgroundColour(wxColour(119, 141, 169));

    right_splitter->SetMinimumPaneSize(100);
    right_splitter->SplitHorizontally(right, bottom);
    right_splitter->SetSashGravity(0.3);

    splitter->SetMinimumPaneSize(200);

    splitter->SplitVertically(left, right_splitter);

    wxTreeCtrl* tree_ctrl = new wxTreeCtrl(left, wxID_ANY, wxDefaultPosition, wxSize(250, 200));
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
    wxTextCtrl* text_ctrl_bottom = new wxTextCtrl(bottom, wxID_ANY, "Query results", wxDefaultPosition, wxSize(250, 200), wxTE_MULTILINE | wxTE_READONLY);
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