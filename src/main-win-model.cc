//===================================================================================================================
//
// model/main-win-model.cc -- The main database connection
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-09  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


//
// -- Enable logging from this file
//    -----------------------------
#define ENABLE_LOG


//
// -- Application includes; framework includes; and then std C++ includes
//    -------------------------------------------------------------------
#include "main-win-model.h"
#include "elements.h"
#include "logger.h"

#include <cstdlib>
#include <stdexcept>


//
// -- This is the Elements Model
//    --------------------------
ModelElements *MainWindowModel::elem = NULL;


//
// -- The constructor for the Model, which will open a connection and check for the table existence
//    ---------------------------------------------------------------------------------------------
MainWindowModel::MainWindowModel()
{
    if (elem) return;

    // Open the database and init the tables
    try {
        elem = ModelElements::Factory();
        elem->CreateTable();
    } catch (sql::SQLException &e) {
        LOG_ERR("Catch All Error!: ", e.what());
        exit(EXIT_FAILURE);
    }
}


//
// -- The class desctructor; closes the database connection
//    -----------------------------------------------------
MainWindowModel::~MainWindowModel()
{
    DisconnectDatabase();
}

