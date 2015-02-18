/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCompatFunctions.cpp

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
#include "../classes/CPlayer.h"
#include "CCompatFunctions.h"
#include <sqrat.h>

void CCompatFunctions::Register(HSQUIRRELVM v) {
	Sqrat::RootTable(v)
		.Func(_SC("GetCinematicBorder"), GetCinematicBorder)
		.Func(_SC("GetScreenScanLines"), GetGreenScanLines)
		.Func(_SC("GetWhiteScanLines"), GetWhiteScanLines)
		
		.Func(_SC("SetCinematicBorder"), SetCinematicBorder)
		.Func(_SC("SetGreenScanLines"), SetGreenScanLines)
		.Func(_SC("SetWhiteScanLines"), SetWhiteScanLines)
		
		.Func(_SC("KickPlayer"), KickPlayer)
		.Func(_SC("BanPlayer"), BanPlayer)
		
		.Func(_SC("Message"), Message)
		.Func(_SC("MessagePlayer"), MessagePlayer)
		.Func(_SC("MessageAllExcept"), MessageAllExcept)
		.Func(_SC("PrivMessage"), PrivMessage)
		.Func(_SC("PrivMessageAll"), PrivMessageAll)
		.Func(_SC("SendPlayerMessage"), SendPlayerMessage);
}

bool CCompatFunctions::GetCinematicBorder(CPlayer * pPlayer) {
	if (pPlayer) return pPlayer->GetWidescreen();
	else return false;
}

bool CCompatFunctions::GetGreenScanLines(CPlayer * pPlayer) {
	if (pPlayer) return pPlayer->GetGreenScanlines();
	else return false;
}

bool CCompatFunctions::GetWhiteScanLines(CPlayer * pPlayer) {
	if (pPlayer) return pPlayer->GetWhiteScanlines();
	else return false;
}

void CCompatFunctions::SetCinematicBorder(CPlayer * pPlayer, bool bEnabled) {
	if (pPlayer) pPlayer->SetWidescreen(bEnabled);
}

void CCompatFunctions::SetGreenScanLines(CPlayer * pPlayer, bool bEnabled) {
	if (pPlayer) pPlayer->SetGreenScanlines(bEnabled);
}

void CCompatFunctions::SetWhiteScanLines(CPlayer * pPlayer, bool bEnabled) {
	if (pPlayer) pPlayer->SetWhiteScanlines(bEnabled);
}

void CCompatFunctions::KickPlayer(CPlayer * pPlayer) {
	if (pPlayer) pPlayer->Kick();
}

void CCompatFunctions::BanPlayer(CPlayer * pPlayer) {
	if (pPlayer) pPlayer->Ban();
}

void CCompatFunctions::Message(const SQChar * pszMessage) {
	g_pCore->F()->SendClientMessage(-1, 0x0b5fa5ff, "%s", pszMessage);
}

void CCompatFunctions::MessagePlayer(const SQChar * pszMessage, CPlayer * pPlayer) {
	if (pPlayer) {
		g_pCore->F()->SendClientMessage(pPlayer->GetID(), 0x0b5fa5ff, "%s", pszMessage);
	}
}

void CCompatFunctions::MessageAllExcept(const SQChar * pszMessage, CPlayer * pPlayer) {
	if (pPlayer) {
		for (int i = 0; i < g_pCore->F()->GetMaxPlayers(); i++) {
			if (g_pCore->F()->IsPlayerConnected(i) && i != pPlayer->GetID()) {
				g_pCore->F()->SendClientMessage(i, 0x0b5fa5ff, "%s", pszMessage);
			}
		}
	}
}

void CCompatFunctions::PrivMessage(CPlayer * pPlayer, const SQChar * pszMessage) {
	if (pPlayer) {
		g_pCore->F()->SendClientMessage(pPlayer->GetID(), 0x007f16ff, "** pm >> %s", pszMessage);
	}
}

void CCompatFunctions::PrivMessageAll(const SQChar * pszMessage) {
	g_pCore->F()->SendClientMessage(-1, 0x007f16ff, "** pm >> %s", pszMessage);
}

void CCompatFunctions::SendPlayerMessage(CPlayer * pPlayerToForge, CPlayer * pTarget, const SQChar * pszMessage) {
	if (pPlayerToForge && pTarget) {
		g_pCore->F()->SendClientMessage(pTarget->GetID(), 0x007f16ff, "** pm from %s >> %s",
			pPlayerToForge->GetName(), pszMessage);
	}
}
