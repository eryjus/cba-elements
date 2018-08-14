//===================================================================================================================
//
// src/about-controller.cc -- The controller for the about dialog box
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-14  Initial   0.0.0   ADCL  Initial version
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
#include "about-controller.h"


//
// -- This is a pointer to the controller, since we will reference this
//    -----------------------------------------------------------------
AboutController *AboutController::controller = NULL;


//
// -- This is a pointer to the instantiated view, so that we only ever create one
//    ---------------------------------------------------------------------------
AboutView *AboutController::view = NULL;


//
// -- This is a factory method to make sure we create a proper About Controller
//    -------------------------------------------------------------------------
AboutController *AboutController::Factory(QObject *parent)
{
    LOG("Creating about dialog");

    if (!view) view = new AboutView();
    if (!controller) controller = new AboutController(parent);

    return controller;
}

