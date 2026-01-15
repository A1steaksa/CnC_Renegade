/*********************************************************************************************** 
 ***                            Confidential - Westwood Studios                              *** 
 *********************************************************************************************** 
 *                                                                                             * 
 *                 Project Name : Commando                                                     * 
 *                                                                                             * 
 *                     $Archive:: /Commando/Code/Commando/combatgmode.h                       $* 
 *                                                                                             * 
 *                      $Author:: Tom_s                                                       $* 
 *                                                                                             * 
 *                     $Modtime:: 11/10/01 12:34p                                             $* 
 *                                                                                             * 
 *                    $Revision:: 23                                                          $* 
 *                                                                                             * 
 *---------------------------------------------------------------------------------------------* 
 * Functions:                                                                                  * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef	COMBATGMODE_H
#define	COMBATGMODE_H

#ifndef	ALWAYS_H
	#include "always.h"
#endif

#ifndef	GAMEMODE_H
	#include "gamemode.h"
#endif

#ifndef	COMBAT_H
	#include "combat.h"
#endif

class AudibleSoundClass;
class PhysicsSceneClass;

#define	COMBAT_BACKGROUND_MUSIC CombatGameModeClass::BackgroundMusic

/*
** Game Mode to do the main combat mode
*/
class CombatGameModeClass : public GameMajorModeClass {
public:
	// the name of this mode
	virtual	const char* Name(){
		return "Combat";
	} 

	virtual	void Init();	 // called when the mode is activated
	virtual	void Shutdown(); // called when the mode is deactivated
	virtual	void Think();	 // called each time through the main loop to think when non-inactive
	virtual	void Render();	 // called each time through the main loop to draw when non-inactive
	virtual	void Resume();	 // activates the mode
	virtual	void Suspend();	 // deactivates the mode (don't shutdown until safe)

	void Load_Level();
	void Core_Shutdown();
	void Core_Restart();

	static void Toggle_Multi_Hud(void);

	static AudibleSoundClass* BackgroundMusic;

	static void Quick_Save( void );

private:
	void Combat_Keyboard(void);

	static void Load_Registry_Keys(void);
	static void Save_Registry_Keys(void);

	static int	IsHudShown;

	static void Post_Load_Id_Uniqueness_Check(void);
	static void Post_Load_Dynamic_Object_Filtering(void);
	static void Compute_World_Size(void);
	static void Spawn_Point_Validation(void);

};

#endif

