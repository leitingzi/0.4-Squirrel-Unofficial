/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CRuleFunctions.h

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

class CRuleFunctions
{
	public:
		static void Register(HSQUIRRELVM v);

		static void SetSyncFrameLimiter(bool bToggle);
		static void SetFrameLimiter(bool bToggle);
		static void SetTaxiBoostJump(bool bToggle);
		static void SetDriveOnWater(bool bToggle);
		static void SetFastSwitch(bool bToggle);
		static void SetFriendlyFire(bool bToggle);
		static void SetDrivebyEnabled(bool bToggle);
		static void SetPerfectHandling(bool bToggle);
		static void SetFlyingCars(bool bToggle);
		static void SetJumpSwitch(bool bToggle);
		static void SetShowOnRadar(bool bToggle);
		static void SetStuntBike(bool bToggle);
		static void SetShootInAir(bool bToggle);
		static void SetShowNametags(bool bToggle);
		static void SetJoinMessages(bool bToggle);
		static void SetDeathMessages(bool bToggle);

		static bool GetSyncFrameLimiter(void);
		static bool GetFrameLimiter(void);
		static bool GetTaxiBoostJump(void);
		static bool GetDriveOnWater(void);
		static bool GetFastSwitch(void);
		static bool GetFriendlyFire(void);
		static bool GetDrivebyEnabled(void);
		static bool GetPerfectHandling(void);
		static bool GetFlyingCars(void);
		static bool GetJumpSwitch(void);
		static bool GetShowOnRadar(void);
		static bool GetStuntBike(void);
		static bool GetShootInAir(void);
		static bool GetShowNametags(void);
		static bool GetJoinMessages(void);
		static bool GetDeathMessages(void);
};