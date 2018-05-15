/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef THREADLOCAL_H_
#define THREADLOCAL_H_

#include "system/platform.h"
#include "system/lang/types.h"

#include <pthread.h>

#include <signal.h>

namespace sys {
 namespace thread {

	template<typename T>
	class DefaultThreadLocalDestructor {
	public:
		const static int hasDestructor = false;

		void run(void* value) {
		}
	};

	template<typename T>
	class DefaultThreadLocalDestructor<T*> {
	public:
		const static int hasDestructor = true;

		void run(void* value) {
			if (value) {
				delete reinterpret_cast<T*>(value);
			}
		}
	};

	template<class T> class ThreadLocal {
		pthread_key_t dataKey;
		void (*keyDestructor)(void*);
	public:
		ThreadLocal();

		/**
		 *  If a destructor is specified, key_delete is not called in ThreadLocal dtor
		 * @param keyDestructor
		 */
		ThreadLocal(void (*keyDestructor)(void*));

		virtual ~ThreadLocal();

		T get();

		void remove();

		void set(const T& value);

	protected:
		void createKey(void (*keyDestructor)(void*) = NULL);

		static void defaultThreadLocalDeleteDtor(void* value) {
			DefaultThreadLocalDestructor<T> destructor;
			destructor.run(value);
		}

		virtual void deleteKey();

		virtual T initValue() {
			return TypeInfo<T>::nullValue();
		}

		T getValue();
	};

	template<class T> ThreadLocal<T>::ThreadLocal() : keyDestructor(NULL) {
		createKey(NULL);
	}

	template<class T> ThreadLocal<T>::ThreadLocal(void (*keyDtor)(void*) ) : keyDestructor(NULL) {
		createKey(keyDtor);
	}

	template<class T> ThreadLocal<T>::~ThreadLocal() {
		if (!keyDestructor)
			deleteKey();
	}

	template<class T> T ThreadLocal<T>::get() {
		T value = getValue();

		if (value == TypeInfo<T>::nullValue()) {
			value = initValue();

			set(value);
		}

		return value;
	}

	template<class T> void ThreadLocal<T>::remove() {
		set(NULL);
	}

	template <class T> void ThreadLocal<T>::set(const T& value) {
		pthread_setspecific(dataKey, reinterpret_cast<void*>(value));
	}

	template<class T> void ThreadLocal<T>::createKey(void (*dtor)(void*)) {
		if (dtor == NULL && TypeInfo<T>::type == TypeInfoAtomicBase<T>::POINTER) {
			keyDestructor = defaultThreadLocalDeleteDtor;
		} else {
			keyDestructor = dtor;
		}

		if (pthread_key_create(&dataKey, keyDestructor) != 0) {
			raise(SIGSEGV);
		}
	}

	template<class T> void ThreadLocal<T>::deleteKey() {
		pthread_key_delete(dataKey);
	}

	template<class T> T ThreadLocal<T>::getValue() {
		return (T) pthread_getspecific(dataKey);
	}
 }
}

using namespace sys::thread;

#endif /* THREADLOCAL_H_ */
