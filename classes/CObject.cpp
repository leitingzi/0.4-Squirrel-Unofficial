/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CObject.cpp

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

#include "../Main.h"
#include "../structures/CQuaternion.h"
#include "../structures/CVector.h"
#include "CObject.h"

void CObject::Register(HSQUIRRELVM v) {
	Sqrat::Class<CObject> c(v, "CObject");

	c
		.Prop(_SC("Pos"), &CObject::GetPos, &CObject::SetPos)
		.Prop(_SC("TrackingShots"), &CObject::GetReportingShots, &CObject::SetReportingShots)
		.Prop(_SC("TrackingBumps"), &CObject::GetReportingBumps, &CObject::SetReportingBumps)
		.Prop(_SC("World"), &CObject::GetWorld, &CObject::SetWorld)
		
		.Prop(_SC("Alpha"), &CObject::GetAlpha)
		.Prop(_SC("ID"), &CObject::GetID)
		.Prop(_SC("Model"), &CObject::GetModel)
		.Prop(_SC("Rotation"), &CObject::GetRotation)
		.Prop(_SC("RotationEuler"), &CObject::GetRotationEuler)
		
		.Func(_SC("Delete"), &CObject::Delete)
		.Func(_SC("MoveTo"), &CObject::MoveTo)
		.Func(_SC("MoveBy"), &CObject::MoveBy)
		.Func(_SC("RotateTo"), &CObject::RotateTo)
		.Func(_SC("RotateBy"), &CObject::RotateBy)
		.Func(_SC("RotateToEuler"), &CObject::RotateToEuler)
		.Func(_SC("RotateByEuler"), &CObject::RotateByEuler)
		.Func(_SC("SetAlpha"), &CObject::SetAlpha)
		.Func(_SC("StreamedToPlayer"), &CObject::StreamedToPlayer);

	Sqrat::RootTable(v).Bind(_SC("CObject"), c);
}

void CObject::Delete(void) {
	g_pCore->F()->DeleteObject(m_nObjectId);
}

void CObject::SetWorld(int nWorld) {
	g_pCore->F()->SetObjectWorld(m_nObjectId, nWorld);
}

void CObject::SetPos(CVector * pPos) {
	g_pCore->F()->SetObjectPos(m_nObjectId, VECTOREX(pPos));
}

void CObject::SetReportingBumps(bool bReport) {
	g_pCore->F()->SetObjectBumpReport(m_nObjectId, bReport);
}

void CObject::SetReportingShots(bool bReport) {
	g_pCore->F()->SetObjectShotReport(m_nObjectId, bReport);
}

int CObject::GetModel(void) {
	return g_pCore->F()->GetObjectModel(m_nObjectId);
}

int CObject::GetAlpha(void) {
	return g_pCore->F()->GetObjectAlpha(m_nObjectId);
}

int CObject::GetWorld(void) {
	return g_pCore->F()->GetObjectWorld(m_nObjectId);
}

CVector CObject::GetPos(void) {
	float x, y, z;
	g_pCore->F()->GetObjectPos(m_nObjectId, &x, &y, &z);

	return CVector(x, y, z);
}

CQuaternion CObject::GetRotation(void) {
	float x, y, z, w;
	g_pCore->F()->GetObjectRot(m_nObjectId, &x, &y, &z, &w);

	return CQuaternion(x, y, z, w);
}

CVector CObject::GetRotationEuler(void) {
	float x, y, z;
	g_pCore->F()->GetObjectRotEuler(m_nObjectId, &x, &y, &z);

	return CVector(x, y, z);
}

bool CObject::GetReportingShots(void) {
	return g_pCore->F()->IsObjectShotReport(m_nObjectId) == 1;
}

bool CObject::GetReportingBumps(void) {
	return g_pCore->F()->IsObjectBumpReport(m_nObjectId) == 1;
}

void CObject::MoveTo(CVector * vecPos, int nTime) {
	g_pCore->F()->MoveObjectTo(m_nObjectId, VECTOREX(vecPos), nTime);
}

void CObject::MoveBy(CVector * vecOffset, int nTime) {
	g_pCore->F()->MoveObjectBy(m_nObjectId, VECTOREX(vecOffset), nTime);
}

void CObject::RotateTo(CQuaternion * quatRot, int nTime) {
	g_pCore->F()->RotObjectTo(m_nObjectId, QUATEX(quatRot), nTime);
}

void CObject::RotateBy(CQuaternion * quatOffset, int nTime) {
	g_pCore->F()->RotObjectBy(m_nObjectId, QUATEX(quatOffset), nTime);
}

void CObject::RotateToEuler(CVector * vecRot, int nTime) {
	g_pCore->F()->RotObjectToEuler(m_nObjectId, VECTOREX(vecRot), nTime);
}

void CObject::RotateByEuler(CVector * vecOffset, int nTime) {
	g_pCore->F()->RotObjectByEuler(m_nObjectId, VECTOREX(vecOffset), nTime);
}

void CObject::SetAlpha(int nAlpha, int nFadeTime) {
	g_pCore->F()->SetObjectAlpha(m_nObjectId, nAlpha, nFadeTime);
}

bool CObject::StreamedToPlayer(CPlayer * pPlayer) {
	return g_pCore->F()->IsObjectStreamedForPlayer(m_nObjectId, pPlayer->GetID()) == 1;
}