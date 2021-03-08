//
// Created by m2 on 2/28/21.
//

#ifndef WX_M_CLIENT_APP_H
#define WX_M_CLIENT_APP_H

#include <wx/wx.h>
#include "MainFrame.h"

class App : public wxApp {
    public:
        virtual bool OnInit();
    private:
        MainFrame* main_frame = nullptr;
};


#endif //WX_M_CLIENT_APP_H
