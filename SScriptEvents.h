/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: SEventsLList.h

   Copyright (c) 2015 Nelson Gomez (Stormeus)

   Licensed under the MIT License. A copy of the License is available in
   LICENSE or at:

       http://opensource.org/licenses/MIT

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#pragma once
#include "SLListNode.h"
#include "SSquirrelFunction.h"
#include "Main.h"

#define DEFINE_EVENT(x) SLListNode<SSquirrelFunction> * x
#define INIT_EVENT(x) x = NULL

// This struct consists of a series of SLListNodes to store linked lists of
// SSquirrelFunctions. This allows scripts to subscribe multiple functions to
// one callback. However, these linked lists need to be destroyed at some point.
//
// Whenever adding an event here, make sure to add it to CScript::DestroyEvents.
// If you don't, memory leaks WILL occur.
//
// It'd also be wise to make sure that CScriptEvents has an appropriate callback
// for CCallbackHandler, and that something in CCallbackHandler is making use of it.
//
// Basically the flow for adding a script event is:
//     1. Declare and init here.
//     2. Add to CScript::DestroyEvents
//     3. Implement in CScriptEvents
//     4. Make sure something in CCallbackHandler actually calls the new event
struct SScriptEvents {
	SScriptEvents() {
		INIT_EVENT(onServerStart);
		INIT_EVENT(onServerStop);

		INIT_EVENT(onScriptLoad);
		INIT_EVENT(onScriptUnload);

		INIT_EVENT(onPlayerJoin);
		INIT_EVENT(onPlayerPart);
		INIT_EVENT(onPlayerCrashDump);
		INIT_EVENT(onLoginAttempt);

		INIT_EVENT(onPlayerRequestClass);
		INIT_EVENT(onPlayerRequestSpawn);
		INIT_EVENT(onPlayerSpawn);

		INIT_EVENT(onPlayerDeath);
		INIT_EVENT(onPlayerKill);
		INIT_EVENT(onPlayerTeamKill);

		INIT_EVENT(onPlayerEnteringVehicle);
		INIT_EVENT(onPlayerEnterVehicle);
		INIT_EVENT(onPlayerExitVehicle);

		INIT_EVENT(onPlayerChat);
		INIT_EVENT(onPlayerCommand);
		INIT_EVENT(onPlayerPM);
		INIT_EVENT(onPlayerBeginTyping);
		INIT_EVENT(onPlayerEndTyping);
		INIT_EVENT(onPlayerAwayChange);

		INIT_EVENT(onPlayerMove);
		INIT_EVENT(onPlayerHealthChange);
		INIT_EVENT(onPlayerArmourChange);
		INIT_EVENT(onPlayerWeaponChange);
		INIT_EVENT(onPlayerActionChange);
		INIT_EVENT(onPlayerStateChange);
		INIT_EVENT(onPlayerOnFireChange);
		INIT_EVENT(onPlayerCrouchChange);
		INIT_EVENT(onPlayerGameKeysChange);

		INIT_EVENT(onPickupClaimPicked);
		INIT_EVENT(onPickupPickedUp);
		INIT_EVENT(onPickupRespawn);

		INIT_EVENT(onVehicleExplode);
		INIT_EVENT(onVehicleRespawn);
		INIT_EVENT(onVehicleHealthChange);
		INIT_EVENT(onVehicleMove);

		INIT_EVENT(onObjectShot);
		INIT_EVENT(onObjectBump);

		INIT_EVENT(onKeyDown);
		INIT_EVENT(onKeyUp);

		INIT_EVENT(onTimeChange);
	}

	DEFINE_EVENT(onServerStart);
	DEFINE_EVENT(onServerStop);

	DEFINE_EVENT(onScriptLoad);
	DEFINE_EVENT(onScriptUnload);

	DEFINE_EVENT(onPlayerJoin);
	DEFINE_EVENT(onPlayerPart);
	DEFINE_EVENT(onPlayerCrashDump);
	DEFINE_EVENT(onLoginAttempt);

	DEFINE_EVENT(onPlayerRequestClass);
	DEFINE_EVENT(onPlayerRequestSpawn);
	DEFINE_EVENT(onPlayerSpawn);

	DEFINE_EVENT(onPlayerDeath);
	DEFINE_EVENT(onPlayerKill);
	DEFINE_EVENT(onPlayerTeamKill);

	DEFINE_EVENT(onPlayerEnteringVehicle);
	DEFINE_EVENT(onPlayerEnterVehicle);
	DEFINE_EVENT(onPlayerExitVehicle);

	DEFINE_EVENT(onPlayerChat);
	DEFINE_EVENT(onPlayerCommand);
	DEFINE_EVENT(onPlayerPM);
	DEFINE_EVENT(onPlayerBeginTyping);
	DEFINE_EVENT(onPlayerEndTyping);
	DEFINE_EVENT(onPlayerAwayChange);

	DEFINE_EVENT(onPlayerMove);
	DEFINE_EVENT(onPlayerHealthChange);
	DEFINE_EVENT(onPlayerArmourChange);
	DEFINE_EVENT(onPlayerWeaponChange);
	DEFINE_EVENT(onPlayerActionChange);
	DEFINE_EVENT(onPlayerStateChange);
	DEFINE_EVENT(onPlayerOnFireChange);
	DEFINE_EVENT(onPlayerCrouchChange);
	DEFINE_EVENT(onPlayerGameKeysChange);

	DEFINE_EVENT(onPickupClaimPicked);
	DEFINE_EVENT(onPickupPickedUp);
	DEFINE_EVENT(onPickupRespawn);

	DEFINE_EVENT(onVehicleExplode);
	DEFINE_EVENT(onVehicleRespawn);
	DEFINE_EVENT(onVehicleHealthChange);
	DEFINE_EVENT(onVehicleMove);

	DEFINE_EVENT(onObjectShot);
	DEFINE_EVENT(onObjectBump);

	DEFINE_EVENT(onKeyDown);
	DEFINE_EVENT(onKeyUp);

	DEFINE_EVENT(onTimeChange);
};