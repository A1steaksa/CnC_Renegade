/*********************************************************************************************** 
 ***                            Confidential - Westwood Studios                              *** 
 *********************************************************************************************** 
 *                                                                                             * 
 *                 Project Name : Commando                                                     * 
 *                                                                                             * 
 *                     $Archive:: /Commando/Code/Combat/netclassids.h         $* 
 *                                                                                             * 
 *                      $Author:: Tom_s                                                       $* 
 *                                                                                             * 
 *                     $Modtime:: 2/21/02 3:00p                                               $* 
 *                                                                                             * 
 *                    $Revision:: 27                                                          $* 
 *                                                                                             * 
 *---------------------------------------------------------------------------------------------* 
 * Functions:                                                                                  * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __NET_CLASSIDS_H
#define __NET_CLASSIDS_H


////////////////////////////////////////////////////////////////
//	Network class IDs
////////////////////////////////////////////////////////////////
enum {
	//
	// S-created objects
	//
	NETCLASSID_GAMEOBJ						= 1000,
	NETCLASSID_SCTEXTOBJ,
	NETCLASSID_PLAYERKILL,
	NETCLASSID_WIN,
	NETCLASSID_PURCHASERESPONSEEVENT,
	NETCLASSID_CONSOLECOMMANDEVENT,
	NETCLASSID_RESETWINSEVENT,
	NETCLASSID_SVRGOODBYEEVENT,
	NETCLASSID_GAMEOPTIONSEVENT,
	NETCLASSID_EVICTIONEVENT,
	NETCLASSID_TEAM,
	NETCLASSID_PLAYER,
	NETCLASSID_GAMEDATAUPDATEEVENT,
	NETCLASSID_SCPINGRESPONSEEVENT,
	NETCLASSID_SCEXPLOSIONEVENT,
	NETCLASSID_SCOBELISKEVENT,
	NETCLASSID_SCANNOUNCEMENT,
	NETCLASSID_GAMESPYSCCHALLENGEEVENT,

	//
	// C-created objects
	//
	NETCLASSID_CLIENTCONTROL,
	NETCLASSID_CSTEXTOBJ,
	NETCLASSID_SUICIDEEVENT,
	NETCLASSID_CHANGETEAMEVENT,
	NETCLASSID_MONEYEVENT,
	NETCLASSID_WARPEVENT,
	NETCLASSID_PURCHASEREQUESTEVENT,
	NETCLASSID_CLIENTGOODBYEEVENT,
	NETCLASSID_BIOEVENT,
	NETCLASSID_LOADINGEVENT,
	NETCLASSID_GODMODEEVENT,
	NETCLASSID_VIPMODEEVENT,
	NETCLASSID_SCOREEVENT,
	NETCLASSID_CLIENTBBOEVENT,
	NETCLASSID_CLIENTFPS,
	NETCLASSID_CSPINGREQUESTEVENT,
	NETCLASSID_CSDAMAGEEVENT,
	NETCLASSID_REQUESTKILLEVENT,
	NETCLASSID_CSCONSOLECOMMANDEVENT,
	NETCLASSID_CSHINT,
	NETCLASSID_CSANNOUNCEMENT,
	NETCLASSID_DONATEEVENT,
	NETCLASSID_GAMESPYCSCHALLENGERESPONSEEVENT,
};	

#endif //__NET_CLASSIDS_H
