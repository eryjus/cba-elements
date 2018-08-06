//===================================================================================================================
//
// main.cc -- The main entry point for the elements applicaiton
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-27  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#include "model-elements.h"

#define ENABLE_LOG
#include "logger.h"

#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include <QApplication>

#include "view-mainwindow.h"

//
// -- The main entry point
//    --------------------
int main(int argc, char *argv[])
{
    LOG("Welcome to the elements maintenance program");
    LOG("  (c) 2018 Adam Clark (hobbyos@eryjus.com)");

    try {
        ModelElements *elements = ModelElements::Factory();
        elements->CreateTable();
    } catch (sql::SQLException &e) {
        LOG_ERR("Catch All Error!: ", e.what());
        return EXIT_FAILURE;
    }

    QApplication app(argc, argv);

    MainWindow *mainWin = MainWindow::Factory();
    mainWin->show();

    int rv = app.exec();
    DisconnectDatabase();

    return rv;
}
