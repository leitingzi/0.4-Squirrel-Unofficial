/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: SEventsLList.h

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

#include "SLListNode.h"
#include "SSquirrelFunction.h"
#include "Main.h"

#define DEFINE_EVENT(x) SLListNode<SSquirrelFunction> x

struct SScriptEvents {
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