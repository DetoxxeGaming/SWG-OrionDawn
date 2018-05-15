/*
 * BaseClientEvent.h
 *
 *  Created on: 29/12/2009
 *      Author: victor
 */


namespace engine {
  namespace service {
    namespace proto {

	class BaseClientEvent;

    } // namespace proto
  } // namespace service
} // namespace engine

#include "engine/service/proto/BaseClient.h"

namespace engine {
  namespace service {
    namespace proto {

	class BaseClientEvent : public Task {
		WeakReference<BaseClient*> client;

	public:
		BaseClientEvent(BaseClient* cl) {
			client = cl;
		}

		void run() {
			Reference<BaseClient*> strong = client.get();

			if (strong == NULL)
				return;

			strong->run();
		}

	};

    } // namespace proto
  } // namespace service
} // namespace engine

using namespace engine::service::proto;

#ifndef BASECLIENTEVENT_H_
#define BASECLIENTEVENT_H_


#endif /* BASECLIENTEVENT_H_ */
