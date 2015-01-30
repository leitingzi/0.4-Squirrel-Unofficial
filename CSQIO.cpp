/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CSQIO.cpp

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

#include "CSQIO.h"
#include "CConsole.h"
#include <stdarg.h>

FILE * CSQIO::m_pLogFile = NULL;
bool CSQIO::m_bTriedLogging = false;

void CSQIO::printf(const char * pszFormat, ...) {
	char szInitBuffer[512];
	va_list va;

	va_start(va, pszFormat);
	{
		int nChars = vsnprintf(szInitBuffer, sizeof(szInitBuffer), pszFormat, va);
		if (nChars > sizeof(szInitBuffer) - 1)
		{
			char * szBuffer = new char[nChars + 1];
			if (szBuffer != NULL) {
				vsnprintf(szBuffer, nChars, pszFormat, va);
				rawprint(szBuffer);

				delete[] szBuffer;
			}
		}
		else
			rawprint(szInitBuffer);
	}
	va_end(va);
}

void CSQIO::rawprint(const char * pszOutput) {
	if (m_pLogFile == NULL && !m_bTriedLogging) {
		m_pLogFile = fopen("server_log.txt", "a");
		m_bTriedLogging = true;
	}

	fputs(pszOutput, stdout);
	if (CSQIO::m_pLogFile != NULL)
		fprintf(m_pLogFile, "%s", pszOutput);
}

void CSQIO::shutdown() {
	if (m_pLogFile != NULL)
		fclose(m_pLogFile);
}

void CSQIO::printfunc(HSQUIRRELVM v, const SQChar *s, ...) {
	va_list arglist;
	char szInitBuffer[512];

	va_start(arglist, s);
	{
		int nChars = vsnprintf(szInitBuffer, sizeof(szInitBuffer), s, arglist);
		if (nChars > sizeof(szInitBuffer) - 1)
		{
			char * szBuffer = new char[nChars + 1];
			if (szBuffer == NULL)
			{
				sprintf(szInitBuffer, "Error could not be printed: failed to malloc the buffer at %d nChars.", nChars + 1);
				rawprint(szInitBuffer);
			}
			else
			{
				vsnprintf(szBuffer, nChars, s, arglist);
				CConsole::OutputScriptInfo(szBuffer);

				delete[] szBuffer;
			}
		}
		else
			CConsole::OutputScriptInfo(szInitBuffer);
	}
	va_end(arglist);
}

void CSQIO::errorfunc(HSQUIRRELVM v, const SQChar *s, ...) {
	va_list arglist;
	char szInitBuffer[512];

	va_start(arglist, s);
	{
		int nChars = vsnprintf(szInitBuffer, sizeof(szInitBuffer), s, arglist);
		if (nChars > sizeof(szInitBuffer) - 1)
		{
			char * szBuffer = new char[nChars + 1];
			if (szBuffer == NULL)
			{
				sprintf(szInitBuffer, "Error could not be printed: failed to malloc the buffer at %d nChars.", nChars + 1);
				rawprint(szInitBuffer);
			}
			else
			{
				vsnprintf(szBuffer, nChars, s, arglist);
				rawprint(szBuffer);

				delete[] szBuffer;
			}
		}
		else
			rawprint(szInitBuffer);
	}
	va_end(arglist);
}

void CSQIO::DoWindowsOutput(const char * pszMsg, uint32_t dwColorFlags) {
	#ifdef WIN32
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO csbBefore;
		GetConsoleScreenBufferInfo(hstdout, &csbBefore);
		SetConsoleTextAttribute(hstdout, dwColorFlags);
		CSQIO::rawprint("[SCRIPT]  ");

		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		CSQIO::rawprint(pszMsg);

		SetConsoleTextAttribute(hstdout, csbBefore.wAttributes);
		CSQIO::rawprint("\n");
	#endif
}