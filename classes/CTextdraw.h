/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CTextdraw.h

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
#include "../structures/CQuaternion.h"
#include "../structures/CVector.h"
#include "IEntity.h"

class CRGBA;
class CTextdraw : public IEntity
{
	public:
		CTextdraw(int nTextdrawId, bool bIsScriptEntity) {
			m_nTextdrawId = nTextdrawId;
			m_bIsScriptEntity = bIsScriptEntity;
		}

		CTextdraw() {
			m_nTextdrawId = -1;
			m_bIsScriptEntity = false;
		}

		int GetID(void) { return m_nTextdrawId; }
		void Delete(void);
		bool IsScriptEntity(void) { return m_bIsScriptEntity; }

	public:
		static void Register(HSQUIRRELVM v);
		void ShowForAll(void);
		void ShowForPlayer(CPlayer * pPlayer);

		void HideFromAll(void);
		void HideFromPlayer(CPlayer * pPlayer);

		void SetPositionForAll(int nX, int nY);
		void SetPositionForPlayer(CPlayer * pPlayer, int nX, int nY);

		void SetColourForAll(unsigned int uiColour);
		void SetColourRGBForAll(CRGBA * pColour);
		void SetColourForPlayer(CPlayer * pPlayer, unsigned int uiColour);
		void SetColourRGBForPlayer(CPlayer * pPlayer, CRGBA * pColour);

		void SetRelativeForAll(bool bRelativity);
		void SetRelativeForPlayer(CPlayer * pPlayer, bool bRelativity);

	private:
		int m_nTextdrawId;
		bool m_bIsScriptEntity;
};