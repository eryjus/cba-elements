//===================================================================================================================
//
// src/about-view.cc -- The view for the about dialog box
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-14  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#include "about-view.h"


//
// -- The constructor for the About Dialog Box
//    ----------------------------------------
AboutView::AboutView(void) : QMessageBox()
{
    setText("(c) 2018 -- Adam Clark\nPlease report any bugs to hobbyos@eryjus.com");
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

