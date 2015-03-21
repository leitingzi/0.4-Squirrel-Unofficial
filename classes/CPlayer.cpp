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

#include "../structures/CRGB.h"
#include "../structures/CVector.h"
#include "../Main.h"
#include "CPlayer.h"

void CPlayer::Register(HSQUIRRELVM v) {
	Sqrat::Class<CPlayer> c(v, "CPlayer");

	c
		.Prop(_SC("Admin"), &CPlayer::GetAdmin, &CPlayer::SetAdmin)
		.Prop(_SC("Angle"), &CPlayer::GetHeading, &CPlayer::SetHeading)
		.Prop(_SC("Armor"), &CPlayer::GetArmour, &CPlayer::SetArmour)
		.Prop(_SC("Armour"), &CPlayer::GetArmour, &CPlayer::SetArmour)
		.Prop(_SC("CanAttack"), &CPlayer::GetCanAttack, &CPlayer::SetCanAttack)
		.Prop(_SC("CanDriveby"), &CPlayer::GetDrivebyEnabled, &CPlayer::SetDrivebyEnabled)
		.Prop(_SC("CanSeeMarkers"), &CPlayer::GetCanSeeMarkers, &CPlayer::SetCanSeeMarkers)
		.Prop(_SC("Cash"), &CPlayer::GetMoney, &CPlayer::SetMoney)
		.Prop(_SC("Color"), &CPlayer::GetColour, &CPlayer::SetColour)
		.Prop(_SC("Colour"), &CPlayer::GetColour, &CPlayer::SetColour)
		// I don't like this next name and might remove it later.
		.Prop(_SC("DrivebyAbility"), &CPlayer::GetDrivebyEnabled, &CPlayer::SetDrivebyEnabled)
		.Prop(_SC("Frozen"), &CPlayer::GetFrozen, &CPlayer::SetFrozen)
		.Prop(_SC("GreenScanlines"), &CPlayer::GetGreenScanlines, &CPlayer::SetGreenScanlines)
		.Prop(_SC("HasChatTags"), &CPlayer::GetCanUseColors, &CPlayer::SetCanUseColors)
		.Prop(_SC("Heading"), &CPlayer::GetHeading, &CPlayer::SetHeading)
		.Prop(_SC("Health"), &CPlayer::GetHealth, &CPlayer::SetHealth)
		.Prop(_SC("Immunity"), &CPlayer::GetImmunity, &CPlayer::SetImmunity)
		.Prop(_SC("IsAdmin"), &CPlayer::GetAdmin, &CPlayer::SetAdmin)
		.Prop(_SC("IsDrunk"), &CPlayer::GetDrunkStatus, &CPlayer::SetDrunkStatus)
		.Prop(_SC("IsFrozen"), &CPlayer::GetFrozen, &CPlayer::SetFrozen)
		.Prop(_SC("IsOnRadar"), &CPlayer::GetOnRadar, &CPlayer::SetOnRadar)
		.Prop(_SC("IsWeaponSyncBlocked"), &CPlayer::GetCanAttack, &CPlayer::SetCanAttack)
		.Prop(_SC("Name"), &CPlayer::GetName, &CPlayer::SetName)
		.Prop(_SC("Pos"), &CPlayer::GetPosition, &CPlayer::SetPosition)
		.Prop(_SC("Score"), &CPlayer::GetScore, &CPlayer::SetScore)
		.Prop(_SC("SecWorld"), &CPlayer::GetSecondaryWorld, &CPlayer::SetSecondaryWorld)
		.Prop(_SC("ShowMarkers"), &CPlayer::GetCanSeeMarkers, &CPlayer::SetCanSeeMarkers)
		.Prop(_SC("Skin"), &CPlayer::GetSkin, &CPlayer::SetSkin)
		.Prop(_SC("SpectateTarget"), &CPlayer::GetSpectateTarget, &CPlayer::SetSpectateTarget)
		.Prop(_SC("Speed"), &CPlayer::GetSpeed, &CPlayer::SetSpeed)
		.Prop(_SC("Team"), &CPlayer::GetTeam, &CPlayer::SetTeam)
		//.Prop(_SC("Vehicle"), &CPlayer::GetVehicle, &CPlayer::SetVehicle)
		.Prop(_SC("WantedLevel"), &CPlayer::GetWantedLevel, &CPlayer::SetWantedLevel)
		.Prop(_SC("Weapon"), &CPlayer::GetWeapon, &CPlayer::SetWeapon)
		.Prop(_SC("WeaponAmmo"), &CPlayer::GetWeaponAmmo, &CPlayer::SetWeaponAmmo)
		.Prop(_SC("WeaponSlot"), &CPlayer::GetWeaponSlot, &CPlayer::SetWeaponSlot)
		.Prop(_SC("WhiteScanlines"), &CPlayer::GetWhiteScanlines, &CPlayer::SetWhiteScanlines)
		.Prop(_SC("Widescreen"), &CPlayer::GetWidescreen, &CPlayer::SetWidescreen)
		.Prop(_SC("World"), &CPlayer::GetWorld, &CPlayer::SetWorld)

		.Prop(_SC("Action"), &CPlayer::GetPlayerAction)
		.Prop(_SC("Away"), &CPlayer::GetIdleStatus)
		.Prop(_SC("AimDir"), &CPlayer::GetPlayerAimDir)
		.Prop(_SC("AimPos"), &CPlayer::GetPlayerAimPos)
		.Prop(_SC("Alpha"), &CPlayer::GetAlpha)
		.Prop(_SC("FPS"), &CPlayer::GetFPS)
		.Prop(_SC("GameKeys"), &CPlayer::GetPlayerGameKeys)
		.Prop(_SC("ID"), &CPlayer::GetID)
		.Prop(_SC("IP"), &CPlayer::GetIP)
		.Prop(_SC("IsAway"), &CPlayer::GetIdleStatus)
		.Prop(_SC("IsCrouching"), &CPlayer::GetPlayerCrouchStatus)
		.Prop(_SC("IsOnFire"), &CPlayer::GetPlayerOnFireStatus)
		.Prop(_SC("IsSpawned"), &CPlayer::GetSpawned)
		.Prop(_SC("IsTyping"), &CPlayer::GetTypingStatus)
		.Prop(_SC("Key"), &CPlayer::GetKey)
		.Prop(_SC("Ping"), &CPlayer::GetPing)
		.Prop(_SC("Spawned"), &CPlayer::GetSpawned)
		//.Prop(_SC("StandingOnObject"), &CPlayer::GetObjectStandingOn)
		//.Prop(_SC("StandingOnVehicle"), &CPlayer::GetVehicleStandingOn)
		.Prop(_SC("State"), &CPlayer::GetState)
		.Prop(_SC("Typing"), &CPlayer::GetTypingStatus)
		.Prop(_SC("UniqueID"), &CPlayer::GetUniqueID)
		.Prop(_SC("UniqueWorld"), &CPlayer::GetUniqueWorld)
		.Prop(_SC("VehicleSlot"), &CPlayer::GetVehicleSlot)
		.Prop(_SC("VehicleStatus"), &CPlayer::GetVehicleStatus)

		.Func(_SC("AddSpeed"), &CPlayer::AddSpeed)
		.Func(_SC("Ban"), &CPlayer::Ban)
		.Func(_SC("Disarm"), &CPlayer::Disarm)
		.Func(_SC("GetAmmoAtSlot"), &CPlayer::GetAmmoAtSlot)
		.Func(_SC("GetWeaponAtSlot"), &CPlayer::GetWeaponAtSlot)
		.Func(_SC("Eject"), &CPlayer::Eject)
		.Func(_SC("GiveMoney"), &CPlayer::GiveMoney)
		.Func(_SC("GiveWeapon"), &CPlayer::GiveWeapon)
		.Func(_SC("Kick"), &CPlayer::Kick)
		.Func(_SC("Redirect"), &CPlayer::Redirect)
		.Func(_SC("RemoveMarker"), &CPlayer::RemoveMarker)
		.Func(_SC("RemoveWeapon"), &CPlayer::RemoveWeapon)
		.Func(_SC("RestoreCamera"), &CPlayer::RestoreCamera)
		.Func(_SC("Select"), &CPlayer::Select)
		.Func(_SC("SetAlpha"), &CPlayer::SetAlpha)
		.Overload(_SC("SetAnim"), &CPlayer::LegacySetAnim)
		.Overload(_SC("SetAnim"), &CPlayer::SetAnim)
		.Func(_SC("SetCameraPos"), &CPlayer::SetCameraPos)
		.Func(_SC("SetWantedLevel"), &CPlayer::SetWantedLevel)
		.Func(_SC("SetWeapon"), &CPlayer::SetWeaponLegacy)
		.Func(_SC("Spawn"), &CPlayer::Spawn)
		.Func(_SC("StreamedToPlayer"), &CPlayer::GetStreamedToPlayer);

	Sqrat::RootTable(v).Bind(_SC("CPlayer"), c);
}

void CPlayer::Delete(void) { Kick(); }
void CPlayer::SetName(const SQChar * pszNewName) {
	g_pCore->F()->SetPlayerName(m_nPlayerId, pszNewName);
}

void CPlayer::SetPosition(CVector * pPos) {
	g_pCore->F()->SetPlayerPos(m_nPlayerId, pPos->GetX(), pPos->GetY(), pPos->GetZ());
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
	g_pCore->F()->SetPlayerColour(m_nPlayerId, pColour->ToInt());
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
	g_pCore->F()->SetPlayerSpeed(m_nPlayerId, pSpeed->GetX(), pSpeed->GetY(), pSpeed->GetZ());
}

void CPlayer::SetWantedLevel(int nWantedLevel) {
	g_pCore->F()->SetPlayerWantedLevel(m_nPlayerId, nWantedLevel);
}

void CPlayer::SetCameraPos(CVector * pCamPos, CVector * pLookPos) {
	g_pCore->F()->SetCameraPosition(m_nPlayerId,
		pCamPos->GetX(), pCamPos->GetY(), pCamPos->GetZ(),
		pLookPos->GetX(), pLookPos->GetY(), pLookPos->GetZ()
	);
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

void CPlayer::SetWeaponLegacy(int nWeapon, int nAmmo) {
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

void CPlayer::SetDrivebyEnabled(bool bToggle) {
	g_pCore->F()->TogglePlayerDriveby(m_nPlayerId, bToggle);
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

CVector CPlayer::GetPosition(void) {
	float x, y, z;
	g_pCore->F()->GetPlayerPos(m_nPlayerId, &x, &y, &z);

	return CVector(x, y, z);
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

CRGB CPlayer::GetColour(void) {
	unsigned int ulColour = g_pCore->F()->GetPlayerColour(m_nPlayerId);
	return CRGB(ulColour);
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

CVector CPlayer::GetSpeed(void) {
	float x, y, z;
	g_pCore->F()->GetPlayerSpeed(m_nPlayerId, &x, &y, &z);
	
	return CVector(x, y, z);
}

int CPlayer::GetWantedLevel(void) {
	return g_pCore->F()->GetPlayerWantedLevel(m_nPlayerId);
}

bool CPlayer::GetAdmin(void) {
	return g_pCore->F()->IsPlayerAdmin(m_nPlayerId) == 1;
}

bool CPlayer::GetFrozen(void) {
	return g_pCore->F()->EnabledPlayerControllable(m_nPlayerId) == 0;
}

bool CPlayer::GetDrivebyEnabled(void) {
	return g_pCore->F()->EnabledPlayerDriveby(m_nPlayerId) == 1;
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

CVector CPlayer::GetPlayerAimDir(void) {
	float x, y, z;
	g_pCore->F()->GetPlayerAimDir(m_nPlayerId, &x, &y, &z);

	return CVector(x, y, z);
}

CVector CPlayer::GetPlayerAimPos(void) {
	float x, y, z;
	g_pCore->F()->GetPlayerAimPos(m_nPlayerId, &x, &y, &z);

	return CVector(x, y, z);
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
	g_pCore->F()->AddPlayerSpeed(m_nPlayerId, pSpeed->GetX(), pSpeed->GetY(), pSpeed->GetZ());
}