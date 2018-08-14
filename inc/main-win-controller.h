//===================================================================================================================
//
// controller/main-win-controller.h -- This is the main window controller definition for the application
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-09  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __MAIN_WIN_CONTROLLER_H__
#define __MAIN_WIN_CONTROLLER_H__


class AboutController;


//
// -- Application includes; framework includes
//    ----------------------------------------
#include "main-win-model.h"
#include "main-win-view.h"

#include <QApplication>
#include <QMainWindow>


//
// -- The main window controller will encapsulate the QApplication object and control the main program loop
//    -----------------------------------------------------------------------------------------------------
class MainWindowController : private QApplication {
    Q_OBJECT

    //
    // -- This is the database connection
    //    -------------------------------
    private: static MainWindowModel *model;


    //
    // -- If we have already created a window controller, this will be populated
    //    ----------------------------------------------------------------------
    private: static MainWindowController *instance;


    //
    // -- If we have already created a view, this will be populated
    //    ---------------------------------------------------------
    private: static MainWindowView *view;


    //
    // -- The about controller, which we will communicate with to display the about dialog box
    //    ------------------------------------------------------------------------------------
    private: static AboutController *about;


    //
    // -- This is the factory method for a new object
    //    -------------------------------------------
    public: static MainWindowController *Factory(int argc, char *argv[]);


    //
    // -- This is the main contructor -- private to prevent inheriting
    //    ------------------------------------------------------------
    private: MainWindowController(int argc, char *argv[]);


    public: ~MainWindowController() {};


    //
    // -- We need an access method to the application program loop, wrapped in some setup and tear down
    //    ---------------------------------------------------------------------------------------------
    public: int Run(void);


    //
    // -- Here we will have all the individual QActions that can be triggered
    //    -------------------------------------------------------------------
    private: QAction *aboutAction;
    public: QAction *&AboutAction(void) { return aboutAction; }


    //
    // -- And then we put the slots that can be leveraged by the actions above
    //    --------------------------------------------------------------------
    private slots: void About(void);
};


#endif
