//===================================================================================================================
//
// model-elements.h -- The concrete elements model.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Jul-26  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __ELEMENTS_MODEL_H__
#define __ELEMENTS_MODEL_H__


#include "model.h"

#include <string>

//
// -- This is the data model for an element as part of an MVC design
//    --------------------------------------------------------------
class ModelElements : public Model {
    private: std::string name;
    private: std::string type;
    private: std::string description;
    private: int size;
    private: int decimals;
    private: bool unsigned_;
    private: bool zero_fill;
    private: bool auto_increment;
    private: std::string char_set;
    private: std::string collate_name;
    private: bool not_null;
    private: std::string short_description;
    private: std::string default_value;
    
    // -- this is the name of an element that was read from the table
    private: std::string orig_name;
    
    
    //
    // -- The litany of access methods, getters and then setters...
    //    ---------------------------------------------------------
    public: std::string GetName(void) const { return name; }
    public: std::string GetType(void) const { return type; }
    public: std::string GetDescription(void) const { return description; }
    public: int GetSize(void) const { return size; }
    public: int GetDecimals(void) const { return decimals; }
    public: bool GetUnsigned(void) const { return unsigned_; }
    public: bool GetZeroFill(void) const { return zero_fill; }
    public: bool GetAutoIncrement(void) const { return auto_increment; }
    public: std::string GetCharSet(void) const { return char_set; }
    public: std::string GetCollateName(void) const { return collate_name; }
    public: bool GetNotNull(void) const { return not_null; }
    public: std::string GetShortDescription(void) const { return short_description; }
    public: std::string GetDefaultValue(void) const { return default_value; }
    
    public: void SetName(const std::string n) { name = n.substr(0, 64); }
    public: void SetType(const std::string t) { type = t.substr(0, 10); }
    public: void SetDescription(const std::string d) { description = d.substr(0, 255); }
    public: void SetSize(const int s) { size = s; }
    public: void SetDecimals(const int d) { decimals = d; }
    public: void SetUnsigned(const bool u) { unsigned_ = u; }
    public: void SetZeroFill(const bool z) { zero_fill = z; }
    public: void SetAutoIncrement(const bool a) { auto_increment = a; }
    public: void SetCharSet(const std::string s) { char_set = s.substr(0, 25); }
    public: void SetCollateName(const std::string n) { collate_name = n.substr(0, 25); }
    public: void SetNotNull(const bool n) { not_null = n; }
    public: void SetShortDescription(const std::string d) { short_description = d.substr(0, 120); }
    public: void SetDefaultValue(const std::string v) { default_value = v.substr(0, 1000); }
    
    
    //
    // -- Constructor, Destructor, and Factory methods
    //    --------------------------------------------
    private: ModelElements(void) : Model("cba_metadata", "elements") { ClearCurrentRecord(); }
    public: ~ModelElements() {}
    public: static ModelElements *Factory();
    
    
    //
    // -- The following are inherited from the Model class
    //    ------------------------------------------------
    public: virtual void ClearCurrentRecord(void);
    public: virtual bool CheckTableExists(void);
    public: virtual void CreateTable(void);
    public: virtual bool InsertRecord(void);
    
    
    //
    // -- Some functions that are needed to initialize the Elements table
    //    ---------------------------------------------------------------
    private: void LoadTables(void);
};


#endif
