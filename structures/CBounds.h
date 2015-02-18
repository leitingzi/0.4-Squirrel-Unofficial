/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CBounds.h

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

class CBounds
{
	public:
		CBounds( float maxX, float minX, float maxY, float minY )
		{
			this->maxX = maxX;
			this->minX = minX;
			this->maxY = maxY;
			this->minY = minY;
		}

		CBounds( int maxX, int minX, int maxY, int minY )
		{
			this->maxX = maxX;
			this->minX = minX;
			this->maxY = maxY;
			this->minY = minY;
		}

		CBounds()
		{
			this->maxX = 0.0f;
			this->minX = 0.0f;
			this->maxY = 0.0f;
			this->minY = 0.0f;
		}

		float maxX;
		float minX;
		float maxY;
		float minY;

		const std::string ToString() {
			std::basic_stringstream<SQChar> out;
			out << _SC("(") << maxX << _SC(",") << minX << _SC(",") << maxY << _SC(",") << minY << _SC(")");

			return out.str();
		}

		static void Register(HSQUIRRELVM v) {
			Sqrat::Class<CBounds> c(v, Sqrat::string("Bounds"));
			c
				.Var(_SC("MaxX"), &CBounds::maxX)
				.Var(_SC("MinX"), &CBounds::minX)
				.Var(_SC("MaxY"), &CBounds::maxY)
				.Var(_SC("MinY"), &CBounds::minY)
				.Func(_SC("_tostring"), &CBounds::ToString);

			Sqrat::RootTable(v).Bind(_SC("Bounds"), c);
		}
};