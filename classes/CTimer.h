/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CTimer.h

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

class CTimer : public IEntity
{
	public:
		CTimer(int nTimerId, bool bIsScriptEntity) {
			m_nTimerId = nTimerId;
			m_bIsScriptEntity = bIsScriptEntity;
		}

		CTimer() {
			m_nTimerId = -1;
			m_bIsScriptEntity = false;
		}

		int GetID(void) { return m_nTimerId; }
		void Delete(void);
		bool IsScriptEntity(void) { return m_bIsScriptEntity; }

	public:
		static void Register(HSQUIRRELVM v);

	private:
		int m_nTimerId;
		bool m_bIsScriptEntity;
};