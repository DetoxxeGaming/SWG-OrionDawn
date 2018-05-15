/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef DEPLOYOBJECTMESSAGE_H_
#define DEPLOYOBJECTMESSAGE_H_

#include "system/lang.h"

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/orb/object/DistributedObjectStub.h"

#include "engine/orb/messages/RemoteObjectBroker.h"

#include "DOBMessage.h"

namespace engine {
  namespace ORB {

	class DeployObjectMessage : public DOBMessage {
		String name;
		String className;

		uint64 requestedObjectID;

		bool deployed;
		uint64 objectID;

	public:	
		DeployObjectMessage(const String& name, const String& classname, uint64 requestedObjectID);
		DeployObjectMessage(Packet* message);

		void execute();

		void handleReply(Packet* message);

		bool isDeployed() const {
			return deployed;
		}

		uint64 getObjectID() const {
			return objectID;
		}
	};

  } // namespace ORB
} // namespace engine

using namespace engine::ORB;

#endif /*DEPLOYOBJECTMESSAGE_H_*/
