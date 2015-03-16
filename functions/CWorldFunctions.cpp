/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CWorldFunctions.cpp

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
#include "../structures/CBounds.h"
#include "../structures/CVector.h"
#include "../structures/CWastedSettings.h"
#include "CWorldFunctions.h"

void CWorldFunctions::Register(HSQUIRRELVM v) {
	Sqrat::RootTable(v)
		.Func(_SC("SetTimeRate"), SetTimeRate)
		.Func(_SC("SetHour"), SetHour)
		.Func(_SC("SetMinute"), SetMinute)
		.Func(_SC("SetTime"), SetTime)
		.Func(_SC("SetWeather"), SetWeather)
		.Func(_SC("SetGravity"), SetGravity)
		.Func(_SC("SetGamespeed"), SetGamespeed)
		.Func(_SC("SetWaterLevel"), SetWaterLevel)
		.Func(_SC("SetMaxHeight"), SetMaxHeight)

		.Func(_SC("GetTimeRate"), GetTimeRate)
		.Func(_SC("GetHour"), GetHour)
		.Func(_SC("GetMinute"), GetMinute)
		.Func(_SC("GetWeather"), GetWeather)
		.Func(_SC("GetGravity"), GetGravity)
		.Func(_SC("GetGamespeed"), GetGamespeed)
		.Func(_SC("GetWaterLevel"), GetWaterLevel)
		.Func(_SC("GetMaxHeight"), GetMaxHeight)

		.Func(_SC("CreateExplosion"), CreateExplosion)
		.Func(_SC("PlaySound"), PlayGameSound)

		.Overload(_SC("SetWorldBounds"), SetWorldBounds)
		.Overload(_SC("SetWorldBounds"), SetWorldBoundsWithInstance)
		.Func(_SC("GetWorldBounds"), GetWorldBounds)

		.Func(_SC("RawHideMapObject"), RawHideMapObject)
		.Func(_SC("RawShowMapObject"), RawShowMapObject)

		.Func(_SC("HideMapObject"), HideMapObject)
		.Func(_SC("ShowMapObject"), ShowMapObject)
		.Func(_SC("ShowAllMapObjects"), ShowAllMapObjects)

		.Func(_SC("SetWeaponDataValue"), SetWeaponDataValue)
		.Func(_SC("GetWeaponDataValue"), GetWeaponDataValue)
		.Func(_SC("ResetWeaponDataValue"), ResetWeaponDataValue)
		.Func(_SC("IsWeaponDataModified"), IsWeaponDataModified)
		.Func(_SC("ResetWeaponData"), ResetWeaponData)
		.Func(_SC("ResetAllWeaponData"), ResetAllWeaponData);
}

void CWorldFunctions::SetTimeRate(unsigned int nTimeRate) {
	g_pCore->F()->SetTimeRate(nTimeRate);
}

void CWorldFunctions::SetHour(int nHour) {
	g_pCore->F()->SetHour(nHour);
}

void CWorldFunctions::SetMinute(int nMinute) {
	g_pCore->F()->SetMinute(nMinute);
}

void CWorldFunctions::SetTime(int nHour, int nMinute) {
	SetHour(nHour);
	SetMinute(nMinute);
}

void CWorldFunctions::SetWeather(int nWeather) {
	g_pCore->F()->SetWeather(nWeather);
}

void CWorldFunctions::SetGravity(float fGravity) {
	g_pCore->F()->SetGravity(fGravity);
}

void CWorldFunctions::SetGamespeed(float fSpeed) {
	g_pCore->F()->SetGamespeed(fSpeed);
}

void CWorldFunctions::SetWaterLevel(float fHeight) {
	g_pCore->F()->SetWaterLevel(fHeight);
}

void CWorldFunctions::SetMaxHeight(float fHeight) {
	g_pCore->F()->SetMaxHeight(fHeight);
}

unsigned int CWorldFunctions::GetTimeRate(void) {
	return g_pCore->F()->GetTimeRate();
}

int CWorldFunctions::GetHour(void) {
	return g_pCore->F()->GetHour();
}

int CWorldFunctions::GetMinute(void) {
	return g_pCore->F()->GetMinute();
}

int CWorldFunctions::GetWeather(void) {
	return g_pCore->F()->GetWeather();
}

float CWorldFunctions::GetGravity(void) {
	return g_pCore->F()->GetGravity();
}

float CWorldFunctions::GetGamespeed(void) {
	return g_pCore->F()->GetGamespeed();
}

float CWorldFunctions::GetWaterLevel(void) {
	return g_pCore->F()->GetWaterLevel();
}

float CWorldFunctions::GetMaxHeight(void) {
	return g_pCore->F()->GetMaxHeight();
}

void CWorldFunctions::CreateExplosion(int nWorld, int nType, CVector * pPos, int nPlayerBlamed, bool bOnGround) {
	g_pCore->F()->CreateExplosion(nWorld, nType, VECTOREX(pPos),
		nPlayerBlamed, bOnGround);
}

void CWorldFunctions::PlayGameSound(int nWorld, int nSound, CVector * pPos) {
	g_pCore->F()->PlaySound(nWorld, nSound, VECTOREX(pPos));
}

void CWorldFunctions::SetWorldBounds(float fMaxX, float fMinX, float fMaxY, float fMinY) {
	g_pCore->F()->SetWorldBounds(fMaxX, fMinX, fMaxY, fMinY);
}

void CWorldFunctions::SetWorldBoundsWithInstance(CBounds sBounds) {
	SetWorldBounds(sBounds.maxX, sBounds.minX, sBounds.maxY, sBounds.minY);
}

CBounds CWorldFunctions::GetWorldBounds(void) {
	static CBounds sBounds;
	g_pCore->F()->GetWorldBounds(&sBounds.maxX, &sBounds.minX,
		&sBounds.maxY, &sBounds.minY);

	return sBounds;
}

/*void CWorldFunctions::SetWastedSettings(int nDeathTime, int nFadeTime, float fFadeInSpeed, float fFadeOutSpeed, CRGB colour, int nCorpseFadeDelay, int nCorpseFadeTime) {

}

void CWorldFunctions::SetWastedSettingsWithInstance(CWastedSettings sSettings) {

}

CWastedSettings CWorldFunctions::GetWastedSettings(void) {

}*/

void CWorldFunctions::RawHideMapObject(int nModelId, int x, int y, int z) {
	g_pCore->F()->HideMapObject(nModelId, x, y, z);
}

void CWorldFunctions::RawShowMapObject(int nModelId, int x, int y, int z) {
	g_pCore->F()->ShowMapObject(nModelId, x, y, z);
}

void CWorldFunctions::HideMapObject(int nModelId, CVector * pPos) {
	int x2 = (int)(floor(pPos->GetX() * 10.0f) + 0.5f);
	int y2 = (int)(floor(pPos->GetY() * 10.0f) + 0.5f);
	int z2 = (int)(floor(pPos->GetZ() * 10.0f) + 0.5f);

	RawHideMapObject(nModelId, x2, y2, z2);
}

void CWorldFunctions::ShowMapObject(int nModelId, CVector * pPos) {
	int x2 = (int)(floor(pPos->GetX() * 10.0f) + 0.5f);
	int y2 = (int)(floor(pPos->GetY() * 10.0f) + 0.5f);
	int z2 = (int)(floor(pPos->GetZ() * 10.0f) + 0.5f);

	g_pCore->F()->ShowMapObject(nModelId, x2, y2, z2);
}

void CWorldFunctions::ShowAllMapObjects(void) {
	g_pCore->F()->ShowAllMapObjects();
}

int CWorldFunctions::SetWeaponDataValue(int nWeaponId, int nFieldId, double dValue) {
	return g_pCore->F()->SetWeaponDataValue(nWeaponId, nFieldId, dValue);
}

double CWorldFunctions::GetWeaponDataValue(int nWeaponId, int nFieldId) {
	return g_pCore->F()->GetWeaponDataValue(nWeaponId, nFieldId);
}

int CWorldFunctions::ResetWeaponDataValue(int nWeaponId, int nFieldId) {
	return g_pCore->F()->ResetWeaponDataValue(nWeaponId, nFieldId);
}

bool CWorldFunctions::IsWeaponDataModified(int nWeaponId, int nFieldId) {
	return g_pCore->F()->IsWeaponDataValueModified(nWeaponId, nFieldId) == 1;
}

int CWorldFunctions::ResetWeaponData(int nWeaponId) {
	return g_pCore->F()->ResetWeaponData(nWeaponId);
}

int CWorldFunctions::ResetAllWeaponData(void) {
	return g_pCore->F()->ResetAllWeaponData();
}
