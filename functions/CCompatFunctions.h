/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CCompatFunctions.h

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
class CCompatFunctions
{
	public:
		static bool GetCinematicBorder(CPlayer * pPlayer);
		static bool GetGreenScanLines(CPlayer * pPlayer);
		static bool GetWhiteScanLines(CPlayer * pPlayer);

		static void SetCinematicBorder(CPlayer * pPlayer, bool bEnabled);
		static void SetGreenScanLines(CPlayer * pPlayer, bool bEnabled);
		static void SetWhiteScanLines(CPlayer * pPlayer, bool bEnabled);

		static void KickPlayer(CPlayer * pPlayer);
		static void BanPlayer(CPlayer * pPlayer);

		static void Message(const SQChar * pszMessage);
		static void MessagePlayer(const SQChar * pszMessage, CPlayer * pPlayer);
		static void MessageAllExcept(const SQChar * pszMessage, CPlayer * pPlayer);
		static void PrivMessage(CPlayer * pPlayer, const SQChar * pszMessage);
		static void PrivMessageAll(const SQChar * pszMessage);
		static void SendPlayerMessage(CPlayer * pPlayerToForge, CPlayer * pTarget, const SQChar * pszMessage);
};