//===================================================================================================================
//
// model-elements.cc -- This is the data model for the elements for cba.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-26  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#include "elements.h"

#define ENABLE_LOG
#include "logger.h"

#include <iostream>


//
// -- This is a class factory, creating an instance of a ModelElemnets class
//    ----------------------------------------------------------------------
ModelElements *ModelElements::Factory(void)
{
    return new ModelElements();
}


//
// -- Clear the contents of the current record
//    ----------------------------------------
void ModelElements::ClearCurrentRecord(void)
{
    name = "";
    type = "";
    description = "";
    size = 0;
    decimals = 0;
    unsigned_ = false;
    zero_fill = false;
    auto_increment = false;
    char_set = "";
    collate_name = "";
    not_null = false;
    short_description = "";
    default_value = "";
    orig_name = "";
}


//
// -- Check if the table exists
//    -------------------------
bool ModelElements::CheckTableExists(void)
{
    std::string sqlStmt = "                                                \
       SELECT *                                                            \
       FROM information_schema.tables                                      \
       WHERE table_schema = '" + GetSchemaName() + "'                      \
          AND table_name = '" + GetTableName() + "'                        \
    ";

    try {
        sql::Statement *stmt = connection->createStatement();
        sql::ResultSet *res = stmt->executeQuery(sqlStmt);
        bool rv = res->next();

        delete res;
        delete stmt;

        return rv;
    } catch (sql::SQLException &e) {
        LOG_ERR("In Elements::CheckTableExists(): ", e.what(), " (Error Code: ", e.getErrorCode(),
                "; State: ", e.getSQLState(), ")");
        return false;
    }
}


//
// -- Create the table, but only if the table does not exist
//    ------------------------------------------------------
void ModelElements::CreateTable(void)
{
    if (!CheckTableExists()) {
        std::string sqlStmt = "                                                 \
            CREATE TABLE IF NOT EXISTS " + GetQualifiedName() + "               \
            (                                                                   \
                element_name              VARCHAR(64) NOT NULL ,                \
                element_type              VARCHAR(10) ,                         \
                element_description       TINYTEXT ,                            \
                element_szie              INT unsigned ,                        \
                element_decimals          TINYINT unsigned ,                    \
                element_unsigned          TINYINT(1) ,                          \
                element_zero_fill         TINYINT(1) ,                          \
                element_auto_increment    TINYINT(1) ,                          \
                element_char_set          VARCHAR(25) ,                         \
                element_collate_name      VARCHAR(25) ,                         \
                element_not_null          TINYINT(1) ,                          \
                element_short_description VARCHAR(120) NOT NULL ,               \
                element_default_value     VARCHAR(1000) NOT NULL ,              \
                element_create_id         VARCHAR(25) NOT NULL ,                \
                element_create_date_time  TIMESTAMP NOT NULL ,                  \
                element_create_system     VARCHAR(120) NOT NULL ,               \
                element_modify_id         VARCHAR(25) ,                         \
                element_modify_date_time  TIMESTAMP ,                           \
                element_modify_system     VARCHAR(120) ,                        \
                                                                                \
                PRIMARY KEY (element_name)                                      \
            )                                                                   \
        ";

        LOG(sqlStmt);

        sql::Statement *stmt = connection->createStatement();
        stmt->execute(sqlStmt);
        delete stmt;

        LoadTables();
    }
}


//
// -- Insert the current data as a new record into the database
//    ---------------------------------------------------------
bool ModelElements::InsertRecord(void)
{
    bool rv = true;
    sql::Statement *stmt;
    std::string sqlStmt = "                                                 \
        INSERT INTO " + GetQualifiedName() + " VALUES (                     \
            '" + name + "',                                                 \
            '" + type + "',                                                 \
            '" + description + "',                                          \
            " + std::to_string(size) + ",                                   \
            " + std::to_string(decimals) + ",                               \
            " + (unsigned_?"TRUE":"FALSE") + ",                             \
            " + (zero_fill?"TRUE":"FALSE") + ",                             \
            " + (auto_increment?"TRUE":"FALSE") + ",                        \
            '" + char_set + "',                                             \
            '" + collate_name + "',                                         \
            " + (not_null?"TRUE":"FALSE") + ",                              \
            '" + short_description + "',                                    \
            '" + default_value + "',                                        \
            " + GetUser() + ",                                              \
            " + GetNow() + ",                                               \
            " + GetComputer() + ",                                          \
            " + GetUser() + ",                                              \
            " + GetNow() + ",                                               \
            " + GetComputer() + "                                           \
        )                                                                   \
    ";

    LOG(sqlStmt);

    try {
        stmt = connection->createStatement();
        stmt->execute(sqlStmt);
    } catch (sql::SQLException &e) {
        LOG_WARN("In Elements::InsertRecord(): ", e.what(), " (Error Code: ", e.getErrorCode(),
                "; State: ", e.getSQLState(), ")");
        rv = false;
    }

    delete stmt;
    return rv;
}


//
// -- Load the initial data into the table
//    ------------------------------------
void ModelElements::LoadTables(void)
{
    // -- Create the 'name' element
    ClearCurrentRecord();
    SetName("name");
    SetType("VARCHAR");
    SetSize(64);
    SetDescription("This is the unique name of the element.");
    SetNotNull(true);
    SetShortDescription("Unique element name");
    InsertRecord();

    // -- Create the 'type' element
    ClearCurrentRecord();
    SetName("type");
    SetType("VARCHAR");
    SetSize(10);
    SetDescription("This is the type of the element.");
    SetShortDescription("Element type");
    InsertRecord();

    // -- Create the 'description' element
    ClearCurrentRecord();
    SetName("description");
    SetType("TINYTEXT");
    SetDescription("This is a long description of the element and its use.  "
            "Feel free to put a really good description here.");
    SetShortDescription("Element long description");
    InsertRecord();

    // -- Create the 'size' element
    ClearCurrentRecord();
    SetName("size");
    SetType("INT");
    SetDescription("This is the length of an element where the size can be defined (null otherwise)");
    SetShortDescription("Element size");
    InsertRecord();

    // -- Create the 'decimals' element
    ClearCurrentRecord();
    SetName("decimals");
    SetType("TINYINT");
    SetDescription("This is the number of decimal placed in a real number");
    SetShortDescription("Element decimal places");
    InsertRecord();

    // -- Create the 'unsigned' element
    ClearCurrentRecord();
    SetName("unsigned");
    SetType("BOOLEAN");
    SetDescription("This this an unsigned number?");
    SetShortDescription("Unsigned number?");
    InsertRecord();

    // -- Create the 'zero_fill' element
    ClearCurrentRecord();
    SetName("zero_fill");
    SetType("BOOLEAN");
    SetDescription("This this a zero filled number?");
    SetShortDescription("Zero filled number?");
    InsertRecord();

    // -- Create the 'auto_increment' element
    ClearCurrentRecord();
    SetName("auto_increment");
    SetType("BOOLEAN");
    SetDescription("This this an auto_incremented number?");
    SetShortDescription("Auto increment number?");
    InsertRecord();

    // -- Create the 'char_set' element
    ClearCurrentRecord();
    SetName("char_set");
    SetType("VARCHAR");
    SetSize(25);
    SetDescription("This is the character set of the string element.");
    SetShortDescription("Element string character set");
    InsertRecord();

    // -- Create the 'collate_name' element
    ClearCurrentRecord();
    SetName("collate_name");
    SetType("VARCHAR");
    SetSize(25);
    SetDescription("This is the collation name of the string element.");
    SetShortDescription("Element string collation name");
    InsertRecord();

    // -- Create the 'not_null' element
    ClearCurrentRecord();
    SetName("not_null");
    SetType("BOOLEAN");
    SetDescription("Is this element required to have a value?");
    SetShortDescription("Element cannot be null?");
    InsertRecord();

    // -- Create the 'short_description' element
    ClearCurrentRecord();
    SetName("short_description");
    SetType("VARCHAR");
    SetSize(120);
    SetDescription("This is a short description of the element.");
    SetNotNull(true);
    SetShortDescription("Element short description");
    InsertRecord();

    // -- Create the 'default_value' element
    ClearCurrentRecord();
    SetName("default_value");
    SetType("VARCHAR");
    SetSize(1000);
    SetDescription("This is a a string representation of the default value of this element.");
    SetShortDescription("Element default value");
    InsertRecord();
}