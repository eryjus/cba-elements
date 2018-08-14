//===================================================================================================================
//
// about-controller.h -- This is the near-trivial About dialog box
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-10  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __ABOUT_CONTROLLER_H__
#define __ABOUT_CONTROLLER_H__


#define ENABLE_LOG


//
// -- Application includes; framework includes
//    ----------------------------------------
#include "logger.h"
#include "about-view.h"

#include <QAction>


//
// -- This is the about dialog box controller
//    ---------------------------------------
class AboutController : public QAction {
    //
    // -- This will be populated when the first controller is created
    //    -----------------------------------------------------------
    private: static AboutController *controller;


    //
    // -- This is the actual view we will use
    //    -----------------------------------
    private: static AboutView *view;


    //
    // -- This is a factory method
    //    ------------------------
    public: static AboutController *Factory(QObject *parent);


    //
    // -- This is a private constructor
    //    -----------------------------
    private: AboutController(QObject *parent) : QAction(parent) {}

    public: virtual ~AboutController() {};


    public: void Show(void) { LOG("Show(): ", view); view->exec(); LOG("Done exec-ing"); }
};


#endif
