//===================================================================================================================
//
// logger.cc -- This is the instance of the logger class to output the results of debugging to an output stream.
//
// This file is adapted from http://www.drdobbs.com/cpp/a-lightweight-logger-for-c/240147505?pgno=1
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-28  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#include "logger.h"


//
// -- This is the logger class that will be used to capture the execution
//    -------------------------------------------------------------------
Logger<FileLogPolicy> logger("debug.log");

