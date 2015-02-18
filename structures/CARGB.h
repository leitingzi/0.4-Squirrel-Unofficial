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

class CARGB
{
	public:
		CARGB( int a, int r, int g, int b ) { this->a = a; this->r = r; this->g = g; this->b = b; }
		CARGB() { this->a = 0; this->r = 0; this->g = 0; this->b = 0; }
			
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
			Sqrat::Class<CARGB> c(v, Sqrat::string("ARGB"));
			c
				.Var(_SC("a"), &CARGB::a)
				.Var(_SC("r"), &CARGB::r)
				.Var(_SC("g"), &CARGB::g)
				.Var(_SC("b"), &CARGB::b)
				.Func(_SC("ToInt"), &CARGB::ToInt)
				.Func(_SC("_tostring"), &CARGB::ToString);

			Sqrat::RootTable(v).Bind(_SC("ARGB"), c);
		}
};