/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CRGB.h

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

class CRGB : IRefreshableStructure<CRGB>
{
	public:
		CRGB( int r, int g, int b ) { this->r = r; this->g = g; this->b = b; }
		CRGB(unsigned int ulColour) {
			this->r = (ulColour >> 16) & 0xFF;
			this->g = (ulColour >> 8) & 0xFF;
			this->b = ulColour & 0xFF;
		}

		CRGB() { this->r = 0; this->g = 0; this->b = 0; }

		void SetR(int r) { this->r = r; ProcessCallback(this); }
		void SetG(int g) { this->g = g; ProcessCallback(this); }
		void SetB(int b) { this->b = b; ProcessCallback(this); }

		int GetR() { return r; }
		int GetG() { return g; }
		int GetB() { return b; }

		unsigned int ToInt() {
			return this->r << 16 | this->g << 8 | this->b;
		}

		const std::string ToString() {
			std::basic_stringstream<SQChar> out;
			out << _SC("(") << r << _SC(",") << g << _SC(",") << b << _SC(")");

			return out.str();
		}

		static void Register(HSQUIRRELVM v) {
			Sqrat::Class<CRGB> c(v, Sqrat::string("RGB"));
			c
				.Prop(_SC("r"), &CRGB::GetR, &CRGB::GetR)
				.Prop(_SC("g"), &CRGB::GetG, &CRGB::GetG)
				.Prop(_SC("b"), &CRGB::GetB, &CRGB::GetB)
				.Func(_SC("ToInt"), &CRGB::ToInt)
				.Func(_SC("_tostring"), &CRGB::ToString);

			Sqrat::RootTable(v).Bind(_SC("RGB"), c);
		}

	private:
		int r;
		int g;
		int b;
};