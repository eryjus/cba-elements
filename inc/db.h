//===================================================================================================================
//
// db.h -- This is the basic interface for working on a database for OpCodes.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-24  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================

#include "mysql_connection.h"

#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h"


#include <string>


//-------------------------------------------------------------------------------------------------------------------
// Global Database Connection
//-------------------------------------------------------------------------------------------------------------------
extern sql::Connection *connection;


//-------------------------------------------------------------------------------------------------------------------
// Function prototypes
//-------------------------------------------------------------------------------------------------------------------


//
// -- Set a Database-level connection parameters
//    ------------------------------------------
void SetConnection(const std::string &h, const std::string &pt, const std::string &d, 
        const std::string &u, const std::string &pw);


//
// -- Actually start a conection to the database
//    ------------------------------------------
void ConnectDatabase(void);


//
// -- Close an open connection to the database
//    ----------------------------------------
void DisconnectDatabase(void);


//
// -- With an open connection, set the default schema for the connection
//    ------------------------------------------------------------------
void SetSchema(const std::string &s);


//-------------------------------------------------------------------------------------------------------------------
// Inline functions
//-------------------------------------------------------------------------------------------------------------------


//
// -- Set the schema to be none
//    -------------------------
static inline void SetSchema(void) { SetSchema(""); }
