/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef STATEUPDATEMESSAGE_H_
#define STATEUPDATEMESSAGE_H_

#include "system/lang.h"

#include "engine/orb/messages/RemoteObjectBroker.h"

#include "engine/orb/messages/DOBMessage.h"

#include "ObjectBrokerDirector.h"

namespace engine {
  namespace ORB {

	class StateUpdateMessage : public DOBMessage {
		int state;

	public:	
		StateUpdateMessage(int state) : DOBMessage(STATEUPDATEMESSAGE, 20) {
			insertInt(state);
		}
	
		StateUpdateMessage(Packet* message) : DOBMessage(message) {
			state = message->parseInt();
		}

		void execute() {
			ObjectBrokerDirector* director = ObjectBrokerDirector::instance();

			RemoteObjectBroker* remoteBroker = getClient()->getRemoteObjectBroker();

			director->handleStateUpdate(remoteBroker, state);
		}
	};

  } // namespace ORB
} // namespace engine

using namespace engine::ORB;

#endif /*STATEUPDATEMESSAGE_H_*/
