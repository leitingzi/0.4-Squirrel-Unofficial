/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CScript.cpp

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

#include "CScript.h"
#include "CConsole.h"
#include "CUtilities.h"

void CScript::Run() {
	m_pEvents = new SScriptEvents;
	m_pVM = sq_open(256);
	m_pRunningScript = new Sqrat::Script(m_pVM);

	sq_setprintfunc(m_pVM, CSQIO::printfunc, CSQIO::errorfunc);
	CVMPopulator::Populate(m_pVM);

	try {
		m_pRunningScript->CompileFile(m_pszScriptName);
		m_pRunningScript->Run();
	}
	catch (Sqrat::Error e) {
		CConsole::OutputError("A script execution error was encountered.");
		CConsole::OutputError(e.Message(m_pVM).c_str());
	}
}

void CScript::ResetState() {
	if (m_pVM) {
		sq_close(m_pVM);
		m_pVM = NULL;
	}

	if (m_pEvents) {
		DestroyEvents();
	}

	if (m_pRunningScript) {
		delete m_pRunningScript;
		m_pRunningScript = NULL;
	}
}

void CScript::Reload() {
	ResetState();
	Run();
}

#define DESTROY_EVENT(x) CUtilities::DestroyLinkedList<SSquirrelFunction>(&m_pEvents->x)
void CScript::DestroyEvents() {
	DESTROY_EVENT(onServerStart);
	DESTROY_EVENT(onServerStop);

	DESTROY_EVENT(onScriptLoad);
	DESTROY_EVENT(onScriptUnload);

	DESTROY_EVENT(onPlayerJoin);
	DESTROY_EVENT(onPlayerPart);
	DESTROY_EVENT(onPlayerCrashDump);
	DESTROY_EVENT(onLoginAttempt);

	DESTROY_EVENT(onPlayerRequestClass);
	DESTROY_EVENT(onPlayerRequestSpawn);
	DESTROY_EVENT(onPlayerSpawn);

	DESTROY_EVENT(onPlayerDeath);
	DESTROY_EVENT(onPlayerKill);
	DESTROY_EVENT(onPlayerTeamKill);

	DESTROY_EVENT(onPlayerEnteringVehicle);
	DESTROY_EVENT(onPlayerEnterVehicle);
	DESTROY_EVENT(onPlayerExitVehicle);

	DESTROY_EVENT(onPlayerChat);
	DESTROY_EVENT(onPlayerCommand);
	DESTROY_EVENT(onPlayerPM);
	DESTROY_EVENT(onPlayerBeginTyping);
	DESTROY_EVENT(onPlayerEndTyping);
	DESTROY_EVENT(onPlayerAwayChange);

	DESTROY_EVENT(onPlayerMove);
	DESTROY_EVENT(onPlayerHealthChange);
	DESTROY_EVENT(onPlayerArmourChange);
	DESTROY_EVENT(onPlayerWeaponChange);
	DESTROY_EVENT(onPlayerActionChange);
	DESTROY_EVENT(onPlayerStateChange);
	DESTROY_EVENT(onPlayerOnFireChange);
	DESTROY_EVENT(onPlayerCrouchChange);
	DESTROY_EVENT(onPlayerGameKeysChange);

	DESTROY_EVENT(onPickupClaimPicked);
	DESTROY_EVENT(onPickupPickedUp);
	DESTROY_EVENT(onPickupRespawn);

	DESTROY_EVENT(onVehicleExplode);
	DESTROY_EVENT(onVehicleRespawn);
	DESTROY_EVENT(onVehicleHealthChange);
	DESTROY_EVENT(onVehicleMove);

	DESTROY_EVENT(onObjectShot);
	DESTROY_EVENT(onObjectBump);

	DESTROY_EVENT(onKeyDown);
	DESTROY_EVENT(onKeyUp);

	DESTROY_EVENT(onTimeChange);

	delete m_pEvents;
}