/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CARGB.h

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
#include <sqrat.h>
#include "../Main.h"

class ARGB
{
	public:
		ARGB( int a, int r, int g, int b ) { this->a = a; this->r = r; this->g = g; this->b = b; }
		ARGB() { this->a = 0; this->r = 0; this->g = 0; this->b = 0; }
			
		int a;
		int r;
		int g;
		int b;

		unsigned int ToInt() {
			return this->a << 24 | this->r << 16 | this->g << 8 | this->b;
		}

		const std::string ToString() {
			std::basic_stringstream<SQChar> out;
			out << _SC("(") << a << _SC(",") << r << _SC(",") << g << _SC(",") << b << _SC(")");

			return out.str();
		}

		static void Register(HSQUIRRELVM v) {
			Sqrat::Class<ARGB> c(v, Sqrat::string("ARGB"));
			c
				.Var(_SC("a"), &ARGB::a)
				.Var(_SC("r"), &ARGB::r)
				.Var(_SC("g"), &ARGB::g)
				.Var(_SC("b"), &ARGB::b)
				.Func(_SC("ToInt"), &ARGB::ToInt)
				.Func(_SC("_tostring"), &ARGB::ToString);

			Sqrat::RootTable(v).Bind(_SC("ARGB"), c);
		}
};