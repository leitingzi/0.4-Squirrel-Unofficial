/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CSprite.cpp

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
#include "CSprite.h"

void CSprite::Register(HSQUIRRELVM v) {
	Sqrat::Class<CObject> c(v, "CSprite");

	c
		.Prop(_SC("ID"), &CSprite::GetID)

		.Func(_SC("Delete"), &CSprite::Delete)
		.Func(_SC("HideFromAll"), &CSprite::HideFromAll)
		.Func(_SC("HideFromPlayer"), &CSprite::HideFromPlayer)
		.Func(_SC("RotateForAll"), &CSprite::SetRotationForAll)
		.Func(_SC("RotateForPlayer"), &CSprite::SetRotationForPlayer)
		.Func(_SC("SetAlphaForAll"), &CSprite::SetAlphaForAll)
		.Func(_SC("SetAlphaForPlayer"), &CSprite::SetAlphaForPlayer)
		.Func(_SC("SetCenterForAll"), &CSprite::SetRotationCenterForAll)
		.Func(_SC("SetCenterForPlayer"), &CSprite::SetRotationCenterForPlayer)
		.Func(_SC("SetPosForAll"), &CSprite::SetPositionForAll)
		.Func(_SC("SetPosForPlayer"), &CSprite::SetPositionForPlayer)
		.Func(_SC("SetRelativeForAll"), &CSprite::SetRelativeForAll)
		.Func(_SC("SetRelativeForPlayer"), &CSprite::SetRelativeForPlayer)
		.Func(_SC("ShowForAll"), &CSprite::ShowForAll)
		.Func(_SC("ShowForPlayer"), &CSprite::ShowForPlayer);

	Sqrat::RootTable(v).Bind(_SC("CSprite"), c);
}

void CSprite::Delete(void) {
	g_pCore->F()->DestroySprite(m_nSpriteId);
}

void CSprite::ShowForAll(void) {
	g_pCore->F()->ShowSprite(m_nSpriteId, -1);
}

void CSprite::ShowForPlayer(CPlayer * pPlayer) {
	g_pCore->F()->ShowSprite(m_nSpriteId, pPlayer->GetID());
}

void CSprite::HideFromAll(void) {
	g_pCore->F()->HideSprite(m_nSpriteId, -1);
}

void CSprite::HideFromPlayer(CPlayer * pPlayer) {
	g_pCore->F()->HideSprite(m_nSpriteId, pPlayer->GetID());
}

void CSprite::SetPositionForAll(int nX, int nY) {
	g_pCore->F()->MoveSprite(m_nSpriteId, -1, nX, nY);
}

void CSprite::SetPositionForPlayer(CPlayer * pPlayer, int nX, int nY) {
	g_pCore->F()->MoveSprite(m_nSpriteId, pPlayer->GetID(), nX, nY);
}

void CSprite::SetRotationCenterForAll(int nX, int nY) {
	g_pCore->F()->SetSpriteCenter(m_nSpriteId, -1, nX, nY);
}

void CSprite::SetRotationCenterForPlayer(CPlayer * pPlayer, int nX, int nY) {
	g_pCore->F()->SetSpriteCenter(m_nSpriteId, pPlayer->GetID(), nX, nY);
}

void CSprite::SetRotationForAll(float fRotation) {
	g_pCore->F()->RotateSprite(m_nSpriteId, -1, fRotation);
}

void CSprite::SetRotationForPlayer(CPlayer * pPlayer, float fRotation) {
	g_pCore->F()->RotateSprite(m_nSpriteId, pPlayer->GetID(), fRotation);
}

void CSprite::SetAlphaForAll(unsigned int uiAlpha) {
	g_pCore->F()->SetSpriteAlpha(m_nSpriteId, -1, uiAlpha);
}

void CSprite::SetAlphaForPlayer(CPlayer * pPlayer, unsigned int uiAlpha) {
	g_pCore->F()->SetSpriteAlpha(m_nSpriteId, pPlayer->GetID(), uiAlpha);
}

void CSprite::SetRelativeForAll(bool bRelativity) {
	g_pCore->F()->SetSpriteRelativity(m_nSpriteId, -1, bRelativity);
}

void CSprite::SetRelativeForPlayer(CPlayer * pPlayer, bool bRelativity) {
	g_pCore->F()->SetSpriteRelativity(m_nSpriteId, pPlayer->GetID(), bRelativity);
}