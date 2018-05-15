/*
 * TransactionalWeakReference.h
 *
 *  Created on: Jun 17, 2011
 *      Author: theanswer
 */

#ifndef TRANSACTIONALWEAKREFERENCE_H_
#define TRANSACTIONALWEAKREFERENCE_H_

#include "Transaction.h"

namespace engine {
  namespace stm {
  
  template<class O> class TransactionalReference;

#ifndef WITH_STM
  template<class O> class TransactionalWeakReference : public WeakReference<O> {
public:
	  TransactionalWeakReference() : WeakReference<O>() {

	  }

	  TransactionalWeakReference(const TransactionalWeakReference& ref) : WeakReference<O>(ref) {

	  }

	  TransactionalWeakReference(const WeakReference<O>& ref) : WeakReference<O>(ref) {

	  }

	  TransactionalWeakReference(O obj) : WeakReference<O>(obj) {

	  }

	  TransactionalWeakReference& operator=(const TransactionalWeakReference& ref) {
		  WeakReference<O>::operator=(ref);

		  return *this;
	  }

	  TransactionalWeakReference& operator=(const Reference<O> ref) {
		  WeakReference<O>::operator=(ref);

		  return *this;
	  }

	  O operator=(O obj) {
		  return WeakReference<O>::operator=(obj);
	  }
  };
#else

  	template<class O> class TransactionalWeakReference {
		Reference<TransactionalObjectHeader<O>* > header;

	public:
		TransactionalWeakReference() {
			header = NULL;
		}

		TransactionalWeakReference(O object) {
			setObject(object);
		}

		TransactionalWeakReference(const TransactionalWeakReference& ref) {
			header = ref.header;
		}

		TransactionalWeakReference& operator=(const TransactionalWeakReference& ref) {
			if (this == &ref)
				return *this;

			header = ref.header;

			return *this;
		}

		O operator=(O obj) {
			setObject(obj);

			return obj;
		}

		bool operator==(O obj) {
			return header == getHeader(obj);
		}

		bool operator!=(O obj) {
			return header != getHeader(obj);
		}

		O get() {
			if (header != NULL)
				return header->get();
			else
				return NULL;
		}

		O getForUpdate() {
			if (header != NULL)
				return header->getForUpdate();
			else
				return NULL;
		}

		bool toBinaryStream(ObjectOutputStream* stream) {
			return get()->toBinaryStream(stream);
		}

		bool parseFromBinaryStream(ObjectInputStream* stream) {
			return getForUpdate()->parseFromBinaryStream(stream);
		}
		
		template<class A> friend class TransactionalReference;

	protected:
		TransactionalObjectHeader<O>* getHeader(O object) {
			if (object == NULL)
				return NULL;

			return Transaction::currentTransaction()->getHeader(object);
		}

		void setObject(O object) {
			header = getHeader(object);
		}
	};

#endif

  } // namespace stm
} // namespace engine

#endif /* TRANSACTIONALWEAKREFERENCE_H_ */
