/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CScriptEvents.h

   Copyright (c) 2015 Nelson Gomez (Stormeus)

   Licensed under the MIT License. A copy of the License is available in
   LICENSE.txt or at:

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
#include <stdint.h>
#include <squirrel.h>
#include <sqrat.h>

#define EVENTCALL_DECL(x) static int x(HSQUIRRELVM v, Sqrat::Function f, uint64_t * pArgs)
#define EVENTCALL_IMPL(x) int CScriptEvents::x(HSQUIRRELVM v, Sqrat::Function f, uint64_t * pArgs)

// These are callbacks used by CCallbackHandler for making proper use of multiple
// scripts and VMs. If there were only one script (i.e. old Squirrel), the callback
// handlers would just directly call the functions. Instead, a function iterates
// through all of the scripts, then iterates through all registered events in each
// script and calls the callbacks here.
//
// From here we can THEN call the script function.
class CScriptEvents
{
	public:
		EVENTCALL_DECL(onServerStart);
		EVENTCALL_DECL(onServerStop);

		EVENTCALL_DECL(onScriptLoad);
		EVENTCALL_DECL(onScriptUnload);

		EVENTCALL_DECL(onPlayerJoin);
		EVENTCALL_DECL(onPlayerPart);
		EVENTCALL_DECL(onPlayerCrashDump);
		EVENTCALL_DECL(onLoginAttempt);

		EVENTCALL_DECL(onPlayerRequestClass);
		EVENTCALL_DECL(onPlayerRequestSpawn);
		EVENTCALL_DECL(onPlayerSpawn);

		EVENTCALL_DECL(onPlayerDeath);
		EVENTCALL_DECL(onPlayerKill);
		EVENTCALL_DECL(onPlayerTeamKill);

		EVENTCALL_DECL(onPlayerEnteringVehicle);
		EVENTCALL_DECL(onPlayerEnterVehicle);
		EVENTCALL_DECL(onPlayerExitVehicle);

		EVENTCALL_DECL(onPlayerChat);
		EVENTCALL_DECL(onPlayerCommand);
		EVENTCALL_DECL(onPlayerPM);
		EVENTCALL_DECL(onPlayerBeginTyping);
		EVENTCALL_DECL(onPlayerEndTyping);
		EVENTCALL_DECL(onPlayerAwayChange);

		EVENTCALL_DECL(onPlayerMove);
		EVENTCALL_DECL(onPlayerHealthChange);
		EVENTCALL_DECL(onPlayerArmourChange);
		EVENTCALL_DECL(onPlayerWeaponChange);
		EVENTCALL_DECL(onPlayerActionChange);
		EVENTCALL_DECL(onPlayerStateChange);
		EVENTCALL_DECL(onPlayerOnFireChange);
		EVENTCALL_DECL(onPlayerCrouchChange);
		EVENTCALL_DECL(onPlayerGameKeysChange);

		EVENTCALL_DECL(onPickupClaimPicked);
		EVENTCALL_DECL(onPickupPickedUp);
		EVENTCALL_DECL(onPickupRespawn);

		EVENTCALL_DECL(onVehicleExplode);
		EVENTCALL_DECL(onVehicleRespawn);
		EVENTCALL_DECL(onVehicleHealthChange);
		EVENTCALL_DECL(onVehicleMove);

		EVENTCALL_DECL(onObjectShot);
		EVENTCALL_DECL(onObjectBump);

		EVENTCALL_DECL(onKeyDown);
		EVENTCALL_DECL(onKeyUp);

		EVENTCALL_DECL(onTimeChange);
};