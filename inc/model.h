//===================================================================================================================
//
// model.h -- An abstract model class implementation.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-26  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __MODEL_H__
#define __MODEL_H__


#include "db.h"


//
// -- This is the class definition for a model as part of an MVC design.
//    ------------------------------------------------------------------
class Model {
    // 
    // -- The database schema and table for this controller -- assumes a 1:1 relationship
    //    -------------------------------------------------------------------------------
    private: std::string SchemaName;
    private: std::string TableName;
    
    // -- ... and the access methods...
    public: std::string GetQualifiedName(void) const { return SchemaName + "." + TableName; }
    public: std::string GetSchemaName(void) const { return SchemaName; }
    public: std::string GetTableName(void) const { return TableName; }
    
    //
    // -- Constructor for the Model
    //    -------------------------
    protected: Model(const std::string &s, const std::string &n) : SchemaName(s), TableName(n) {
        SetConnection("", "", s, "", "");
        ConnectDatabase();
    }
    
    //
    // -- Clear out the record and prepare it for new data
    //    ------------------------------------------------
    public: virtual void ClearCurrentRecord(void) = 0;
    
    //
    // -- Check if the table exists
    //    -------------------------
    public: virtual bool CheckTableExists(void) = 0;
    
    //
    // -- Create the table if it does not exist
    //    -------------------------------------
    public: virtual void CreateTable(void) = 0;
    
    //
    // -- Insert Record
    //    -------------
    public: virtual bool InsertRecord(void) = 0;
    
    //
    // -- Update Record
    //    -------------
//    public: virtual bool UpdateRecord(void) = 0;
    
    //
    // -- Delete Record
    //    -------------
//    public: virtual bool DeleteRecord(void) = 0;

    // 
    // -- the functions to get the audit info from mysql
    //    ----------------------------------------------
    const std::string GetNow(void) { return "now()"; }
    const std::string GetUser(void) { return "substring(user(),1,locate('@',user())-1)"; }
    const std::string GetComputer(void) { return "substring_index(user(),'@',-1)"; }
};


#endif
