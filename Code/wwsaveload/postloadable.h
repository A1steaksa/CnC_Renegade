/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : WWSaveLoad                                                   *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/wwsaveload/postloadable.h                    $*
 *                                                                                             *
 *              Original Author:: Greg Hjelstrom                                               *
 *                                                                                             *
 *                      $Author:: Greg_h                                                      $*
 *                                                                                             *
 *                     $Modtime:: 5/09/01 11:46a                                              $*
 *                                                                                             *
 *                    $Revision:: 3                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef POSTLOADABLE_H
#define POSTLOADABLE_H


//////////////////////////////////////////////////////////////////////////////////
//
//	PostLoadableClass
//
//	PostLoadableClass allows a lower level for non-Persist objects to On_Post_Load
// without requiring Get_Factory or other requirements of PersistClass.  Objects
// derived from this class can be added to the post-load list in the SaveLoadSystem
//
//////////////////////////////////////////////////////////////////////////////////
class PostLoadableClass {
public:
    PostLoadableClass( void ) : IsPostLoadRegistered( false ) {
    }

    virtual ~PostLoadableClass( void ) {
    }

    virtual void On_Post_Load( void ) {
    }

    bool Is_Post_Load_Registered( void ) {
        return IsPostLoadRegistered;
    }

    void Set_Post_Load_Registered( bool onoff ) {
        IsPostLoadRegistered = onoff;
    }

private:
    bool									IsPostLoadRegistered;
};



#endif

