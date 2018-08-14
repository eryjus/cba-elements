//===================================================================================================================
//
// about-view.h -- This is the near-trivial About dialog box
//
// We use Qt4 for this implementation.
//
// -----------------------------------------------------------------------------------------------------------------
//
//    Date      Tracker  Version  Pgmr  Description
// -----------  -------  -------  ----  ----------------------------------------------------------------------------
// 2018-Aug-06  Initial   0.0.0   ADCL  Initial version
//
//===================================================================================================================


#ifndef __ABOUT_VIEW_H__
#define __ABOUT_VIEW_H__


//
// -- Application includes; framework includes
//    ----------------------------------------
#include <QMessageBox>


//
// -- This is a simple dialog box that displays some information about the `cba-elements` application
//    -----------------------------------------------------------------------------------------------
class AboutView : public QMessageBox {
    friend class AboutController;


    //
    // -- Private constructor to prevent inheritence
    //    ------------------------------------------
    private: AboutView();       // prevent inheritance

    public: ~AboutView() {};
};


#endif

