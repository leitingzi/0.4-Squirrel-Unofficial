/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CScript.h

   Copyright (c) 2015 Nelson Gomez (Stormeus)

   Licensed under the MIT License. A copy of the License is available in
   LICENSE.txt or at:

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
#include "Main.h"
#include "SScriptEvents.h"

class CScript
{
	public:
		CScript() {
			m_pEvents = new SScriptEvents;
			m_pVM = sq_open(256);
		}

		~CScript();

		// Abbreviation for "Get(V)M"
		HSQUIRRELVM V() { return m_pVM; }

		// Abbreviation for "Get(E)vents"
		SScriptEvents * E() { return m_pEvents; }

	private:
		SScriptEvents * m_pEvents;
		HSQUIRRELVM m_pVM;
		//CTimerManager * m_pTimerManager;

		// Sqrat's copy of the running script
		Script * m_pRunningScript;
};