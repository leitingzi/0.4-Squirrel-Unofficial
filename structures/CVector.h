/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CVector.h

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
#pragma warning( disable : 4244 )

#include <sqrat.h>
#include "IRefreshableStructure.h"
#include "../Main.h"

class CVector : IRefreshableStructure<CVector>
{
	public:
		CVector(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
		CVector() { this->x = 0.0f; this->y = 0.0f; this->z = 0.0f; }

		void SetX(float x) { this->x = x; ProcessCallback(this); }
		void SetY(float y) { this->y = y; ProcessCallback(this); }
		void SetZ(float z) { this->z = z; ProcessCallback(this); }

		float GetX() { return x; }
		float GetY() { return y; }
		float GetZ() { return z; }

		float Length(void) const {
			return sqrt(pow(x, 2) + pow(x, 2) + pow(x, 2));
		}

		float Distance(const CVector &v) const {
			return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
		}

		float Dot(const CVector &v) {
			return (x * v.x) + (y * v.y) + (z * v.z);
		}

		CVector Cross(const CVector &v) {
			float crossX = (this->y * v.z) - (this->z * v.y);
			float crossY = (this->z * v.x) - (this->x * v.z);
			float crossZ = (this->x * v.y) - (this->y * v.x);

			return CVector(crossX, crossY, crossZ);
		}

		CVector& Normalize(void) {
			float invLen = 1.0f / Length();
			this->x *= invLen;
			this->y *= invLen;
			this->z *= invLen;

			return *this;
		}

		bool operator ==(const CVector &v) const {
			return x == v.x && y == v.y && z == v.z;
		}

		CVector operator -(void) const {
			return CVector(-x, -y, -z);
		}

		CVector operator +(const CVector &v) const {
			return CVector(x + v.x, y + v.y, z + v.z);
		}

		CVector operator -(const CVector &v) const {
			return CVector(x - v.x, y - v.y, z - v.z);
		}

		CVector operator *(const float f) const {
			return CVector(x * f, y * f, z * f);
		}

		CVector operator /(const float f) const {
			return CVector(x / f, y / f, z / f);
		}

		CVector& operator =(const CVector &v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			ProcessCallback(this);

			return *this;
		}

		CVector& operator =(const float f) {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = f;
			ProcessCallback(this);

			return *this;
		}

		const std::string ToString() {
			std::basic_stringstream<SQChar> out;
			out << _SC("(") << x << _SC(",") << y << _SC(",") << z <<  _SC(")");

			return out.str();
		}

		static void Register(HSQUIRRELVM v) {
			Sqrat::Class<CVector> c(v, Sqrat::string("Vector"));
			c
				.Prop(_SC("x"), &CVector::GetX, &CVector::SetX)
				.Prop(_SC("y"), &CVector::GetY, &CVector::SetY)
				.Prop(_SC("z"), &CVector::GetZ, &CVector::SetZ)

				.Func(_SC("Cross"), &CVector::Cross)
				.Func(_SC("Distance"), &CVector::Distance)
				.Func(_SC("Dot"), &CVector::Dot)
				.Func(_SC("Length"), &CVector::Length)
				.Func(_SC("Normalize"), &CVector::Normalize)

				.Func(_SC("_add"), &CVector::operator +)
				.Func(_SC("_mul"), &CVector::operator *)
				.Func(_SC("_div"), &CVector::operator /)
				.Func<CVector(CVector::*)(void) const>(_SC("_unm"), &CVector::operator -)
				.Func<CVector(CVector::*)(const CVector&) const>(_SC("_sub"), &CVector::operator -)

				.Func(_SC("_tostring"), &CVector::ToString);

			Sqrat::RootTable(v).Bind(_SC("Vector"), c);
		}

	private:
		float x;
		float y;
		float z;
};