/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CQuaternion.h

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

class CQuaternion : IRefreshableStructure<CQuaternion>
{
	public:
		CQuaternion( float x, float y, float z, float w ) { this->w = w; this->x = x; this->y = y; this->z = z; }
		CQuaternion() { this->w = 0.0f; this->x = 0.0f; this->y = 0.0f; this->z = 0.0f; }

		void SetX(float x) { this->x = x; ProcessCallback(this); }
		void SetY(float y) { this->y = y; ProcessCallback(this); }
		void SetZ(float z) { this->z = z; ProcessCallback(this); }
		void SetW(float w) { this->w = w; ProcessCallback(this); }

		float GetX() { return x; }
		float GetY() { return y; }
		float GetZ() { return z; }
		float GetW() { return w; }

		bool operator ==(const CQuaternion &q) const {
			return this->w == q.w && this->x == q.x && this->y == q.y && this->z == q.z;
		}

		CQuaternion operator -(void) const {
			return CQuaternion(-w, -x, -y, -z);
		}

		CQuaternion operator +(const CQuaternion &q) const {
			return CQuaternion(this->w + q.w, this->x + q.x, this->y + q.y, this->z + q.z);
		}

		CQuaternion operator -(const CQuaternion &q) const {
			return CQuaternion(this->w - q.w, this->x - q.x, this->y - q.y, this->z - q.z);
		}

		CQuaternion operator *(const float f) const {
			return CQuaternion(this->w * f, this->x * f, this->y * f, this->z * f);
		}

		CQuaternion operator /(const float f) const {
			return CQuaternion(this->w / f, this->x / f, this->y / f, this->z / f);
		}

		CQuaternion& operator =(const CQuaternion &q) {
			this->w = q.w;
			this->x = q.x;
			this->y = q.y;
			this->z = q.z;
			ProcessCallback(this);

			return *this;
		}

		CQuaternion& operator =(const float q) {
			this->w = 0.0f;
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = q;
			ProcessCallback(this);

			return *this;
		}

		const std::string ToString() {
			std::basic_stringstream<SQChar> out;
			out << _SC("(") << x << _SC(",") << y << _SC(",") << z << _SC(",") << w << _SC(")");

			return out.str();
		}

		static void Register(HSQUIRRELVM v) {
			Sqrat::Class<CQuaternion> c(v, Sqrat::string("Quaternion"));
			c
				.Prop(_SC("x"), &CQuaternion::GetX, &CQuaternion::SetX)
				.Prop(_SC("y"), &CQuaternion::GetY, &CQuaternion::SetY)
				.Prop(_SC("z"), &CQuaternion::GetZ, &CQuaternion::SetZ)
				.Prop(_SC("w"), &CQuaternion::GetW, &CQuaternion::SetW)

				.Func(_SC("_tostring"), &CQuaternion::ToString)
				.Func(_SC("_add"), &CQuaternion::operator +)
				.Func(_SC("_mul"), &CQuaternion::operator *)
				.Func(_SC("_div"), &CQuaternion::operator /)
				.Func<CQuaternion(CQuaternion::*)(void) const>(_SC("_unm"), &CQuaternion::operator -)
				.Func<CQuaternion(CQuaternion::*)(const CQuaternion&) const>(_SC("_sub"), &CQuaternion::operator -);

			Sqrat::RootTable(v).Bind(_SC("Quaternion"), c);
		}

	private:
		float w;
		float x;
		float y;
		float z;
};