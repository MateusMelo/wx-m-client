//
// Created by m2 on 2/28/21.
//

#ifndef WX_M_CLIENT_MAINFRAME_H
#define WX_M_CLIENT_MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
    public:
        MainFrame();
    private:
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
};


#endif //WX_M_CLIENT_MAINFRAME_H
