/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCore.h

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
#include "CCallbackHandler.h"
#include "CEntityPool.h"
#include "plugin.h"

#include "classes/CObject.h"
#include "classes/CPickup.h"
#include "classes/CPlayer.h"
#include "classes/CSprite.h"
#include "classes/CTextdraw.h"
#include "classes/CTimer.h"
#include "classes/CVehicle.h"

#include <squirrel.h>
#include <unordered_map>

#define MAX_PLAYERS    100
#define MAX_VEHICLES   1000
#define MAX_OBJECTS    3000
#define MAX_PICKUPS    2000
#define MAX_SPRITES    128
#define MAX_TEXTDRAWS  256

class CScript;
class CCore
{
	public:
		typedef std::unordered_map<const SQChar *, CScript *>::iterator ScriptIterator;
		typedef CEntityPool<CObject, MAX_OBJECTS> ObjectPool;
		typedef CEntityPool<CPickup, MAX_PICKUPS> PickupPool;
		typedef CEntityPool<CPlayer, MAX_PLAYERS> PlayerPool;
		typedef CEntityPool<CSprite, MAX_SPRITES> SpritePool;
		typedef CEntityPool<CTextdraw, MAX_TEXTDRAWS> TextdrawPool;
		typedef CEntityPool<CVehicle, MAX_VEHICLES> VehiclePool;

		CCore(PluginFuncs* functions, PluginCallbacks* callbacks, PluginInfo* info);
		~CCore();
		
		bool CanReload() { return this->m_bCanReload; }
		void DestroyScripts();
		void DestroyWorld();
		void ParseConfig();
		void Tick();

		CScript * GetScript(const SQChar * szScriptName) {
			return m_pScripts[szScriptName];
		}

		ScriptIterator GetScriptsIterator() { return m_pScripts.begin(); }
		ScriptIterator GetScriptsEnd() { return m_pScripts.end(); }

		// Abbreviation for "Get(F)unctions"
		PluginFuncs * F() { return m_pSDKFuncs; }

		// Abbreviation for "Get(C)allbacks"
		PluginCallbacks * C() { return m_pSDKCalls; }

		// Abbreviation for "Get(I)nfo"
		PluginInfo * I() { return m_pSDKInfo; }

		ObjectPool* GetObjectPool() { return m_pObjectPool; }
		PickupPool* GetPickupPool() { return m_pPickupPool; }
		PlayerPool* GetPlayerPool() { return m_pPlayerPool; }
		SpritePool* GetSpritePool() { return m_pSpritePool; }
		TextdrawPool* GetTextdrawPool() { return m_pTextdrawPool; }

	private:
		bool ParseConfigLine(const char * szLine);
		CScript * SpawnScript(const SQChar * szScriptName);

		std::unordered_map<const SQChar *, CScript *> m_pScripts;
		bool m_bCanReload;

		PluginFuncs * m_pSDKFuncs;
		PluginCallbacks * m_pSDKCalls;
		PluginInfo * m_pSDKInfo;

		ObjectPool* m_pObjectPool;
		PickupPool* m_pPickupPool;
		PlayerPool* m_pPlayerPool;
		SpritePool* m_pSpritePool;
		TextdrawPool* m_pTextdrawPool;
		VehiclePool* m_pVehiclePool;
};