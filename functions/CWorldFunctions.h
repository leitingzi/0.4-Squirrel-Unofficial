/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CWorldFunctions.h

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
class CBounds;
class CPlayer;
class CRGB;
class CVector;
class CWastedSettings;

class CWorldFunctions
{
	public:
		static void SetTimeRate(unsigned int nTimeRate);
		static void SetHour(int nHour);
		static void SetMinute(int nMinute);
		static void SetTime(int nHour, int nMinute);
		static void SetWeather(int nWeather);
		static void SetGravity(float fGravity);
		static void SetGamespeed(float fSpeed);
		static void SetWaterLevel(float fHeight);
		static void SetMaxHeight(float fHeight);

		static unsigned int GetTimeRate(void);
		static int GetHour(void);
		static int GetMinute(void);
		static int GetWeather(void);
		static float GetGravity(void);
		static float GetGamespeed(void);
		static float GetWaterLevel(void);
		static float GetMaxHeight(void);
		
		static void CreateExplosion(int nWorld, int nType, CVector * pPos, int nPlayerBlamed, bool bOnGround);
		static void PlayGameSound(CPlayer * pPlayer, int nSound, CVector * pPos);

		static void SetWorldBounds(float fMaxX, float fMinX, float fMaxY, float fMinY);
		static CBounds GetWorldBounds(void);

		static void SetWastedSettings(int nDeathTime, int nFadeTime, float fFadeInSpeed, float fFadeOutSpeed, CRGB colour, int nCorpseFadeDelay, int nCorpseFadeTime);
		static CWastedSettings GetWastedSettings(void);

		static void RawHideMapObject(int nModelId, int x, int y, int z);
		static void HideMapObject(int nModelId, CVector * pPos);
		static void ShowMapObject(int nModelId, CVector * pPos);
		static void ShowAllMapObjects(void);

		static bool SetWeaponDataValue(int nWeaponId, int nFieldId, double dValue);
		static double GetWeaponDataValue(int nWeaponId, int nFieldId);
		static bool ResetWeaponDataValue(int nWeaponId, int nFieldId);
		static bool IsWeaponDataModified(int nWeaponId, int nFieldId);
		static bool ResetWeaponData(int nWeaponId);
		static bool ResetAllWeaponData(void);
};