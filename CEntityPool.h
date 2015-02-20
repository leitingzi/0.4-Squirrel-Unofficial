/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CEntityPool.h

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
#include "classes/IEntity.h"
#include <sqrat.h>
#include <stdint.h>

// If T does not implement IEntity, this will fail!
template<typename T, const uint32_t MAX_ENTITIES>
class CEntityPool
{
	private:
		Sqrat::SharedPtr<T>* m_pEntities[MAX_ENTITIES];
		uint32_t GetNextFreeSlot(void) {
			for (uint32_t i = 0; i < MAX_ENTITIES; i++) {
				if (m_pEntities[i] != NULL) {
					return i;
				}
			}

			return -1;
		}

		uint32_t GetByPointer(T* pEntity) {
			for (uint32_t i = 0; i < MAX_ENTITIES; i++) {
				if (m_pEntities[i] == pEntity) {
					return i;
				}
			}

			return -1;
		}

	public:
		CEntityPool() {
			for (uint32_t i = 0; i < MAX_ENTITIES; i++) {
				m_pEntities[i] = NULL;
			}
		}

		~CEntityPool() {
			for (uint32_t i = 0; i < MAX_ENTITIES; i++) {
				if (m_pEntities[i] != NULL) {
					delete m_pEntities[i];
				}
			}
		}

		Sqrat::SharedPtr<T*> Get(unsigned int uiSlot) {
			if (uiSlot >= MAX_ENTITIES) {
				return NULL;
			}

			return m_pEntities[uiSlot];
		}

		Sqrat::WeakPtr<T*> GetWeakRef(unsigned int uiSlot) {
			Sqrat::SharedPtr<T*> pEntity = Get(uiSlot);
			if (pEntity == NULL) {
				return NULL;
			}

			return Sqrat::WeakPtr<T*>(pEntity);
		}

		bool New(int nEntityId, bool bIsScriptEntity = true) {
			uint32_t uiFreeSlot = GetNextFreeSlot();
			if (uiFreeSlot == -1) {
				return false;
			}

			T* pEntity = new T(nEntityId, bIsScriptEntity);
			m_pEntities[uiFreeSlot] = new Sqrat::SharedPtr<T>(pEntity);

			return true;
		}

		bool Delete(T* pEntity) {
			uint32_t uiSlot = GetByPointer(pEntity);
			if (uiSlot == -1) {
				return false;
			}

			return Delete(uiSlot);
		}

		bool Delete(unsigned int uiSlot) {
			if (m_pEntities[uiSlot] != NULL) {
				m_pEntities[uiSlot]->Delete();

				delete m_pEntities[uiSlot];
				m_pEntities[uiSlot] = NULL;

				return true;
			}

			return false;
		}

		bool Remove(T* pEntity) {
			uint32_t uiSlot = GetByPointer(pEntity);
			if (uiSlot == -1) {
				return false;
			}

			return Remove(uiSlot);
		}

		bool Remove(unsigned int uiSlot) {
			if (m_pEntities[uiSlot] != NULL) {
				delete m_pEntities[uiSlot];
				m_pEntities[uiSlot] = NULL;

				return true;
			}

			return false;
		}

		void RemoveAllScriptEntities(void) {
			for (uint32_t i = 0; i < MAX_ENTITIES; i++) {
				if (m_pEntities[i] != NULL && m_pEntities[i]->IsScriptEntity()) {
					Delete(i);
				}
			}
		}
};