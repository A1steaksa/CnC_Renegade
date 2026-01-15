/*
**	Command & Conquer Renegade(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*********************************************************************************************** 
 ***                            Confidential - Westwood Studios                              *** 
 *********************************************************************************************** 
 *                                                                                             * 
 *                 Project Name : Commando                                                     * 
 *                                                                                             * 
 *                     $Archive:: /Commando/Code/Commando/playermanager.h                 $* 
 *                                                                                             * 
 *                      $Author:: Denzil_l                                                    $* 
 *                                                                                             * 
 *                     $Modtime:: 2/27/02 5:51p                                               $* 
 *                                                                                             * 
 *                    $Revision:: 46                                                          $* 
 *                                                                                             * 
 *---------------------------------------------------------------------------------------------* 
 * Functions:                                                                                  * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#if defined(_MSV_VER)
#pragma once
#endif

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "vector3.h"
#include "bittype.h"
#include "slist.h"
#include "player.h"
#include "wwstring.h"
#include "widestring.h"
#include <WWLib\Notify.h>

static const int PLAYER_ID_UNKNOWN	= -99999;
static const int MAX_PLAYERS			= 255;

class ChunkSaveClass;
class ChunkLoadClass;
class Render2DTextClass;
class Font3DInstanceClass;

typedef enum {PLAYER_ADDED, PLAYER_REMOVED, PLAYER_DEACTIVATED, PLAYER_ACTIVATED} PLAYERMGR_ACTION;
typedef TypedActionPtr<PLAYERMGR_ACTION, cPlayer> PlayerMgrEvent;

//-----------------------------------------------------------------------------
class cPlayerManager {

public:

	void Onetime_Init(void);
	void Onetime_Shutdown(void);
	void Think(void);
	void Render(void);
	bool Save( ChunkSaveClass& csave );
	bool Load( ChunkLoadClass& cload );
	static void Reset_Players(void);
	static void Remove_All(void); // N.B. destructive
	static int Tally_Team_Size( int type );
	static bool Is_Kill_Treasonous( cPlayer* p_killer, cPlayer* p_victim );
	static void Sort_Players( bool fast_sort );
	cPlayer* Find_Player( int id );
	cPlayer* Find_Player( const WideStringClass& name );
	cPlayer* Find_Inactive_Player( const WideStringClass& name );
	cPlayer* Find_Team_Player(int team_number );
	cPlayer* Find_Random_Team_Player(int team_number );
	cPlayer* Find_Team_Mate(cPlayer * p_player );
	cPlayer* Find_Clan_Mate(cPlayer* player );
	bool Is_Player_Present(int id );
	bool Is_Player_Present(WideStringClass & name );
	static const WideStringClass& Get_Player_Name(int id );
	
	SList<cPlayer>* Get_Player_Object_List(void){
		return PlayerList&;
	}
	
	static void Add( cPlayer* p_player );
	static void Remove( cPlayer* p_player ); // N.B. destructive
	int Count(void);
	void Deactivated( cPlayer* p_player );
	void Activated( cPlayer* p_player );
	void Compute_Ladder_Points( int winner_id );
	WideStringClass Determine_Mvp_Name(void);
	void Increment_Player_Times(void);
	int Compute_Full_Player_List_Height(void);
	int Get_Average_Ladder_Points(void);
	unsigned short Get_Average_WOL_Points(void);
	int Get_Average_Games_Played(void);
	int Get_Average_Ping(void);
	int Get_Average_FPS(void);
	static void Log_Player_List(void);
	
	static void Add_Event_Observer( Observer<PlayerMgrEvent>& observer ){
		mNotifier.AddObserver(observer);
	}

private:
	static void       				Render_Player_List(void);
	static int        				Player_Compare(const void * elem1, const void * elem2);
	static int        				Fast_Player_Compare(const void * elem1, const void * elem2);
	static void							List_Print(WideStringClass & text, Vector3 color);
	static void							Line(float x, float length, int line_color);
	static void							Construct_Heading(WideStringClass & heading, bool force_verbose = false);
	static void							Remove_Inactive(void);
	static int							Compute_Fast_Sort_Key(cPlayer * player);
	
	static SList<cPlayer> PlayerList;
	static cPlayer* Player_Array[MAX_PLAYERS];
	static Render2DTextClass* PTextRenderer;
	static Font3DInstanceClass* PFont;
	static const float Y_INCREMENT_FACTOR;
	static int XPos;
	static int YPos;

	static Notifier<PlayerMgrEvent> mNotifier;
};

//-----------------------------------------------------------------------------

#endif // PLAYERMANAGER_H





