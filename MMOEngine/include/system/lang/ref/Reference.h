/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include "system/lang/Object.h"

#include "system/lang/Long.h"

#include "system/thread/atomic/AtomicReference.h"
#include "system/thread/atomic/AtomicInteger.h"

namespace sys {
  namespace lang {

#ifdef TRACE_REFERENCES
  	  class ReferenceIdCounter {
  	  public:
  		  static AtomicInteger nextID;
  	  };
#endif


	template<class O> class Reference {
	protected:
		AtomicReference<O> object;

#ifdef TRACE_REFERENCES
		AtomicInteger id;
#endif

	public:
		Reference() : object() {
			//object = NULL;
#ifdef TRACE_REFERENCES
			id = ReferenceIdCounter::nextID.increment();
#endif
		}

		Reference(const Reference& ref)  {
#ifdef TRACE_REFERENCES
			id = ReferenceIdCounter::nextID.increment();
#endif
			initializeObject(ref.object.get());
		}

#ifdef CXX11_COMPILER
		Reference(Reference<O>&& ref) : object(ref.object) {
			ref.object = NULL;

#ifdef TRACE_REFERENCES
			id = ref.id;
			ref.id = 0;
#endif
		}
#endif

		Reference(O obj) {
#ifdef TRACE_REFERENCES
			id = ReferenceIdCounter::nextID.increment();
#endif

			initializeObject(obj);
		}

		inline ~Reference() {
			releaseObject();
		}

		int compareTo(const Reference& val) const {
			if (std::less<Object*>()(object, val.object)) {
				return 1;
			} else if (object == val.object) {
				return 0;
			} else {
				return -1;
			}
		}

		Reference& operator=(const Reference& ref) {
			if (this == &ref)
				return *this;

			updateObject(ref.object.get());

			return *this;
		}

#ifdef CXX11_COMPILER
		Reference& operator=(Reference&& ref) {
			if (this == &ref)
				return *this;

			releaseObject();

			object = ref.object;

			ref.object = NULL;

#ifdef TRACE_REFERENCES
			id = ref.id;
			ref.id = 0;
#endif

			return *this;
		}
#endif

		int hashCode() const {
			return UnsignedLong::hashCode((uint64)object.get());
		}

		inline O operator=(O obj) {
			updateObject(obj);

			return object.get();
		}

		inline bool operator==(O obj) const {
			return object.get() == obj;
		}

		inline bool operator!=(O obj) const {
			return object.get() != obj;
		}

		inline O operator->() const {
			return object.get();
		}

		inline operator O() const {
			return object.get();
		}

		template<class B>
		Reference<B> castTo() const {
			Reference<B> stored = dynamic_cast<B>(get());
			return stored;
		}

		inline O get() const {
			return object.get();
		}

		bool toBinaryStream(ObjectOutputStream* stream) {
			//return object->toBinaryStream(stream);
			return false;
		}

		bool parseFromBinaryStream(ObjectInputStream* stream) {
			//return object->parseFromBinaryStream(stream);
			return false;
		}

		O compareAndSetReturnOld(O oldval, O newval) {
			O oldRef = object.compareAndSetReturnOld(oldval, newval);

			if (oldval == oldRef) { //success
				if (newval != NULL) {
					(newval)->acquire();

					#ifdef TRACE_REFERENCES
					newval->addHolder(id);
					#endif
				}

				if (oldval != NULL) {
					#ifdef TRACE_REFERENCES
					oldval->removeHolder(id);
					#endif

					(oldval)->release();
				}
			}

			return oldRef;
		}

		inline void initializeWithoutAcquire(O obj) {
			object = obj;
		}

		bool compareAndSet(O oldval, O newval) {
			bool success = object.compareAndSet(oldval, newval);

			if (success) {
				if (newval != NULL) {
					(newval)->acquire();

					#ifdef TRACE_REFERENCES
					newval->addHolder(id);
					#endif
				}

				if (oldval != NULL) {
					#ifdef TRACE_REFERENCES
					oldval->removeHolder(id);
					#endif

					(oldval)->release();
				}
			}

			return success;
		}

	protected:
		//lock free
		inline void updateObject(O obj) {
			if (obj != NULL) {
				(obj)->acquire();

				#ifdef TRACE_REFERENCES
				Object* castedObject = dynamic_cast<Object*>(obj);

				castedObject->addHolder(id);
				#endif
			}

			while (true) {
				O oldobj = object.get();

				if (object.compareAndSet(oldobj, obj)) {
					if (oldobj != NULL) {
						#ifdef TRACE_REFERENCES
						Object* castedObject = dynamic_cast<Object*>(oldobj);

						castedObject->removeHolder(id);
						#endif

						(oldobj)->release();
					}

					return;
				}

				//Thread::yield();
			}

		}

		inline void setObject(O obj) {
			if (obj == object)
				return;

			initializeObject(obj);
		}

		inline void initializeObject(O obj) {
			object = obj;

			acquireObject();
		}

		inline void acquireObject() {
			if (object != NULL) {
			#ifdef TRACE_REFERENCES
				(object.get())->addHolder(id);
			#endif
				(object.get())->acquire();
			}
		}

		inline void releaseObject() {
			if (object != NULL) {
			#ifdef TRACE_REFERENCES
				(object.get())->removeHolder(id);
			#endif
				(object.get())->release();
				object = NULL;
			}
		}
	};

	

  } // namespace lang
} // namespace sys

using namespace sys::lang;

#endif /*REFERENCE_H_*/
