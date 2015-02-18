/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CRuleFunctions.cpp

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

// Personally, I think this file is a miracle and an atrocity of modern science. -stormeus

#include "../Main.h"
#include "CRuleFunctions.h"
#include <sqrat.h>
#include "..\classes\CPlayer.h"

#define REGISTER_TOGGLE(x) Sqrat::RootTable(v).Func(_SC("Set## x ##"), CRuleFunctions::Set ## x); \
	Sqrat::RootTable(v).Func(_SC("Get## x ##"), CRuleFunctions::Get ## x)

void CRuleFunctions::Register(HSQUIRRELVM v) {
	REGISTER_TOGGLE(DrivebyEnabled);
	REGISTER_TOGGLE(ShowOnRadar);
	REGISTER_TOGGLE(SyncFrameLimiter);
	REGISTER_TOGGLE(FrameLimiter);
	REGISTER_TOGGLE(TaxiBoostJump);
	REGISTER_TOGGLE(DriveOnWater);
	REGISTER_TOGGLE(FastSwitch);
	REGISTER_TOGGLE(FriendlyFire);
	REGISTER_TOGGLE(PerfectHandling);
	REGISTER_TOGGLE(FlyingCars);
	REGISTER_TOGGLE(JumpSwitch);
	REGISTER_TOGGLE(StuntBike);
	REGISTER_TOGGLE(ShootInAir);
	REGISTER_TOGGLE(ShowNametags);
	REGISTER_TOGGLE(JoinMessages);
	REGISTER_TOGGLE(DeathMessages);
	REGISTER_TOGGLE(ChatTagsByDefault);
}

void CRuleFunctions::SetDrivebyEnabled(bool bToggle) {
	g_pCore->F()->ToggleDisableDriveby(!bToggle);
}

bool CRuleFunctions::GetDrivebyEnabled(void) {
	return g_pCore->F()->EnabledDisableDriveby() == 0;
}

void CRuleFunctions::SetShowOnRadar(bool bToggle) {
	g_pCore->F()->ToggleShowMarkers(bToggle);
}

bool CRuleFunctions::GetShowOnRadar(void) {
	return g_pCore->F()->EnabledShowMarkers() == 1;
}

void CRuleFunctions::SetChatTagsByDefault(bool bToggle) {
	g_pCore->F()->ToggleChatTagsByDefaultEnabled(bToggle);
}

bool CRuleFunctions::GetChatTagsByDefault(void) {
	return g_pCore->F()->EnabledChatTagsByDefault() == 1;
}

#define IMPL_STDTOGGLE(x) void CRuleFunctions::Set ## x(bool bToggle) {\
	g_pCore->F()->Toggle ## x(bToggle); \
  } \
  \
  bool CRuleFunctions::Get ## x(void) {\
	return g_pCore->F()->Enabled ## x() == 1; \
  }

IMPL_STDTOGGLE(SyncFrameLimiter);
IMPL_STDTOGGLE(FrameLimiter);
IMPL_STDTOGGLE(TaxiBoostJump);
IMPL_STDTOGGLE(DriveOnWater);
IMPL_STDTOGGLE(FastSwitch);
IMPL_STDTOGGLE(FriendlyFire);
IMPL_STDTOGGLE(PerfectHandling);
IMPL_STDTOGGLE(FlyingCars);
IMPL_STDTOGGLE(JumpSwitch);
IMPL_STDTOGGLE(StuntBike);
IMPL_STDTOGGLE(ShootInAir);
IMPL_STDTOGGLE(ShowNametags);
IMPL_STDTOGGLE(JoinMessages);
IMPL_STDTOGGLE(DeathMessages);