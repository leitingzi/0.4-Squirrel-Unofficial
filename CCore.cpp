/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCore.cpp

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

#include "CCore.h"
#include "CConsole.h"
#include "CScript.h"

void CCore::ParseConfig() {
	m_bCanReload = false;

	FILE * pConfig = fopen("server.cfg", "r");
	if (pConfig == NULL)
		CConsole::OutputError("0.4-squirrel could not read server.cfg");
	else
	{
		const int lineSize = 128;
		const int bufferSize = sizeof(char) * lineSize;
		char * lineBuffer = (char *)malloc(bufferSize);
		int elapsedLineSize = 0;

		if (lineBuffer == NULL)
			CConsole::OutputError("0.4-squirrel could not allocate memory to read server.cfg");
		else
		{
			memset(lineBuffer, 0, bufferSize);
			char ch = getc(pConfig);

			while (ch != EOF)
			{
				if (ch == '\n')
				{
					// End of the line. Parse it.
					this->ParseConfigLine(lineBuffer);

					memset(lineBuffer, 0, bufferSize);
					elapsedLineSize = 0;
				}
				else
				{
					lineBuffer[elapsedLineSize++] = ch;

					// If we've hit our limit on line size, stop reading the line.
					if (elapsedLineSize + 1 == lineSize)
					{
						// Parse it.
						this->ParseConfigLine(lineBuffer);

						// Go straight to the next one instead.
						while (ch != '\n')
							ch = getc(pConfig);

						memset(lineBuffer, 0, bufferSize);
						elapsedLineSize = 0;
					}
				}

				// Get the next character in the file.
				ch = getc(pConfig);
			}

			free(lineBuffer);
		}

		fclose(pConfig);
	}

	m_bCanReload = true;
}

bool CCore::ParseConfigLine(const char * szLine) {
	const char * gamemodeSearch = NULL;
	if ((gamemodeSearch = strstr(szLine, "sqgamemode ")) == NULL)
		return false;
	else if (strlen(gamemodeSearch) < 1)
		return false;
	else
	{
		gamemodeSearch += sizeof("sqgamemode");
		CScript * pScript = this->SpawnScript(gamemodeSearch);

		m_pScripts[gamemodeSearch] = pScript;
		return true;
	}
}

CScript * CCore::SpawnScript(const char * szScriptName) {
	CScript * pScript = new CScript(szScriptName);
	return pScript;
}

void CCore::printf(const char * pszFormat, ...)
{
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
				this->rawprint(szBuffer);

				delete[] szBuffer;
			}
		}
		else
			this->rawprint(szInitBuffer);
	}
	va_end(va);
}

void CCore::rawprint(const char * pszOutput)
{
	fputs(pszOutput, stdout);
	if (this->m_pLogFile != NULL)
		fprintf(this->m_pLogFile, "%s", pszOutput);
}