/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef UNDEPLOYOBJECTMESSAGE_H_
#define UNDEPLOYOBJECTMESSAGE_H_

#include "system/lang.h"

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/orb/object/DistributedObjectStub.h"

#include "engine/orb/messages/RemoteObjectBroker.h"

#include "DOBMessage.h"

namespace engine {
  namespace ORB {

	class UndeployObjectMessage : public DOBMessage {
		String name;

		uint64 objectID;

	public:	
		UndeployObjectMessage(const String& name) : DOBMessage(UNDEPLOYOBJECTMESSAGE, 40) {
			insertAscii(name);

			objectID = 0;
		}
	
		UndeployObjectMessage(Packet* message) : DOBMessage(message) {
			message->parseAscii(name);

			objectID = 0;
		}

		void execute() {
			DistributedObjectBroker* broker = DistributedObjectBroker::instance();

			DistributedObjectStub* obj = NULL;
			try {
				obj = broker->undeployRemote(name);
			} catch (const Exception& e) {
				e.printStackTrace();
			}

			uint64 objectID = 0;
			if (obj != NULL)
				objectID = obj->_getObjectID();

			insertLong(objectID);

			client->sendReply(this);

		}

		void handleReply(Packet* message) {
			objectID = message->parseLong();
		}

		uint64 getObjectID() {
			return objectID;
		}
	};

  } // namespace ORB
} // namespace engine

using namespace engine::ORB;

#endif /*UNDEPLOYOBJECTMESSAGE_H_*/
