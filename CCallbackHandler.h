/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCallbackHandler.h

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
#include "plugin.h"
#include "SSquirrelFunction.h"
#include <squirrel.h>

class CCallbackHandler
{
	public:
		static void Register(PluginCallbacks * callbacks);

	private:
		static int OnInitServer();
		static void OnShutdownServer();
		static void OnFrame(float fElapsedTime);

		static void OnPlayerConnect(int nPlayerId);
		static void OnPlayerDisconnect(int nPlayerId, int nReason);
		static void OnPlayerBeginTyping(int nPlayerId);
		static void OnPlayerEndTyping(int nPlayerId);

		static int OnPlayerRequestClass(int nPlayerId, int nOffset);
		static int OnPlayerRequestSpawn(int nPlayerId);
		static void OnPlayerSpawn(int nPlayerId);
		static void OnPlayerDeath(int nPlayerId, int nKillerId, int nReason, int nBodyPart);
		static void OnPlayerUpdate(int nPlayerId, int nUpdateType);

		static int OnPlayerRequestEnter(int nPlayerId, int nVehicleId, int nSlotId);
		static void OnPlayerEnterVehicle(int nPlayerId, int nVehicleId, int nSlotId);
		static void OnPlayerExitVehicle(int nPlayerId, int nVehicleId);
		
		static int OnPickupClaimPicked(int nPickupId, int nPlayerId);
		static void OnPickupPickedUp(int nPickupId, int nPlayerId);
		static void OnPickupRespawn(int nPickupId);

		static void OnVehicleUpdate(int nVehicleId, int nUpdateType);
		static void OnVehicleExplode(int nVehicleId);
		static void OnVehicleRespawn(int nVehicleId);
		
		static void OnObjectShot(int nObjectId, int nPlayerId, int nWeapon);
		static void OnObjectBump(int nObjectId, int nPlayerId);
		
		static int OnPublicMessage(int nPlayerId, const char * pszText);
		static int OnCommandMessage(int nPlayerId, const char * pszText);
		static int OnPrivateMessage(int nPlayerId, int nTargetId, const char * pszText);
		static int OnInternalCommand(unsigned int uCmdType, const char * pszText);

		static int OnLoginAttempt(char * pszPlayerName, const char * pszUserPassword, const char * pszIpAddr);
		static void OnEntityPoolChange(int nEntityType, int nEntityId, unsigned int bDeleted);

		static void OnKeyBindDown(int nPlayerId, int nBindId);
		static void OnKeyBindUp(int nPlayerId, int nBindId);

		static void OnPlayerAwayChange(int nPlayerId, unsigned int bNewStatus);
		static void OnPlayerSpectate(int nPlayerId, int nTargetId);
		static void OnPlayerCrashReport(int nPlayerId, const char * pszReport);
		
		static void OnPlayerNameChange(int nPlayerId, const char * pszOldName, const char * pszNewName);
		static void OnPlayerStateChange(int nPlayerId, int nOldState, int nNewState);
		static void OnPlayerActionChange(int nPlayerId, int nOldAction, int nNewAction);
		static void OnPlayerOnFireChange(int nPlayerId, unsigned int bIsOnFireNow);
		static void OnPlayerCrouchChange(int nPlayerId, unsigned int bIsCrouchingNow);
		static void OnPlayerGameKeysChange(int nPlayerId, int nOldKeys, int nNewKeys);
};