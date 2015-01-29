/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CScript.cpp

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

#include "CScript.h"
#include "CConsole.h"

void CScript::Run() {
	m_pEvents = new SScriptEvents;
	m_pVM = sq_open(256);
	m_pRunningScript = new Sqrat::Script(m_pVM);

	sq_setprintfunc(m_pVM, CSQIO::printfunc, CSQIO::errorfunc);
	CVMPopulator::Populate(m_pVM);

	try {
		m_pRunningScript->CompileFile(m_pszScriptName);
	}
	catch (Sqrat::Error e) {
		CConsole::OutputError("A script execution error was encountered.");
		CConsole::OutputError(e.Message(m_pVM).c_str());
	}
}

void CScript::ResetState() {
	if (m_pVM) {
		sq_close(m_pVM);
		m_pVM = NULL;
	}

	if (m_pEvents) {
		delete m_pEvents;
		m_pEvents = NULL;
	}

	if (m_pRunningScript) {
		delete m_pRunningScript;
		m_pRunningScript = NULL;
	}
}

void CScript::Reload() {
	ResetState();
	Run();
}