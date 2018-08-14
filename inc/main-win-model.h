//===================================================================================================================
//
// model/main-win-model.h -- This is the main window model for the application -- responsible for the database conn.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-09  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __MAIN_WIN_MODEL_H__
#define __MAIN_WIN_MODEL_H__


//
// -- Application includes; framework includes
//    ----------------------------------------
#include "elements.h"


//
// -- A forward class declaration
//    ---------------------------
class MainWindowController;


//
// -- The main window model -- the database connection
//    ------------------------------------------------
class MainWindowModel {
    //
    // -- We need the controller to be able to access these members and methods
    //    ---------------------------------------------------------------------
    friend class MainWindowController;


    //
    // -- This is the element database connection
    //    ---------------------------------------
    private: static ModelElements *elem;


    //
    // -- This is the constructor for the Model, open a connection to the database
    //    ------------------------------------------------------------------------
    private: MainWindowModel();


    //
    // -- This is the destructor for the Model, closing the database connection
    //    ---------------------------------------------------------------------
    private: ~MainWindowModel();
};


#endif
