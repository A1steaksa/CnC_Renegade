/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : WWSaveLoad                                                   *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/wwsaveload/saveloadsubsystem.cpp             $*
 *                                                                                             *
 *                       Author:: Greg Hjelstrom                                               *
 *                                                                                             *
 *                     $Modtime:: 9/09/99 9:50a                                               $*
 *                                                                                             *
 *                    $Revision:: 2                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


#include "saveloadsubsystem.h"
#include "saveload.h"


SaveLoadSubSystemClass::SaveLoadSubSystemClass(void) : NextSubSystem(NULL){
	// All Sub-Systems are automatically registered with the SaveLoadSystem
	SaveLoadSystemClass::Register_Sub_System(this);
}

SaveLoadSubSystemClass::~SaveLoadSubSystemClass(void){
	SaveLoadSystemClass::Unregister_Sub_System(this);
}
