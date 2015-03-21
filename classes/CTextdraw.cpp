/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CTextdraw.cpp

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

#include "../structures/CRGBA.h"
#include "../Main.h"
#include "CTextdraw.h"

void CTextdraw::Register(HSQUIRRELVM v) {
	Sqrat::Class<CTextdraw> c(v, "CTextdraw");

	c
		.Prop(_SC("ID"), &CTextdraw::GetID)

		.Func(_SC("Delete"), &CTextdraw::Delete)
		.Func(_SC("HideFromAll"), &CTextdraw::HideFromAll)
		.Func(_SC("HideFromPlayer"), &CTextdraw::HideFromPlayer)
		.Overload(_SC("SetColourForAll"), &CTextdraw::SetColourForAll)
		.Overload(_SC("SetColourForAll"), &CTextdraw::SetColourRGBForAll)
		.Overload(_SC("SetColourForPlayer"), &CTextdraw::SetColourForPlayer)
		.Overload(_SC("SetColourForPlayer"), &CTextdraw::SetColourRGBForPlayer)
		.Func(_SC("SetPosForAll"), &CTextdraw::SetPositionForAll)
		.Func(_SC("SetPosForPlayer"), &CTextdraw::SetPositionForPlayer)
		.Func(_SC("SetRelativeForAll"), &CTextdraw::SetRelativeForAll)
		.Func(_SC("SetRelativeForPlayer"), &CTextdraw::SetRelativeForPlayer)
		.Func(_SC("ShowForAll"), &CTextdraw::ShowForAll)
		.Func(_SC("ShowForPlayer"), &CTextdraw::ShowForPlayer);

	Sqrat::RootTable(v).Bind(_SC("CTextdraw"), c);
}

void CTextdraw::Delete(void) {
	g_pCore->F()->DestroyTextdraw(m_nTextdrawId);
}

void CTextdraw::ShowForAll(void) {
	g_pCore->F()->ShowTextdraw(m_nTextdrawId, -1);
}

void CTextdraw::ShowForPlayer(CPlayer * pPlayer) {
	g_pCore->F()->ShowTextdraw(m_nTextdrawId, pPlayer->GetID());
}

void CTextdraw::HideFromAll(void) {
	g_pCore->F()->HideTextdraw(m_nTextdrawId, -1);
}

void CTextdraw::HideFromPlayer(CPlayer * pPlayer) {
	g_pCore->F()->HideTextdraw(m_nTextdrawId, pPlayer->GetID());
}

void CTextdraw::SetPositionForAll(int nX, int nY) {
	g_pCore->F()->MoveTextdraw(m_nTextdrawId, -1, nX, nY);
}

void CTextdraw::SetPositionForPlayer(CPlayer * pPlayer, int nX, int nY) {
	g_pCore->F()->MoveTextdraw(m_nTextdrawId, pPlayer->GetID(), nX, nY);
}

void CTextdraw::SetRelativeForAll(bool bRelativity) {
	g_pCore->F()->SetTextdrawRelativity(m_nTextdrawId, -1, bRelativity);
}

void CTextdraw::SetRelativeForPlayer(CPlayer * pPlayer, bool bRelativity) {
	g_pCore->F()->SetTextdrawRelativity(m_nTextdrawId, pPlayer->GetID(), bRelativity);
}

void CTextdraw::SetColourForAll(unsigned int uiColour) {
	g_pCore->F()->SetTextdrawColour(m_nTextdrawId, -1, uiColour);
}

void CTextdraw::SetColourRGBForAll(CRGBA * pColour) {
	g_pCore->F()->SetTextdrawColour(m_nTextdrawId, -1, pColour->ToInt());
}

void CTextdraw::SetColourForPlayer(CPlayer * pPlayer, unsigned int uiColour) {
	g_pCore->F()->SetTextdrawColour(m_nTextdrawId, pPlayer->GetID(), uiColour);
}

void CTextdraw::SetColourRGBForPlayer(CPlayer * pPlayer, CRGBA * pColour) {
	g_pCore->F()->SetTextdrawColour(m_nTextdrawId, pPlayer->GetID(), pColour->ToInt());
}