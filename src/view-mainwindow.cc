//===================================================================================================================
//
// view-mainwindow.cc -- This is the main window implementation
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


#include "view-mainwindow.h"

#include <QDesktopWidget>
#include <QMenuBar>
#include <QMenu>


//
// -- The Factory class needs will create a new instance
//    --------------------------------------------------
MainWindow *MainWindow::Factory(void)
{
    QDesktopWidget desktop;
    MainWindow *rv = new MainWindow();

    rv->move(0, 0);
    rv->setFixedSize((int)(desktop.width() * 0.85), (int)(desktop.height() * 0.85));
    rv->CreateMenus();

    return rv;
}


//
// -- Create the menus for the applicaiton
//    ------------------------------------
void MainWindow::CreateMenus(void)
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
    helpMenu->addAction(tr("&About"));
}
