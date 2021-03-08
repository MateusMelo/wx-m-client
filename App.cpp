//
// Created by m2 on 2/28/21.
//

#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    main_frame = new MainFrame();
    main_frame->Show(true);

    return true;
}