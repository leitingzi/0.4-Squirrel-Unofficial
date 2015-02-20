/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: Main.h

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

#ifdef WIN32
	#define PLUGIN_EXPORT __declspec(dllexport)
#else
	#define PLUGIN_EXPORT
#endif

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <squirrel.h>
#include <sqstdaux.h>
#include <sqstdblob.h>
#include <sqstdio.h>
#include <sqstdmath.h>
#include <sqstdstring.h>

#include <sqrat.h>
using namespace Sqrat;

#include "plugin.h"
#include "CCore.h"

#define _SQ( x ) SQInteger x( HSQUIRRELVM v )
#define PLUGIN_INIT extern "C" PLUGIN_EXPORT unsigned int

// Declared in the main header to be accessible to all code in this module.
extern CCore * g_pCore;