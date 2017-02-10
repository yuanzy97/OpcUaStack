/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ForwardGlobalSync_h__
#define __OpcUaStackCore_ForwardGlobalSync_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardInfo.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardGlobalSync
	: public Object
	{
	  public:
		typedef boost::shared_ptr<ForwardGlobalSync> SPtr;

		ForwardGlobalSync(void);
		virtual ~ForwardGlobalSync(void);

		ForwardInfo& registerServerService(void);
		ForwardInfo& findServersService(void);

		void updateFrom(ForwardGlobalSync& forwardGlobalSync);

	  private:
		// discovery service
		ForwardInfo registerServerService_;
		ForwardInfo findServersService_;
	};

}

#endif