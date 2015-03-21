/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CServerFunctions.cpp

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

#include "../Main.h"
#include "../structures/CRGBA.h"
#include "../structures/CVector.h"
#include "CServerFunctions.h"
#include <sqrat.h>

void CServerFunctions::Register(HSQUIRRELVM v) {
	Sqrat::RootTable(v)
		.Overload(_SC("ClientMessage"), ClientMessage)
		.Overload(_SC("ClientMessage"), ClientMessageWithAlpha)

		.Overload(_SC("ClientMessageToAll"), ClientMessageToAll)
		.Overload(_SC("ClientMessageToAll"), ClientMessageToAllWithAlpha)
		
		.Overload(_SC("Announce"), GameMessage)
		.Overload(_SC("Announce"), GameMessageLegacy)
		
		.Overload(_SC("AnnounceAll"), GameMessageToAll)
		.Overload(_SC("AnnounceAll"), GameMessageToAllLegacy)
		
		.Func(_SC("GetServerName"), GetServerName)
		.Func(_SC("GetPassword"), GetPassword)
		.Func(_SC("GetGameModeName"), GetGameModeName)
		.Func(_SC("GetMaxPlayers"), GetMaxPlayers)
		.Func(_SC("GetKillDelay"), GetKillDelay)
		.Func(_SC("GetUseClasses"), GetUseClasses)
		
		.Func(_SC("SetServerName"), SetServerName)
		.Func(_SC("SetPassword"), SetPassword)
		.Func(_SC("SetGameModeName"), SetGameModeName)
		.Func(_SC("SetMaxPlayers"), SetMaxPlayers)
		.Func(_SC("SetKillDelay"), SetKillDelay)
		.Func(_SC("SetUseClasses"), SetUseClasses)

		.Func(_SC("SetSpawnPlayerPos"), SetSpawnPlayerPos)
		.Func(_SC("SetSpawnCameraPos"), SetSpawnCameraPos)
		.Func(_SC("SetSpawnCameraLook"), SetSpawnCameraLook)
		
		.Func(_SC("BanIP"), BanIP)
		.Func(_SC("UnbanIP"), UnbanIP)
		.Func(_SC("IsIPBanned"), IsIPBanned)
		
		.Func(_SC("Shutdown"), Shutdown);
}

void CServerFunctions::ClientMessage(const SQChar * pszMessage, CPlayer * pPlayer, int r, int g, int b) {
	g_pCore->F()->SendClientMessage(pPlayer->GetID(),
		CRGBA(r, g, b, 0xFF).ToInt(), "%s", pszMessage);
}

void CServerFunctions::ClientMessageWithAlpha(const SQChar * pszMessage, CPlayer * pPlayer, int r, int g, int b, int a) {
	g_pCore->F()->SendClientMessage(pPlayer->GetID(),
		CRGBA(r, g, b, a).ToInt(), "%s", pszMessage);
}

void CServerFunctions::ClientMessageToAll(const SQChar * pszMessage, int r, int g, int b) {
	g_pCore->F()->SendClientMessage(-1, CRGBA(r, g, b, 0xFF).ToInt(),
		"%s", pszMessage);
}

void CServerFunctions::ClientMessageToAllWithAlpha(const SQChar * pszMessage, int r, int g, int b, int a) {
	g_pCore->F()->SendClientMessage(-1, CRGBA(r, g, b, a).ToInt(),
		"%s", pszMessage);
}

void CServerFunctions::GameMessage(const SQChar * pszMessage, CPlayer * pPlayer, int type) {
	g_pCore->F()->SendGameMessage(pPlayer->GetID(), type, "%s", pszMessage);
}

void CServerFunctions::GameMessageLegacy(const SQChar * pszMessage, CPlayer * pPlayer) {
	g_pCore->F()->SendGameMessage(pPlayer->GetID(), 1, "%s", pszMessage);
}

void CServerFunctions::GameMessageToAll(const SQChar * pszMessage, int type) {
	g_pCore->F()->SendGameMessage(-1, type, "%s", pszMessage);
}

void CServerFunctions::GameMessageToAllLegacy(const SQChar * pszMessage) {
	g_pCore->F()->SendGameMessage(-1, 1, "%s", pszMessage);
}

void CServerFunctions::SetServerName(const SQChar * pszName) {
	g_pCore->F()->SetServerName(pszName);
}

void CServerFunctions::SetMaxPlayers(int nMaxPlayers) {
	g_pCore->F()->SetMaxPlayers(nMaxPlayers);
}

void CServerFunctions::SetPassword(SQChar * pszPassword) {
	g_pCore->F()->SetServerPassword(pszPassword);
}

void CServerFunctions::SetGameModeName(const SQChar * pszName) {
	g_pCore->F()->SetGameModeText(pszName);
}

void CServerFunctions::SetKillDelay(int nDelay) {
	g_pCore->F()->SetKillCmdDelay(nDelay);
}

const SQChar * CServerFunctions::GetServerName(void) {
	static SQChar szBuf[256];
	g_pCore->F()->GetServerName(szBuf, 256);

	return szBuf;
}

const SQChar * CServerFunctions::GetPassword(void) {
	static SQChar szBuf[64];
	g_pCore->F()->GetServerPassword(szBuf, 64);

	return szBuf;
}

const SQChar * CServerFunctions::GetGameModeName(void) {
	static SQChar szBuf[64];
	g_pCore->F()->GetGameModeText(szBuf, 64);

	return szBuf;
}

int CServerFunctions::GetMaxPlayers(void) {
	return g_pCore->F()->GetMaxPlayers();
}

int CServerFunctions::GetKillDelay(void) {
	return g_pCore->F()->GetKillCmdDelay();
}

void CServerFunctions::SetUseClasses(bool bEnabled) {
	g_pCore->F()->SetUseClasses(bEnabled);
}

bool CServerFunctions::GetUseClasses(void) {
	return g_pCore->F()->GetUseClasses() == 1;
}

void CServerFunctions::SetSpawnPlayerPos(CVector * pPos) {
	g_pCore->F()->SetSpawnPlayerPos(VECTOREX(pPos));
}

void CServerFunctions::SetSpawnCameraPos(CVector * pPos) {
	g_pCore->F()->SetSpawnCameraPos(VECTOREX(pPos));
}

void CServerFunctions::SetSpawnCameraLook(CVector * pPos) {
	g_pCore->F()->SetSpawnCameraLookAt(VECTOREX(pPos));
}

void CServerFunctions::BanIP(SQChar * pszIP) {
	g_pCore->F()->BanIP(pszIP);
}

void CServerFunctions::UnbanIP(SQChar * pszIP) {
	g_pCore->F()->UnbanIP(pszIP);
}

bool CServerFunctions::IsIPBanned(SQChar * pszIP) {
	return g_pCore->F()->IsIPBanned(pszIP) == 1;
}

void CServerFunctions::Shutdown(void) {
	g_pCore->F()->ShutdownServer();
}