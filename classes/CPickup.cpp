/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CPickup.cpp

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

#include "CPickup.h"

void CPickup::Register(HSQUIRRELVM v) {
	Sqrat::Class<CPickup> c(v, "CPickup");

	c
		.Prop(_SC("World"), GetWorld, SetWorld)
		.Prop(_SC("Alpha"), GetAlpha, SetAlpha)
		.Prop(_SC("Automatic"), GetAuto, SetAuto)
		.Prop(_SC("IsAutomatic"), GetAuto, SetAuto)
		.Prop(_SC("RespawnTime"), GetAutoTimer, SetAutoTimer)
		.Prop(_SC("Pos"), GetPos, SetPos)
		
		.Prop(_SC("Model"), GetModel)
		.Prop(_SC("Quantity"), GetQuantity)
		.Prop(_SC("ID"), GetID)
		
		.Func(_SC("Remove"), Delete)
		.Func(_SC("Respawn"), Respawn)
		.Func(_SC("StreamedToPlayer"), StreamedToPlayer);

	Sqrat::RootTable(v).Bind(_SC("CPickup"), c);
}

void CPickup::Delete(void) {
	g_pCore->F()->DeletePickup(m_nPickupId);
}

void CPickup::SetWorld(int nWorld) {
	g_pCore->F()->SetPickupWorld(m_nPickupId, nWorld);
}

void CPickup::SetAlpha(int nAlpha) {
	g_pCore->F()->PickupSetAlpha(m_nPickupId, nAlpha);
}

// There've been a few questions as to what exactly this is.
// A pickup that is "automatic" is a pickup that automatically grants
// some sort of item.
//
// An automatic pickup with a weapon model will grant the weapon whose
// model is used and ammo when picked up.
//
// An automatic pickup with a health model will grant health.
// An automatic pickup with an armour model will grant armour.
//
// The "quantity" of the pickup is how the server determines how much
// ammo, health, or armour to give the player.
//
// The "auto timer" of the pickup is the pickup's respawn time and is
// managed by the server. If this is disabled, scripts must respawn them.
//
// ALL OF THIS BEHAVIOR IS OVERRIDDEN BY SETTING THIS TO FALSE.
void CPickup::SetAuto(bool bHasAutoReward) {
	g_pCore->F()->PickupSetAutomatic(m_nPickupId, bHasAutoReward);
}

void CPickup::SetAutoTimer(int nRewardTime) {
	g_pCore->F()->SetPickupAutoTimer(m_nPickupId, nRewardTime);
}

void CPickup::SetPos(CVector * vecPos) {
	g_pCore->F()->PickupSetPos(m_nPickupId, VECTOREX(vecPos));
}

int CPickup::GetWorld(void) {
	return g_pCore->F()->GetPickupWorld(m_nPickupId);
}

int CPickup::GetAlpha(void) {
	return g_pCore->F()->PickupGetAlpha(m_nPickupId);
}

bool CPickup::GetAuto(void) {
	return g_pCore->F()->PickupIsAutomatic(m_nPickupId) == 1;
}

int CPickup::GetAutoTimer(void) {
	return g_pCore->F()->GetPickupAutoTimer(m_nPickupId);
}

CVector CPickup::GetPos(void) {
	float x, y, z;
	g_pCore->F()->PickupGetPos(m_nPickupId, &x, &y, &z);

	static CVector vecPos(x, y, z);
	return vecPos;
}

int CPickup::GetModel(void) {
	return g_pCore->F()->PickupGetModel(m_nPickupId);
}

int CPickup::GetQuantity(void) {
	return g_pCore->F()->PickupGetQuantity(m_nPickupId);
}

void CPickup::Respawn(void) {
	g_pCore->F()->PickupRefresh(m_nPickupId);
}

bool CPickup::StreamedToPlayer(CPlayer * pPlayer) {
	return g_pCore->F()->IsPickupStreamedForPlayer(m_nPickupId,
		pPlayer->GetID()) == 1;
}