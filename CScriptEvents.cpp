/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CScriptEvents.cpp

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
#include "CScriptEvents.h"

inline bool EvaluateEventResult(Sqrat::SharedPtr<int> pnResult) {
	if (!pnResult) {
		return 1;
	}

	return (*pnResult == 1);
}

EVENTCALL_IMPL(onServerStart) {
	Sqrat::SharedPtr<int> pnResult = f.Evaluate<int>();
	return EvaluateEventResult(pnResult);
}

EVENTCALL_IMPL(onServerStop) {
	Sqrat::SharedPtr<int> pnResult = f.Evaluate<int>();
	return EvaluateEventResult(pnResult);
}

EVENTCALL_IMPL(onScriptLoad) {
	Sqrat::SharedPtr<int> pnResult = f.Evaluate<int>();
	return EvaluateEventResult(pnResult);
}

EVENTCALL_IMPL(onScriptUnload) {
	Sqrat::SharedPtr<int> pnResult = f.Evaluate<int>();
	return EvaluateEventResult(pnResult);
}

EVENTCALL_IMPL(onPlayerJoin) {
	return 1;
}

EVENTCALL_IMPL(onPlayerPart) {
	return 1;
}

EVENTCALL_IMPL(onPlayerCrashDump) {
	return 1;
}
EVENTCALL_IMPL(onLoginAttempt) {
	return 1;
}

EVENTCALL_IMPL(onPlayerRequestClass) {
	return 1;
}

EVENTCALL_IMPL(onPlayerRequestSpawn) {
	return 1;
}

EVENTCALL_IMPL(onPlayerSpawn) { return 1; }

EVENTCALL_IMPL(onPlayerDeath) { return 1; }
EVENTCALL_IMPL(onPlayerKill) { return 1; }
EVENTCALL_IMPL(onPlayerTeamKill) { return 1; }

EVENTCALL_IMPL(onPlayerEnteringVehicle) { return 1; }
EVENTCALL_IMPL(onPlayerEnterVehicle) { return 1; }
EVENTCALL_IMPL(onPlayerExitVehicle) { return 1; }

EVENTCALL_IMPL(onPlayerChat) { return 1; }
EVENTCALL_IMPL(onPlayerCommand) { return 1; }
EVENTCALL_IMPL(onPlayerPM) { return 1; }
EVENTCALL_IMPL(onPlayerBeginTyping) { return 1; }
EVENTCALL_IMPL(onPlayerEndTyping) { return 1; }
EVENTCALL_IMPL(onPlayerAwayChange) { return 1; }

EVENTCALL_IMPL(onPlayerMove) { return 1; }
EVENTCALL_IMPL(onPlayerHealthChange) { return 1; }
EVENTCALL_IMPL(onPlayerArmourChange) { return 1; }
EVENTCALL_IMPL(onPlayerWeaponChange) { return 1; }
EVENTCALL_IMPL(onPlayerActionChange) { return 1; }
EVENTCALL_IMPL(onPlayerStateChange) { return 1; }
EVENTCALL_IMPL(onPlayerOnFireChange) { return 1; }
EVENTCALL_IMPL(onPlayerCrouchChange) { return 1; }
EVENTCALL_IMPL(onPlayerGameKeysChange) { return 1; }

EVENTCALL_IMPL(onPickupClaimPicked) { return 1; }
EVENTCALL_IMPL(onPickupPickedUp) { return 1; }
EVENTCALL_IMPL(onPickupRespawn) { return 1; }

EVENTCALL_IMPL(onVehicleExplode) { return 1; }
EVENTCALL_IMPL(onVehicleRespawn) { return 1; }
EVENTCALL_IMPL(onVehicleHealthChange) { return 1; }
EVENTCALL_IMPL(onVehicleMove) { return 1; }

EVENTCALL_IMPL(onObjectShot) { return 1; }
EVENTCALL_IMPL(onObjectBump) { return 1; }

EVENTCALL_IMPL(onKeyDown) { return 1; }
EVENTCALL_IMPL(onKeyUp) { return 1; }

EVENTCALL_IMPL(onTimeChange) { return 1; }