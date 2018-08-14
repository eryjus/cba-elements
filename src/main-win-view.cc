//===================================================================================================================
//
// view/main-win-view.cc -- This is the main window implementation
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


//
// -- Enable logging from this file
//    -----------------------------
#define ENABLE_LOG


//
// -- Application includes; framework includes; and then std C++ includes
//    -------------------------------------------------------------------
#include "logger.h"
#include "about-controller.h"
#include "main-win-view.h"
#include "main-win-controller.h"
#include "about-view.h"

#include <QDesktopWidget>
#include <QMenuBar>
#include <QMenu>
#include <QStackedWidget>


//
// -- The Factory class needs will create a new instance
//    --------------------------------------------------
MainWindowView *MainWindowView::Factory(MainWindowController *ctl)
{
    QDesktopWidget desktop;
    MainWindowView *rv = new MainWindowView();

    rv->move(0, 0);
    rv->setFixedSize((int)(desktop.width() * 0.85), (int)(desktop.height() * 0.85));
    rv->CreateMenus(ctl);
    rv->setCentralWidget(new QStackedWidget());

    return rv;
}


//
// -- Create the menus for the applicaiton
//    ------------------------------------
void MainWindowView::CreateMenus(MainWindowController *ctl)
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("&New"));
    fileMenu->addAction(tr("&Save"));
    fileMenu->addAction(tr("&Close"));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("&Quit"));

    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(tr("&Search"));
    editMenu->addSeparator();
    editMenu->addAction(tr("&Preferences"));

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    ctl->AboutAction() = new QAction(tr("&About"), this);
    helpMenu->addAction(ctl->AboutAction());
}
