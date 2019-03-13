/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */
#ifndef __OpcUaStackClient_SessionServiceStateError_h__
#define __OpcUaStackClient_SessionServiceStateError_h__

#include "OpcUaStackClient/ServiceSet/SessionServiceStateIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceStateError
	: public SessionServiceStateIf
	{
	  public:
		SessionServiceStateError(void);
		~SessionServiceStateError(void);

		virtual SessionServiceStateId asyncConnect(
			SessionTransaction::SPtr& sessionTransaction
		) override;
		virtual SessionServiceStateId asyncDisconnect(
			SessionTransaction::SPtr& sessionTransaction,
			bool deleteSubscriptions
		) override;
		virtual SessionServiceStateId asyncCancel(
			SessionTransaction::SPtr& sessionTransaction,
			uint32_t requestHandle
		) override;

		virtual SessionServiceStateId handleConnect(SecureChannel* secureChannel) override;
		virtual SessionServiceStateId handleDisconnect(SecureChannel* secureChannel) override;
		virtual SessionServiceStateId recvCreateSessionResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvActivateSessionResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvCloseSessionResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvMessageResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) override;

		virtual SessionServiceStateId sendMessageRequest(Message::SPtr message) override;

		virtual SessionServiceStateId reconnectTimeout(void) override;
		virtual SessionServiceStateId pendingQueueTimeout(const Object::SPtr& object) override;
	};

}

#endif
