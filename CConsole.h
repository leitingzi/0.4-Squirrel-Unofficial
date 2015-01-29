/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CConsole.h

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
#ifdef WIN32
	#include <Windows.h>
#endif

#include <iostream>
#include <stdio.h>
#include <stdint.h>

class CConsole
{
	public:
		static void OutputScriptInfo(const char * msg);
		static void OutputDebug(const char * msg);
		static void OutputMessage(const char * msg);
		static void OutputWarning(const char * msg);
		static void OutputError(const char * msg);
};