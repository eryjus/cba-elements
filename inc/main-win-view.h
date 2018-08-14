//===================================================================================================================
//
// view/main-win-view.h -- This is the main window portion of the View components if the MVC design model
//
// We use Qt4 for this implementation.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-05  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __MAIN_WIN_VIEW_H__
#define __MAIN_WIN_VIEW_H__


class MainWindowController;


//
// -- Application includes; framework includes
//    ----------------------------------------
#include <QMainWindow>


//
// -- This is the main window class of the `cba-elements` applicaiton
//    ---------------------------------------------------------------
class MainWindowView : public QMainWindow {
    //
    // -- This is the static Factory() method
    //    -----------------------------------
    public: static MainWindowView *Factory(MainWindowController *ctl);


    //
    // -- The constructor is protected to precent independent instantiation
    //    -----------------------------------------------------------------
    protected: MainWindowView() : QMainWindow() {};

    public: virtual ~MainWindowView() {};


    //
    // -- Create the menus for the application
    //    ------------------------------------
    private: void CreateMenus(MainWindowController *ctl);
};


#endif

