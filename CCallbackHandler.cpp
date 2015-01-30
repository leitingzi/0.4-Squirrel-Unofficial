/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCallbackHandler.cpp

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

#include "CCallbackHandler.h"
#include "CConsole.h"
#include "CScript.h"
#include "CScriptEvents.h"
#include "Main.h"

// nEventOffset is the offset, in bytes, from SScriptEvents that the event node is at.
//
// pArgs is an array of uint64_t values which can be adapted for various purposes, such as:
//     - pointers to other objects to be dereferenced by the callback
//     - IDs for vehicles, players, or other entitites
//     - literal values such as floats and doubles
//
// The way that CallEvent is set up, ALL events in ALL scripts must agree to allow an event
// to be performed before the VC:MP server allows an action to be performed.
//
// By default, events will yield to other event subscribers and scripts. If some script event
// returns 0 in an event, all processing on that event will end there.
int CCallbackHandler::CallEvent(CScript * pScript, const SQChar * pszCallbackName, uint32_t nEventOffset, uint64_t * pArgs, EventReceiver pfCallback) {
	SScriptEvents * pEvents = pScript->E();

	// Whoever is calling this function uses offsetof(member) so the offset should be trustworthy.
	//
	// From there, we add the offset to the value of the pointer in order to get a new pointer, which
	// takes us to the event node itself.
	SLListNode<SSquirrelFunction> ** ppEventNode = (SLListNode<SSquirrelFunction> **)pEvents + nEventOffset;
	SLListNode<SSquirrelFunction> * pEventNode = *ppEventNode;

	if (pEventNode != NULL) {
		SLListNode<SSquirrelFunction> * pCurrentNode = pEventNode;
		while (pCurrentNode != NULL) {
			try {
				Sqrat::Function f = pCurrentNode->data.function;
				if (!f.IsNull()) {
					// If the callback signals for an early end to processing, we stop there.
					if (pfCallback(pScript->V(), f, pArgs) == 0) {
						return 0;
					}
				}
			}
			catch (Sqrat::Error e) {
				CConsole::OutputError("An error occurred while processing an event.");
				CConsole::OutputError(e.Message(pScript->V()).c_str());
			}

			if (pCurrentNode->next != NULL) {
				pCurrentNode = pCurrentNode->next;
			}
		}
	}
	else if (pszCallbackName != NULL) {
		Sqrat::Function f = Sqrat::RootTable(pScript->V()).GetFunction(pszCallbackName);
		if (!f.IsNull()) {
			if (pfCallback(pScript->V(), f, pArgs) == 0) {
				return 0;
			}
		}
	}

	return 1;
}

int CCallbackHandler::CallAllEvents(const SQChar * pszCallbackName, uint32_t nEventOffset, uint64_t * pArgs, EventReceiver pfCallback) {
	for (CCore::ScriptIterator it = g_pCore->GetScriptsIterator(); it != g_pCore->GetScriptsEnd(); it++) {
		CScript * pScript = it->second;
		if (CallEvent(pScript, pszCallbackName, nEventOffset, pArgs, pfCallback) == 0) {
			return 0;
		}
	}

	return 1;
}

#define REGISTER_CALLBACK(x) callbacks->x = x
void CCallbackHandler::Register(PluginCallbacks * callbacks) {
	REGISTER_CALLBACK(OnInitServer);
	REGISTER_CALLBACK(OnShutdownServer);
	REGISTER_CALLBACK(OnFrame);

	REGISTER_CALLBACK(OnPlayerConnect);
	REGISTER_CALLBACK(OnPlayerDisconnect);
	REGISTER_CALLBACK(OnPlayerBeginTyping);
	REGISTER_CALLBACK(OnPlayerEndTyping);

	REGISTER_CALLBACK(OnPlayerRequestClass);
	REGISTER_CALLBACK(OnPlayerRequestSpawn);
	REGISTER_CALLBACK(OnPlayerSpawn);
	REGISTER_CALLBACK(OnPlayerDeath);
	REGISTER_CALLBACK(OnPlayerUpdate);

	REGISTER_CALLBACK(OnPlayerRequestEnter);
	REGISTER_CALLBACK(OnPlayerEnterVehicle);
	REGISTER_CALLBACK(OnPlayerExitVehicle);

	REGISTER_CALLBACK(OnPickupClaimPicked);
	REGISTER_CALLBACK(OnPickupPickedUp);
	REGISTER_CALLBACK(OnPickupRespawn);
	
	REGISTER_CALLBACK(OnVehicleUpdate);
	REGISTER_CALLBACK(OnVehicleExplode);
	REGISTER_CALLBACK(OnVehicleRespawn);

	REGISTER_CALLBACK(OnObjectShot);
	REGISTER_CALLBACK(OnObjectBump);

	REGISTER_CALLBACK(OnPublicMessage);
	REGISTER_CALLBACK(OnCommandMessage);
	REGISTER_CALLBACK(OnPrivateMessage);
	REGISTER_CALLBACK(OnInternalCommand);

	REGISTER_CALLBACK(OnLoginAttempt);
	REGISTER_CALLBACK(OnEntityPoolChange);

	REGISTER_CALLBACK(OnKeyBindDown);
	REGISTER_CALLBACK(OnKeyBindUp);

	REGISTER_CALLBACK(OnPlayerAwayChange);
	REGISTER_CALLBACK(OnPlayerSpectate);
	REGISTER_CALLBACK(OnPlayerCrashReport);

	REGISTER_CALLBACK(OnPlayerNameChange);
	REGISTER_CALLBACK(OnPlayerStateChange);
	REGISTER_CALLBACK(OnPlayerActionChange);
	REGISTER_CALLBACK(OnPlayerOnFireChange);
	REGISTER_CALLBACK(OnPlayerCrouchChange);
	REGISTER_CALLBACK(OnPlayerGameKeysChange);
}

int CCallbackHandler::OnInitServer() {
	CallAllEvents("onServerStart", offsetof(SScriptEvents, onServerStart), NULL, CScriptEvents::onServerStart);
	return 1;
}

void CCallbackHandler::OnShutdownServer() {
	CallAllEvents("onServerStop", offsetof(SScriptEvents, onServerStop), NULL, CScriptEvents::onServerStop);
}

void CCallbackHandler::OnFrame(float fElapsedTime) {

}

void CCallbackHandler::OnPlayerConnect(int nPlayerId) {

}

void CCallbackHandler::OnPlayerDisconnect(int nPlayerId, int nReason) {

}

void CCallbackHandler::OnPlayerBeginTyping(int nPlayerId) {

}

void CCallbackHandler::OnPlayerEndTyping(int nPlayerId) {

}

int CCallbackHandler::OnPlayerRequestClass(int nPlayerId, int nOffset) {
	return 1;
}

int CCallbackHandler::OnPlayerRequestSpawn(int nPlayerId) {
	return 1;
}

void CCallbackHandler::OnPlayerSpawn(int nPlayerId) {

}

void CCallbackHandler::OnPlayerDeath(int nPlayerId, int nKillerId, int nReason, int nBodyPart) {

}

void CCallbackHandler::OnPlayerUpdate(int nPlayerId, int nUpdateType) {

}

int CCallbackHandler::OnPlayerRequestEnter(int nPlayerId, int nVehicleId, int nSlotId) {
	return 1;
}

void CCallbackHandler::OnPlayerEnterVehicle(int nPlayerId, int nVehicleId, int nSlotId) {

}

void CCallbackHandler::OnPlayerExitVehicle(int nPlayerId, int nVehicleId) {

}

int CCallbackHandler::OnPickupClaimPicked(int nPickupId, int nPlayerId) {
	return 1;
}

void CCallbackHandler::OnPickupPickedUp(int nPickupId, int nPlayerId) {

}

void CCallbackHandler::OnPickupRespawn(int nPickupId) {

}

void CCallbackHandler::OnVehicleUpdate(int nVehicleId, int nUpdateType) {

}

void CCallbackHandler::OnVehicleExplode(int nVehicleId) {

}

void CCallbackHandler::OnVehicleRespawn(int nVehicleId) {

}

void CCallbackHandler::OnObjectShot(int nObjectId, int nPlayerId, int nWeapon) {

}

void CCallbackHandler::OnObjectBump(int nObjectId, int nPlayerId) {

}

int CCallbackHandler::OnPublicMessage(int nPlayerId, const char * pszText) {
	return 1;
}

int CCallbackHandler::OnCommandMessage(int nPlayerId, const char * pszText) {
	return 1;
}

int CCallbackHandler::OnPrivateMessage(int nPlayerId, int nTargetId, const char * pszText) {
	return 1;
}

int CCallbackHandler::OnInternalCommand(unsigned int uCmdType, const char * pszText) {
	return 1;
}

int CCallbackHandler::OnLoginAttempt(char * pszPlayerName, const char * pszUserPassword, const char * pszIpAddr) {
	return 1;
}

void CCallbackHandler::OnEntityPoolChange(int nEntityType, int nEntityId, unsigned int bDeleted) {

}

void CCallbackHandler::OnKeyBindDown(int nPlayerId, int nBindId) {

}

void CCallbackHandler::OnKeyBindUp(int nPlayerId, int nBindId) {

}

void CCallbackHandler::OnPlayerAwayChange(int nPlayerId, unsigned int bNewStatus) {

}

void CCallbackHandler::OnPlayerSpectate(int nPlayerId, int nTargetId) {

}

void CCallbackHandler::OnPlayerCrashReport(int nPlayerId, const char * pszReport) {

}

void CCallbackHandler::OnPlayerNameChange(int nPlayerId, const char * pszOldName, const char * pszNewName) {

}

void CCallbackHandler::OnPlayerStateChange(int nPlayerId, int nOldState, int nNewState) {

}

void CCallbackHandler::OnPlayerActionChange(int nPlayerId, int nOldAction, int nNewAction) {

}

void CCallbackHandler::OnPlayerOnFireChange(int nPlayerId, unsigned int bIsOnFireNow) {

}

void CCallbackHandler::OnPlayerCrouchChange(int nPlayerId, unsigned int bIsCrouchingNow) {

}

void CCallbackHandler::OnPlayerGameKeysChange(int nPlayerId, int nOldKeys, int nNewKeys) {

}