/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CPlayer.cpp

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
#include "CPlayer.h"

void CPlayer::Register(HSQUIRRELVM v) {
	// TODO
}

void CPlayer::Delete(void) { Kick(); }
void CPlayer::SetName(const SQChar * pszNewName) {
	g_pCore->F()->SetPlayerName(m_nPlayerId, pszNewName);
}

void CPlayer::SetPosition(CVector * pPos) {
	// TODO
}

void CPlayer::SetHealth(float fHealth) {
	g_pCore->F()->SetPlayerHealth(m_nPlayerId, fHealth);
}

void CPlayer::SetArmour(float fArmour) {
	g_pCore->F()->SetPlayerArmour(m_nPlayerId, fArmour);
}

void CPlayer::SetWorld(int nWorld) {
	g_pCore->F()->SetPlayerWorld(m_nPlayerId, nWorld);
}

void CPlayer::SetSecondaryWorld(int nWorld) {
	g_pCore->F()->SetPlayerSecWorld(m_nPlayerId, nWorld);
}

void CPlayer::SetTeam(int nTeam) {
	g_pCore->F()->SetPlayerTeam(m_nPlayerId, nTeam);
}

void CPlayer::SetSkin(int nSkin) {
	g_pCore->F()->SetPlayerSkin(m_nPlayerId, nSkin);
}

void CPlayer::SetColour(CRGB * pColour) {
	// TODO
}

void CPlayer::SetMoney(int nMoney) {
	g_pCore->F()->SetPlayerMoney(m_nPlayerId, nMoney);
}

void CPlayer::SetScore(int nScore) {
	g_pCore->F()->SetPlayerScore(m_nPlayerId, nScore);
}

void CPlayer::SetImmunity(unsigned int uiImmunityFlags) {
	g_pCore->F()->SetPlayerImmunityFlags(m_nPlayerId, uiImmunityFlags);
}

void CPlayer::SetHeading(float fHeading) {
	g_pCore->F()->SetPlayerHeading(m_nPlayerId, fHeading);
}

void CPlayer::SetVehicle(CVehicle * pVehicle) {
	// TODO
}

void CPlayer::SetWeaponSlot(int nSlot) {
	g_pCore->F()->SetPlayerWeaponSlot(m_nPlayerId, nSlot);
}

void CPlayer::SetSpectateTarget(CPlayer * pTarget) {
	g_pCore->F()->SetPlayerSpectateTarget(m_nPlayerId, (pTarget ? pTarget->GetID() : -1));
}

void CPlayer::SetWeapon(int nWeapon) {
	g_pCore->F()->SetPlayerWeapon(m_nPlayerId, nWeapon, 25000);
}

void CPlayer::SetWeaponAmmo(int nWeaponAmmo) {
	g_pCore->F()->SetPlayerWeapon(m_nPlayerId, GetWeapon(), nWeaponAmmo);
}

void CPlayer::SetSpeed(CVector * pSpeed) {
	// TODO
}

void CPlayer::SetWantedLevel(int nWantedLevel) {
	g_pCore->F()->SetPlayerWantedLevel(m_nPlayerId, nWantedLevel);
}

void CPlayer::SetCameraPos(CVector * pCamPos, CVector * pLookPos) {
	// TODO
}

void CPlayer::LegacySetAnim(int nAnim) {
	g_pCore->F()->SetPlayerAnimation(m_nPlayerId, 0, nAnim);
}

void CPlayer::SetAnim(int nAnimGroup, int nAnim) {
	g_pCore->F()->SetPlayerAnimation(m_nPlayerId, nAnimGroup, nAnim);
}

void CPlayer::GiveWeapon(int nWeapon, int nAmmo) {
	g_pCore->F()->GivePlayerWeapon(m_nPlayerId, nWeapon, nAmmo);
}

void CPlayer::SetWeapon(int nWeapon, int nAmmo) {
	g_pCore->F()->SetPlayerWeapon(m_nPlayerId, nWeapon, nAmmo);
}

void CPlayer::RemoveWeapon(int nWeapon) {
	g_pCore->F()->RemovePlayerWeapon(m_nPlayerId, nWeapon);
}

void CPlayer::SetAlpha(int nAlpha, int nFadeTime) {
	g_pCore->F()->SetPlayerAlpha(m_nPlayerId, nAlpha, nFadeTime);
}

bool CPlayer::Redirect(const SQChar * pszIp, unsigned int usPort, const SQChar * pszNickname, const SQChar * pszSrvPass, const SQChar * pszUserPass) {
	return g_pCore->F()->RedirectPlayerToServer(m_nPlayerId, pszIp, usPort, pszNickname, pszSrvPass, pszUserPass) == 1;
}

void CPlayer::SetAdmin(bool bToggle) {
	g_pCore->F()->SetPlayerAdmin(m_nPlayerId, bToggle);
}

void CPlayer::SetFrozen(bool bToggle) {
	g_pCore->F()->TogglePlayerControllable(m_nPlayerId, !bToggle);
}

void CPlayer::SetWhiteScanlines(bool bToggle) {
	g_pCore->F()->TogglePlayerWhiteScanlines(m_nPlayerId, bToggle);
}

void CPlayer::SetGreenScanlines(bool bToggle) {
	g_pCore->F()->TogglePlayerGreenScanlines(m_nPlayerId, bToggle);
}

void CPlayer::SetWidescreen(bool bToggle) {
	g_pCore->F()->TogglePlayerWidescreen(m_nPlayerId, bToggle);
}

void CPlayer::SetOnRadar(bool bToggle) {
	g_pCore->F()->TogglePlayerHasMarker(m_nPlayerId, bToggle);
}

void CPlayer::SetCanAttack(bool bToggle) {
	g_pCore->F()->TogglePlayerAttackPriv(m_nPlayerId, bToggle);
}

void CPlayer::SetCanSeeMarkers(bool bToggle) {
	g_pCore->F()->TogglePlayerShowMarkers(m_nPlayerId, bToggle);
}

void CPlayer::SetCanUseColors(bool bToggle) {
	g_pCore->F()->TogglePlayerChatTagsEnabled(m_nPlayerId, bToggle);
}

void CPlayer::SetDrunkStatus(bool bToggle) {
	g_pCore->F()->TogglePlayerDrunkEffects(m_nPlayerId, bToggle);
}

const SQChar * CPlayer::GetName(void) {
	g_pCore->F()->GetPlayerName(m_nPlayerId, m_szPlayerName, 25);
	return m_szPlayerName;
}

CVector * CPlayer::GetPosition(void) {
	// TODO
	return NULL;
}

float CPlayer::GetHealth(void) {
	return g_pCore->F()->GetPlayerHealth(m_nPlayerId);
}

float CPlayer::GetArmour(void) {
	return g_pCore->F()->GetPlayerArmour(m_nPlayerId);
}

int CPlayer::GetWorld(void) {
	return g_pCore->F()->GetPlayerWorld(m_nPlayerId);
}

int CPlayer::GetSecondaryWorld(void) {
	return g_pCore->F()->GetPlayerSecWorld(m_nPlayerId);
}

int CPlayer::GetTeam(void) {
	return g_pCore->F()->GetPlayerTeam(m_nPlayerId);
}

int CPlayer::GetSkin(void) {
	return g_pCore->F()->GetPlayerSkin(m_nPlayerId);
}

CRGB * CPlayer::GetColour(void) {
	// TODO
	return NULL;
}

int CPlayer::GetMoney(void) {
	return g_pCore->F()->GetPlayerMoney(m_nPlayerId);
}

int CPlayer::GetScore(void) {
	return g_pCore->F()->GetPlayerScore(m_nPlayerId);
}

unsigned int CPlayer::GetImmunity(void) {
	return g_pCore->F()->GetPlayerImmunityFlags(m_nPlayerId);
}

float CPlayer::GetHeading(void) {
	return g_pCore->F()->GetPlayerHeading(m_nPlayerId);
}

CVehicle * CPlayer::GetVehicle(void)
{
	// TODO
	return NULL;
}

int CPlayer::GetWeaponSlot(void) {
	return g_pCore->F()->GetPlayerWeaponSlot(m_nPlayerId);
}

CPlayer * CPlayer::GetSpectateTarget(void) {
	// TODO
	return NULL;
}

int CPlayer::GetWeapon(void) {
	return g_pCore->F()->GetPlayerWeapon(m_nPlayerId);
}

int CPlayer::GetWeaponAmmo(void) {
	return g_pCore->F()->GetPlayerWeaponAmmo(m_nPlayerId);
}

CVector * CPlayer::GetSpeed(void) {
	// TODO
	return NULL;
}

bool CPlayer::GetAdmin(void) {
	return g_pCore->F()->IsPlayerAdmin(m_nPlayerId) == 1;
}

bool CPlayer::GetFrozen(void) {
	return g_pCore->F()->EnabledPlayerControllable(m_nPlayerId) == 0;
}

bool CPlayer::GetWhiteScanlines(void) {
	return g_pCore->F()->EnabledPlayerWhiteScanlines(m_nPlayerId) == 1;
}

bool CPlayer::GetGreenScanlines(void) {
	return g_pCore->F()->EnabledPlayerGreenScanlines(m_nPlayerId) == 1;
}

bool CPlayer::GetWidescreen(void) {
	return g_pCore->F()->EnabledPlayerWidescreen(m_nPlayerId) == 1;
}

bool CPlayer::GetOnRadar(void) {
	return g_pCore->F()->EnabledPlayerHasMarker(m_nPlayerId) == 1;
}

bool CPlayer::GetCanAttack(void) {
	return g_pCore->F()->EnabledPlayerAttackPriv(m_nPlayerId) == 1;
}

bool CPlayer::GetCanSeeMarkers(void) {
	return g_pCore->F()->EnabledPlayerShowMarkers(m_nPlayerId) == 1;
}

bool CPlayer::GetCanUseColors(void) {
	return g_pCore->F()->EnabledPlayerChatTags(m_nPlayerId) == 1;
}

bool CPlayer::GetDrunkStatus(void) {
	return g_pCore->F()->EnabledPlayerDrunkEffects(m_nPlayerId) == 1;
}

const SQChar * CPlayer::GetIP(void) {
	g_pCore->F()->GetPlayerIP(m_nPlayerId, m_szPlayerIP, 16);
	return m_szPlayerIP;
}

bool CPlayer::GetSpawned(void) {
	return g_pCore->F()->IsPlayerSpawned(m_nPlayerId) == 1;
}

int CPlayer::GetUniqueWorld(void) {
	return g_pCore->F()->GetPlayerUniqueWorld(m_nPlayerId);
}

int CPlayer::GetState(void) {
	return g_pCore->F()->GetPlayerState(m_nPlayerId);
}

int CPlayer::GetPing(void) {
	return g_pCore->F()->GetPlayerPing(m_nPlayerId);
}

int CPlayer::GetVehicleSlot(void) {
	return g_pCore->F()->GetPlayerInVehicleSlot(m_nPlayerId);
}

int CPlayer::GetVehicleStatus(void) {
	return g_pCore->F()->GetPlayerInVehicleStatus(m_nPlayerId);
}

int CPlayer::GetAlpha(void) {
	return g_pCore->F()->GetPlayerAlpha(m_nPlayerId);
}

int CPlayer::GetKey(void) {
	return g_pCore->F()->GetPlayerKey(m_nPlayerId);
}

double CPlayer::GetFPS(void) {
	return g_pCore->F()->GetPlayerFPS(m_nPlayerId);
}

const SQChar * CPlayer::GetUniqueID(void) {
	g_pCore->F()->GetPlayerUID(m_nPlayerId, m_szPlayerHWID, 41);
	return m_szPlayerHWID;
}

int CPlayer::GetPlayerAction(void) {
	return g_pCore->F()->GetPlayerAction(m_nPlayerId);
}

int CPlayer::GetPlayerGameKeys(void) {
	return g_pCore->F()->GetPlayerGameKeys(m_nPlayerId);
}

CVector * CPlayer::GetPlayerAimDir(void) {
	// TODO
	return NULL;
}

CVector * CPlayer::GetPlayerAimPos(void) {
	// TODO
	return NULL;
}

CVehicle * CPlayer::GetVehicleStandingOn(void) {
	// TODO
	return NULL;
}

CObject * CPlayer::GetObjectStandingOn(void) {
	// TODO
	return NULL;
}

bool CPlayer::GetTypingStatus(void) {
	return g_pCore->F()->IsPlayerTyping(m_nPlayerId) == 1;
}

bool CPlayer::GetIdleStatus(void) {
	return g_pCore->F()->IsPlayerAway(m_nPlayerId) == 1;
}

bool CPlayer::GetPlayerOnFireStatus(void) {
	return g_pCore->F()->GetPlayerOnFireStatus(m_nPlayerId) == 1;
}

bool CPlayer::GetPlayerCrouchStatus(void) {
	return g_pCore->F()->GetPlayerCrouchStatus(m_nPlayerId) == 1;
}

void CPlayer::Kick(void) {
	g_pCore->F()->KickPlayer(m_nPlayerId);
}

void CPlayer::Ban(void) {
	g_pCore->F()->BanPlayer(m_nPlayerId);
}

void CPlayer::Spawn(void) {
	g_pCore->F()->ForcePlayerSpawn(m_nPlayerId);
}

void CPlayer::Eject(void) {
	g_pCore->F()->RemovePlayerFromVehicle(m_nPlayerId);
}

void CPlayer::Disarm(void) {
	g_pCore->F()->RemoveAllWeapons(m_nPlayerId);
}

void CPlayer::Select(void) {
	g_pCore->F()->ForcePlayerSelect(m_nPlayerId);
}

void CPlayer::RestoreCamera(void) {
	g_pCore->F()->RestoreCamera(m_nPlayerId);
}

void CPlayer::RemoveMarker(void) {
	SetOnRadar(false);
}

int CPlayer::GetWeaponAtSlot(int nSlot) {
	return g_pCore->F()->GetPlayerWeaponAtSlot(m_nPlayerId, nSlot);
}

int CPlayer::GetAmmoAtSlot(int nSlot) {
	return g_pCore->F()->GetPlayerAmmoAtSlot(m_nPlayerId, nSlot);
}

bool CPlayer::GetStreamedToPlayer(CPlayer * pOther) {
	if (pOther) return g_pCore->F()->IsPlayerStreamedForPlayer(m_nPlayerId, pOther->GetID()) == 1;
	else return false;
}

void CPlayer::GiveMoney(int nMoney) {
	g_pCore->F()->GivePlayerMoney(m_nPlayerId, nMoney);
}

void CPlayer::AddSpeed(CVector * pSpeed) {
	// TODO
}