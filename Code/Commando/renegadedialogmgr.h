/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Combat																		  *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/commando/renegadedialogmgr.h       $*
 *                                                                                             *
 *                       Author:: Patrick Smith                                                *
 *                                                                                             *
 *                     $Modtime:: 2/13/02 1:58p                                               $*
 *                                                                                             *
 *                    $Revision:: 14                                                          $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENEGADE_DIALOG_MGR_H
#define __RENEGADE_DIALOG_MGR_H

#include "dialogfactory.h"
#include "dialogresource.h"
#include "wwuiinput.h"
#include "win.h"

////////////////////////////////////////////////////////////////
//	Constants and globals
////////////////////////////////////////////////////////////////
const int FACTORY_COUNT	= ( DIALOG_LINK_LAST - DIALOG_LINK_FIRST );
extern DialogFactoryBaseClass* FactoryArray[FACTORY_COUNT];
extern WWUIInputClass* _TheWWUIInput;

class RenegadeDialogMgrClass {
public:

	typedef enum {
		LOC_MAIN_MENU			= 0,
		LOC_INTERNET_MAIN,
		LOC_INTERNET_GAME_LIST,
		LOC_LAN_MAIN,
		LOC_ENCYCLOPEDIA,
		LOC_OBJECTIVES,
		LOC_MAP,
		LOC_CNC_REFERENCE,
		LOC_LOAD_GAME,
		LOC_IN_GAME_HELP,
		LOC_GAMESPY_MAIN,
		LOC_SPLASH_IN,
		LOC_SPLASH_OUT,
	}	LOCATION;
	
	// Initialization
	static void Initialize(void);
	static void Shutdown(void);

	// Dialog creation
	static void Do_Dialog_By_Button_ID( int button_id );
	static void Do_Simple_Dialog( int dlg_res_id );

	// Menu traversal access
	static void Goto_Location( LOCATION location );
};

inline void RenegadeDialogMgrClass::Do_Dialog_By_Button_ID( int button_id ){
	WWASSERT( button_id >= DIALOG_LINK_FIRST && button_id <= DIALOG_LINK_LAST );
	
	// Start the dialog
	FactoryArray[button_id - DIALOG_LINK_FIRST]->Do_Dialog();
	return;
}

#endif //__RENEGADE_DIALOG_MGR_H

