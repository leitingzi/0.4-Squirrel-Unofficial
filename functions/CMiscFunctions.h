/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CMiscFunctions.h

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

class CMiscFunctions
{
	public:
		static int CreateRadioStream(const SQChar * pszRadioName, const SQChar * pszRadioURL, bool bCanSelect);
		static void DestroyRadioStream(int nRadioID);

		static int BindKey(bool bIsOnKeyDown, int nKey1, int nKey2 = 0, int nKey3 = 0);
		static bool RemoveKeybind(int nBindId);
		static void RemoveAllKeybinds(void);

		static const SQChar * GetWeaponName(int nWeaponId);
		static const SQChar * GetDistrictName(float fX, float fY);
		static const SQChar * GetSkinName(int nSkinId);

		static int GetWeaponID(const SQChar * pszName);
		static unsigned int GetTickCount(void);

		static float DistanceFromPoint(float fX1, float fY1, float fX2, float fY2);
		static SQInteger ReloadScripts(HSQUIRRELVM v);

		static int GetVehicleModelFromName(SQChar * pszName);
		static const SQChar * GetVehicleNameFromModel(int nModel);

		static bool IsNum(const SQChar * pszLine);
};