/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CEntityFunctions.h

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
#include <stdint.h>

class CObject;
class CPickup;
class CPlayer;
class CSprite;
class CTextdraw;
class CVector;
class CVehicle;

class CEntityFunctions
{
	public:
		static int GetPlayerIDFromName(const SQChar * pszName);
		static bool IsWorldCompatibleWithPlayer(CPlayer * pPlayer, int nWorld);

		static CPickup * CreatePickupLegacy(int nModel, CVector * pPos);
		static CVehicle * CreateVehicleLegacy(int nModel, CVector * pPos, float fAngle, int nCol1, int nCol2);

		static CObject * CreateObject(int nModel, int nWorld, CVector * pPos, int nAlpha);
		static CPickup * CreatePickup(int nModel, int nWorld, int nQuantity, CVector * pPos, int nAlpha, bool bIsAuto);
		static CSprite * CreateSprite(const SQChar * pszFilename, uint16_t x, uint16_t y, uint16_t rX, uint16_t rY, float fRot, uint16_t nAlpha);
		static CTextdraw * CreateTextdraw(const SQChar * pszText, int x, int y, unsigned int uiColour);
		static CVehicle * CreateVehicle(int nModel, int nWorld, CVector * pPos, float fAngle, int nCol1, int nCol2);

		static CObject * FindObject(int nId);
		static CPickup * FindPickup(int nId);
		static SQInteger FindPlayer(HSQUIRRELVM v);
		static CVehicle * FindVehicle(int nId);

		static void ForceAllSelect(void);

		static void ResetAllVehicleHandling(void);
		static bool IsHandlingRuleSet(int nVehModel, int nRule);
		static void SetHandlingRule(int nVehModel, int nRule, float fValue);
		static double GetHandlingRule(int nVehModel, int nRule);
		static void ResetHandlingRule(int nModel, int nRule);
		static void ResetVehicleHandling(int nModel);

		static int GetObjectCount(void);
		static int GetPickupCount(void);
		static int GetVehicleCount(void);
		static int GetPlayers(void);
};