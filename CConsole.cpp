/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CConsole.cpp

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

#include "CConsole.h"
#include "Main.h"

void CConsole::DoWindowsOutput(const char * msg, uint32_t dwColorFlags) {
	#ifdef WIN32
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO csbBefore;
		GetConsoleScreenBufferInfo(hstdout, &csbBefore);
		SetConsoleTextAttribute(hstdout, dwColorFlags);
		g_pCore->rawprint("[SCRIPT]  ");

		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		g_pCore->rawprint(msg);

		SetConsoleTextAttribute(hstdout, csbBefore.wAttributes);
		g_pCore->rawprint("\n");
	#endif
}

void CConsole::OutputScriptInfo( const char * msg ) {
	#ifdef WIN32
		CConsole::DoWindowsOutput(msg, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	#else
		pCore->printf( "%c[0;36m[SCRIPT]%c[0;37m %s\n", 27, 27, msg );
	#endif
}

void CConsole::OutputDebug( const char * msg ) {
	#ifdef _DEBUG
		OutputMessage( msg );
	#endif
}

void CConsole::OutputMessage( const char * msg ) {
	#ifdef WIN32
		CConsole::DoWindowsOutput(msg, FOREGROUND_GREEN);
	#else
		pCore->printf( "%c[0;32m[MODULE]%c[0;37m %s\n", 27, 27, msg );
	#endif
}

void CConsole::OutputWarning( const char * msg ) {
	#ifdef WIN32
		CConsole::DoWindowsOutput(msg, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	#else
		pCore->printf( "%c[0;30m[WARNING]%c[0;37m %s\n", 27, 27, msg );
	#endif
}

void CConsole::OutputError( const char * msg )
{
	#ifdef WIN32
		DoWindowsOutput(msg, FOREGROUND_RED | FOREGROUND_INTENSITY);
	#else
		pCore->printf( "%c[0;30m[ERROR]%c[0;37m %s\n", 27, 27, msg );
	#endif
}