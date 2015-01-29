/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCore.h

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
#include "CCallbackHandler.h"
#include "plugin.h"
#include <squirrel.h>
#include <unordered_map>

#define MAX_SCRIPTS 32
class CScript;

// TODO: Splinter logging functions/printf into a different class
class CCore
{
	public:
		CCore(PluginFuncs* functions, PluginCallbacks* callbacks, PluginInfo* info) {
			m_pSDKFuncs = functions;
			m_pSDKCalls = callbacks;
			m_pSDKInfo = info;
			m_pLogFile = fopen("server_log.txt", "a");

			CCallbackHandler::Register(callbacks);
			ParseConfig();
		}

		~CCore();
		
		bool CanReload() { return this->m_bCanReload; }
		void DestroyWorld();
		void ParseConfig();
		void Tick();

		FILE * GetLogInstance() { return m_pLogFile; }
		CScript * GetScript(const SQChar * szScriptName) {
			return m_pScripts[szScriptName];
		}

		static void printfunc(HSQUIRRELVM v, const SQChar *s, ...);
		static void errorfunc(HSQUIRRELVM v, const SQChar *s, ...);
		void rawprint(const char * pszOutput);
		void printf(const char * pszFormat, ...);

		// Abbreviation for "Get(F)unctions"
		PluginFuncs * F() { return m_pSDKFuncs; }

		// Abbreviation for "Get(C)allbacks"
		PluginCallbacks * C() { return m_pSDKCalls; }

		// Abbreviation for "Get(I)nfo"
		PluginInfo * I() { return m_pSDKInfo; }

	private:
		bool ParseConfigLine(const char * szLine);
		CScript * SpawnScript(const SQChar * szScriptName);

		std::unordered_map<const SQChar *, CScript *> m_pScripts;
		FILE * m_pLogFile;
		bool m_bCanReload;

		PluginFuncs * m_pSDKFuncs;
		PluginCallbacks * m_pSDKCalls;
		PluginInfo * m_pSDKInfo;
};