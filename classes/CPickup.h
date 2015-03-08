/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CPickup.h

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
#include "IEntity.h"
#include "../structures/CVector.h"

class CPickup : public IEntity
{
	public:
		CPickup(int nObjectId, bool bIsScriptEntity) {
			m_nPickupId = nObjectId;
			m_bIsScriptEntity = bIsScriptEntity;
		}

		CPickup() {
			m_nPickupId = -1;
			m_bIsScriptEntity = false;
		}

		int GetID(void) { return m_nPickupId; }
		void Delete(void);
		bool IsScriptEntity(void) { return m_bIsScriptEntity; }

	public:
		static void Register(HSQUIRRELVM v);

		void SetWorld(int nWorld);
		void SetAlpha(int nAlpha);
		void SetAuto(bool bHasAutoReward);
		void SetAutoTimer(int nRewardTime);
		void SetPos(CVector vecPos);

		int GetWorld(void);
		int GetAlpha(void);
		bool GetAuto(void);
		int GetAutoTimer(void);
		CVector GetPos(void);
		int GetModel(void);
		int GetQuantity(void);

		void Respawn(void);
		bool StreamedToPlayer(CPlayer * player);
			
	private:
		int m_nPickupId;
		bool m_bIsScriptEntity;
};