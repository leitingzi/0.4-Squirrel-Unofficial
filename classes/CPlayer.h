/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CPlayer.h

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

#pragma once
#include <squirrel.h>
#include "IEntity.h"

class CObject;
class CRGB;
class CVector;
class CVehicle;

class CPlayer : public IEntity
{
	public:
		CPlayer(int nPlayerId) {
			m_nPlayerId = nPlayerId;
		}

		int GetID(void) { return m_nPlayerId; }
		void Delete(void);

	public:
		static void Register(HSQUIRRELVM v);

		void SetName(const SQChar * pszNewName);
		void SetPosition(CVector * pPos);
		void SetHealth(float fHealth);
		void SetArmour(float fArmour);
		void SetWorld(int nWorld);
		void SetSecondaryWorld(int nWorld);
		void SetTeam(int nTeam);
		void SetSkin(int nSkin);
		void SetColour(CRGB * pColour);
		void SetMoney(int nMoney);
		void SetScore(int nScore);
		void SetImmunity(unsigned int uiImmunityFlags);
		void SetHeading(float fHeading);
		void SetVehicle(CVehicle * pVehicle);
		void SetWeaponSlot(int nSlot);
		void SetSpectateTarget(CPlayer * pTarget);
		void SetWeapon(int nWeapon);
		void SetWeaponAmmo(int nWeaponAmmo);
		void SetSpeed(CVector * pSpeed);

		void SetAdmin(bool bToggle);
		void SetFrozen(bool bToggle);
		void SetDrivebyEnabled(bool bToggle);
		void SetWhiteScanlines(bool bToggle);
		void SetGreenScanlines(bool bToggle);
		void SetWidescreen(bool bToggle);
		void SetOnRadar(bool bToggle);
		void SetCanAttack(bool bToggle);
		void SetCanSeeMarkers(bool bToggle);
		void SetCanUseColors(bool bToggle);
		void SetDrunkStatus(bool bToggle);

		const SQChar * GetName(void);
		CVector * GetPosition(void);
		float GetHealth(void);
		float GetArmour(void);
		int GetWorld(void);
		int GetSecondaryWorld(void);
		int GetTeam(void);
		int GetSkin(void);
		CRGB * GetColour(void);
		int GetMoney(void);
		int GetScore(void);
		unsigned int GetImmunity(void);
		float GetHeading(void);
		CVehicle * GetVehicle(void);
		int GetWeaponSlot(void);
		CPlayer * GetSpectateTarget(void);
		int GetWeapon(void);
		int GetWeaponAmmo(void);
		CVector * GetSpeed(void);

		bool GetAdmin(void);
		bool GetFrozen(void);
		bool GetDrivebyEnabled(void);
		bool GetWhiteScanlines(void);
		bool GetGreenScanlines(void);
		bool GetWidescreen(void);
		bool GetOnRadar(void);
		bool GetCanAttack(void);
		bool GetCanSeeMarkers(void);
		bool GetCanUseColors(void);
		bool GetDrunkStatus(void);

		const SQChar * GetIP(void);
		bool GetSpawned(void);
		int GetUniqueWorld(void);
		int GetState(void);
		int GetPing(void);
		int GetVehicleSlot(void);
		int GetVehicleStatus(void);
		int GetAlpha(void);
		int GetKey(void);
		double GetFPS(void);
		const SQChar * GetUniqueID(void);
		int GetPlayerAction(void);
		int GetPlayerGameKeys(void);
		CVector * GetPlayerAimDir(void);
		CVector * GetPlayerAimPos(void);
		CVehicle * GetVehicleStandingOn(void);
		CObject * GetObjectStandingOn(void);

		bool GetTypingStatus(void);
		bool GetIdleStatus(void);
		bool GetPlayerOnFireStatus(void);
		bool GetPlayerCrouchStatus(void);

		void Kick(void);
		void Ban(void);
		void Spawn(void);
		void Eject(void);
		void Disarm(void);
		void Select(void);
		void RestoreCamera(void);
		void RemoveMarker(void);

		int GetWeaponAtSlot(int nSlot);
		int GetAmmoAtSlot(int nSlot);
		bool GetStreamedToPlayer(CPlayer * pOther);

		void GiveMoney(int nMoney);
		void AddSpeed(CVector * pSpeed);
		void SetWantedLevel(int nWantedLevel);
		void SetCameraPos(CVector * pCamPos, CVector * pLookPos);
		void LegacySetAnim(int nAnim);
		void SetAnim(int nAnimGroup, int nAnim);
		void GiveWeapon(int nWeapon, int nAmmo);
		void SetWeapon(int nWeapon, int nAmmo);
		void RemoveWeapon(int nWeapon);
		void SetAlpha(int nAlpha, int nFadeTime);
		bool Redirect(const SQChar * pszIp, unsigned int usPort, const SQChar * pszNickname, const SQChar * pszSrvPass, const SQChar * pszUserPass);
		
	private:
		int m_nPlayerId;
		char m_szPlayerName[25];
		char m_szPlayerIP[16];
		char m_szPlayerHWID[41];
};