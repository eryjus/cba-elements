//===================================================================================================================
//
// view-mainwindow.h -- This is the main window portion of the View components if the MVC design model
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


#ifndef __VIEW_MAINWINDOW_H__
#define __VIEW_MAINWINDOW_H__


#include <QMainWindow>


//
// -- This is the main window class of the `cba-elements` applicaiton
//    ---------------------------------------------------------------
class MainWindow : public QMainWindow {
    // -- This is the static Factory() method
    public: static MainWindow *Factory(void);

    // -- The constructor is protected to precent independent instantiation
    protected: MainWindow() : QMainWindow() {};

    // -- Create the menus for the application
    private: void CreateMenus(void);
};


#endif

