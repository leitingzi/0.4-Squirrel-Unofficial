/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CServerFunctions.h

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

class CPlayer;
class CServerFunctions
{
	public:
		static void ClientMessage(const SQChar * pszMessage, CPlayer * pPlayer, int r, int g, int b);
		static void ClientMessageWithAlpha(const SQChar * pszMessage, CPlayer * pPlayer, int r, int g, int b, int a);

		static void ClientMessageToAll(const SQChar * pszMessage, int r, int g, int b);
		static void ClientMessageToAllWithAlpha(const SQChar * pszMessage, int r, int g, int b, int a);

		static void GameMessage(const SQChar * pszMessage, CPlayer * pPlayer, int type);
		static void GameMessageLegacy(const SQChar * pszMessage, CPlayer * pPlayer);

		static void GameMessageToAll(const SQChar * pszMessage, int type);
		static void GameMessageToAllLegacy(const SQChar * pszMessage);

		static void SetServerName(const SQChar * pszName);
		static void SetMaxPlayers(int nMaxPlayers);
		static void SetPassword(const SQChar * pszPassword);
		static void SetGameModeName(const SQChar * pszName);
		static void SetKillDelay(int nDelay);

		static const SQChar * GetServerName(void);
		static const SQChar * GetPassword(void);
		static const SQChar * GetGameModeName(void);
		static int GetMaxPlayers(void);
		static int GetKillDelay(void);
};