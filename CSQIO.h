/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CSQIO.h

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
#include <stdio.h>
#include <squirrel.h>

class CSQIO
{
	public:
		static void rawprint(const char * pszOutput);
		static void printf(const char * pszFormat, ...);
		static void printfunc(HSQUIRRELVM v, const SQChar *s, ...);
		static void errorfunc(HSQUIRRELVM v, const SQChar *s, ...);
		static void shutdown();

	private:
		static FILE * m_pLogFile;
		static bool m_bTriedLogging;
};