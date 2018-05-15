/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef DISTRIBUTEDOBJECTADAPTER_H_
#define DISTRIBUTEDOBJECTADAPTER_H_

#include "DistributedObjectStub.h"

#include "engine/orb/messages/DOBMessage.h"

namespace engine {
  namespace ORB {

	class DistributedMethod;

	class DistributedObjectServant;
	
	class DistributedObjectAdapter {
	protected:
		//DistributedObjectServant* impl;

		DistributedObjectStub* stub;

		
	public:
		DistributedObjectAdapter(DistributedObjectStub* obj) {
			//impl = obj;
			stub = NULL;
		}
		
		virtual ~DistributedObjectAdapter() {
		}
		
		virtual void invokeMethod(sys::uint32 methid, DistributedMethod* inv) = 0;
		
		inline void setStub(DistributedObjectStub* stb) {
			stub = stb;
		}
		
		/*inline DistributedObjectServant* getImplementation() {
			return impl;
		}*/
	
		inline DistributedObjectStub* getStub() {
			return stub;
		}
	
	};

  } // namespace ORB
} // namespace engine

using namespace engine::ORB;

#endif /*DISTRIBUTEDOBJECTADAPTER_H_*/
