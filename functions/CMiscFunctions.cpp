/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CMiscFunctions.cpp

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

#include "../Main.h"
#include "CMiscFunctions.h"
#include <sqrat.h>

void CMiscFunctions::Register(HSQUIRRELVM v) {
	Sqrat::RootTable(v)
		.Func(_SC("CreateRadioStream"), CMiscFunctions::CreateRadioStream)
		.Func(_SC("DestroyRadioStream"), CMiscFunctions::DestroyRadioStream)
		
		.Func(_SC("BindKey"), CMiscFunctions::BindKey)
		.Func(_SC("UnbindKey"), CMiscFunctions::RemoveKeybind)
		.Func(_SC("UnbindAll"), CMiscFunctions::RemoveAllKeybinds);
}

int CMiscFunctions::CreateRadioStream(const SQChar * pszRadioName, const SQChar * pszRadioURL, bool bCanSelect) {
	return g_pCore->F()->AddRadioStream(-1, pszRadioName, pszRadioURL, bCanSelect);
}

void CMiscFunctions::DestroyRadioStream(int nRadioId) {
	g_pCore->F()->RemoveRadioStream(nRadioId);
}

int CMiscFunctions::BindKey(bool bIsOnKeyUp, int nKey1, int nKey2, int nKey3) {
	return g_pCore->F()->RegisterKeyBind(-1, bIsOnKeyUp, nKey1, nKey2, nKey3);
}

bool CMiscFunctions::RemoveKeybind(int nBindId) {
	return g_pCore->F()->RemoveKeyBind(nBindId) == 1;
}

void CMiscFunctions::RemoveAllKeybinds(void) {
	g_pCore->F()->RemoveAllKeyBinds();
}