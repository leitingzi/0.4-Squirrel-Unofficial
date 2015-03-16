/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CRGBA.h

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
#include "IRefreshableStructure.h"
#include "../Main.h"

class CRGBA : IRefreshableStructure<CRGBA>
{
	public:
		CRGBA( int a, int r, int g, int b ) { this->a = a; this->r = r; this->g = g; this->b = b; }
		CRGBA(unsigned int ulColour) {
			this->r = (ulColour >> 24) & 0xFF;
			this->g = (ulColour >> 16) & 0xFF;
			this->b = (ulColour >> 8) & 0xFF;
			this->a = ulColour & 0xFF;
		}

		CRGBA() { this->a = 0; this->r = 0; this->g = 0; this->b = 0; }

		void SetA(int a) { this->a = a; ProcessCallback(this); }
		void SetR(int r) { this->r = r; ProcessCallback(this); }
		void SetG(int g) { this->g = g; ProcessCallback(this); }
		void SetB(int b) { this->b = b; ProcessCallback(this); }

		int GetA() { return a; }
		int GetR() { return r; }
		int GetG() { return g; }
		int GetB() { return b; }

		unsigned int ToInt() {
			return this->r << 24 | this->g << 16 | this->b << 8 | this->a;
		}

		const std::string ToString() {
			std::basic_stringstream<SQChar> out;
			out << _SC("(") << r << _SC(",") << g << _SC(",") << b << _SC(",") << a << _SC(")");

			return out.str();
		}

		static void Register(HSQUIRRELVM v) {
			Sqrat::Class<CRGBA> c(v, Sqrat::string("RGBA"));
			c
				.Prop(_SC("a"), &CRGBA::GetA, &CRGBA::SetA)
				.Prop(_SC("r"), &CRGBA::GetR, &CRGBA::GetR)
				.Prop(_SC("g"), &CRGBA::GetG, &CRGBA::GetG)
				.Prop(_SC("b"), &CRGBA::GetB, &CRGBA::GetB)
				.Func(_SC("ToInt"), &CRGBA::ToInt)
				.Func(_SC("_tostring"), &CRGBA::ToString);

			Sqrat::RootTable(v).Bind(_SC("RGBA"), c);
		}

	private:
		int a;
		int r;
		int g;
		int b;
};