//===================================================================================================================
//
// db.cc -- The implementation of the database interface.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-24  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#include "db.h"

#include <stdexcept>


//-------------------------------------------------------------------------------------------------------------------
// Some local static variables (not thread safe!)
//-------------------------------------------------------------------------------------------------------------------
static std::string host = "";
static std::string port = "";
static std::string db = "";
static std::string user = "";
static std::string pwd = "";

sql::Connection *connection = NULL;


//-------------------------------------------------------------------------------------------------------------------
// SetConnection() -- Set the connection parameters
//-------------------------------------------------------------------------------------------------------------------
void SetConnection(const std::string &h, const std::string &pt, const std::string &d,
        const std::string &u, const std::string &pw)
{
    host = h;
    port = pt;
    db = d;
    user = u;
    pwd = pw;
}


//-------------------------------------------------------------------------------------------------------------------
// ConnectDatabase() -- Make a connection to the database server; SetConnection must be called first
//-------------------------------------------------------------------------------------------------------------------
void ConnectDatabase(void)
{
    if (host == "") host = "localhost";
    if (port == "") port = "3306";
    if (user == "") user = "eryjus";

    connection = get_driver_instance()->connect(host + ":" + port, user, pwd);
    if (!connection) throw new std::runtime_error("Unable to make a database connection");

    if (db != "") SetSchema(db);
}


//--------------------------------------------------------------------------------------------------------------
// DisconnectDatabase() -- Disconnect from a database server
//-------------------------------------------------------------------------------------------------------------------
void DisconnectDatabase(void)
{
    if (!connection) return;
    connection->close();
    connection = NULL;
}


//------------------------------------------------------------------------------------------------------------------
// SetSchema() -- Set the conenction to use a database schema, creating it if it does not already exist
//-------------------------------------------------------------------------------------------------------------------
void SetSchema(const std::string &s)
{
    if (s != "") db = s;
    if (!connection) throw new std::runtime_error("Database connection not made");

    sql::Statement *stmt = connection->createStatement();
    if (!stmt) throw new std::runtime_error("Unable to create a new SQL statement");

    stmt->execute("CREATE DATABASE IF NOT EXISTS " + db);
    connection->setSchema(db);
    delete stmt;
}

