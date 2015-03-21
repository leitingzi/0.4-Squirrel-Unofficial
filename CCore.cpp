/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCore.cpp

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

#include "CCore.h"
#include "CConsole.h"
#include "CScript.h"
#include "CSQIO.h"

CCore::CCore(PluginFuncs* functions, PluginCallbacks* callbacks, PluginInfo* info) {
	m_pSDKFuncs = functions;
	m_pSDKCalls = callbacks;
	m_pSDKInfo = info;

	m_pObjectPool = new ObjectPool();
	m_pPickupPool = new PickupPool();
	m_pPlayerPool = new PlayerPool();
	m_pSpritePool = new SpritePool();
	m_pTextdrawPool = new TextdrawPool();
	m_pVehiclePool = new VehiclePool();

	CCallbackHandler::Register(callbacks);
	ParseConfig();
}

CCore::~CCore() {
	CSQIO::shutdown();
	this->DestroyScripts();

	delete m_pPlayerPool;
}

void CCore::DestroyScripts() {
	for (ScriptIterator it = m_pScripts.begin(); it != m_pScripts.end(); it++) {
		delete it->second;
	}
}

void CCore::DestroyWorld() {
	m_pObjectPool->RemoveAllScriptEntities();
	m_pPickupPool->RemoveAllScriptEntities();
	m_pSpritePool->RemoveAllScriptEntities();
	m_pTextdrawPool->RemoveAllScriptEntities();
	m_pVehiclePool->RemoveAllScriptEntities();
}

void CCore::ParseConfig() {
	m_bCanReload = false;

	FILE * pConfig = fopen("server.cfg", "r");
	if (pConfig == NULL) {
		CConsole::OutputError("0.4-squirrel could not read server.cfg");
	}
	else {
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

			while (ch != EOF) {
				if (ch == '\n') {
					// End of the line. Parse it.
					this->ParseConfigLine(lineBuffer);

					memset(lineBuffer, 0, bufferSize);
					elapsedLineSize = 0;
				}
				else {
					lineBuffer[elapsedLineSize++] = ch;

					// If we've hit our limit on line size, stop reading the line.
					if (elapsedLineSize + 1 == lineSize)
					{
						// Parse it.
						this->ParseConfigLine(lineBuffer);

						// Go straight to the next one instead.
						while (ch != '\n') {
							ch = getc(pConfig);
						}

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
	if ((gamemodeSearch = strstr(szLine, "sqgamemode ")) == NULL) {
		return false;
	}
	else if (strlen(gamemodeSearch) < 1) {
		return false;
	}
	else {
		gamemodeSearch += sizeof("sqgamemode");
		CScript * pScript = this->SpawnScript(gamemodeSearch);

		m_pScripts[gamemodeSearch] = pScript;
		return true;
	}
}

CScript * CCore::SpawnScript(const SQChar * szScriptName) {
	CScript * pScript = new CScript(szScriptName);
	return pScript;
}