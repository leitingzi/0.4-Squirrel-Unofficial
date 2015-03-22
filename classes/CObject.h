/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CObject.h

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

class CPlayer;
class CObject : public IEntity
{
	public:
		CObject(int nObjectId, bool bIsScriptEntity) {
			m_nObjectId = nObjectId;
			m_bIsScriptEntity = bIsScriptEntity;
		}

		CObject() {
			m_nObjectId = -1;
			m_bIsScriptEntity = false;
		}

		int GetID(void) { return m_nObjectId; }
		void Delete(void);
		bool IsScriptEntity(void) { return m_bIsScriptEntity; }

	public:
		static void Register(HSQUIRRELVM v);

		void SetWorld(int world);
		void SetPos(CVector * pPos);
		void SetReportingShots(bool toReport);
		void SetReportingBumps(bool toReport);

		int GetModel(void);
		int GetAlpha(void);
		int GetWorld(void);
		CVector GetPos(void);
		CQuaternion GetRotation(void);
		CVector GetRotationEuler(void);
		bool GetReportingShots(void);
		bool GetReportingBumps(void);

		void MoveTo(CVector * pos, int time);
		void MoveBy(CVector * offset, int time);
		void RotateTo(CQuaternion * rotation, int time);
		void RotateBy(CQuaternion * rotOffset, int time);
		void RotateToEuler(CVector * rotation, int time);
		void RotateByEuler(CVector * rotOffset, int time);
		void SetAlpha(int alpha, int fadeTime);
		bool StreamedToPlayer(CPlayer * player);

	private:
		int m_nObjectId;
		bool m_bIsScriptEntity;
};