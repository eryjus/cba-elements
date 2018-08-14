//===================================================================================================================
//
// src/main-win-controller.cc -- The main entry point and main window for the elements applicaiton
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-27  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


//
// -- Enable logging from this file
//    -----------------------------
#define ENABLE_LOG


//
// -- Application includes; framework includes; and then std C++ includes
//    -------------------------------------------------------------------
#include "logger.h"
#include "elements.h"
#include "about-controller.h"
#include "main-win-view.h"
#include "main-win-controller.h"

#include <QApplication>

#include <iostream>
#include <cstdlib>
#include <stdexcept>


//
// -- A static attribute to hold the Model pointer
//    --------------------------------------------
MainWindowModel *MainWindowController::model = NULL;


//
// -- A static member to hold the already created window; NULL if not created
//    -----------------------------------------------------------------------
MainWindowController *MainWindowController::instance = NULL;


//
// -- A static attribute to hold the main window view
//    -----------------------------------------------
MainWindowView *MainWindowController::view = NULL;


//
// -- A static attribute to hold the about dialog
//    -------------------------------------------
AboutController *MainWindowController::about = NULL;


//
// -- This is the contructor for the MainWindowController class
//    ---------------------------------------------------------
MainWindowController::MainWindowController(int argc, char *argv[]) : QApplication(argc, argv)
{
    if (!model) model = new MainWindowModel();
    if (!view) view = MainWindowView::Factory(this);

    if (!about) {
        about = AboutController::Factory(view);
        connect(aboutAction, SIGNAL(triggered()), this, SLOT(About()));
    }

    view->show();
}


//
// -- This is the factory method for a MainWindowController
//    -----------------------------------------------------
MainWindowController *MainWindowController::Factory(int argc, char *argv[])
{
    if (instance) return instance;

    instance = new MainWindowController(argc, argv);
    return instance;
}


//
// -- Setup to execute the program loop
//    ---------------------------------
int MainWindowController::Run(void)
{
    LOG("Starting the program execution loop");
    return exec();
}


//
// -- Display the About dialog box
//    ----------------------------
void MainWindowController::About(void)
{
    LOG("Trying to display the about dialog box");
    if (about) about->Show();
}


// ==================================================================================================================
// == Here we have the main entry point hand-off from C++
// ==================================================================================================================


//
// -- The main entry point
//    --------------------
int main(int argc, char *argv[])
{
    // Greet in the logs
    LOG("Welcome to the elements maintenance program");
    LOG("  (c) 2018 Adam Clark (hobbyos@eryjus.com)");

    MainWindowController *mainWin = MainWindowController::Factory(argc, argv);
    int rv = mainWin->Run();
    delete mainWin;
    return rv;
}


#include "main-win-controller.moc"
