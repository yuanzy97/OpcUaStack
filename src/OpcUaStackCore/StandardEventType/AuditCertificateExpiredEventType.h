/*
    EventTypeClass: AuditCertificateExpiredEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AuditCertificateExpiredEventType_h__
#define __OpcUaStackCore_AuditCertificateExpiredEventType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardEventType/AuditCertificateEventType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AuditCertificateExpiredEventType
    : public AuditCertificateEventType
    {
      public:
        typedef boost::shared_ptr<AuditCertificateExpiredEventType> SPtr;
    
        AuditCertificateExpiredEventType(void);
        virtual ~AuditCertificateExpiredEventType(void);
        
        
        //- EventBase interface
        virtual void mapNamespaceUri(void);
        
        virtual OpcUaVariant::SPtr get(
            OpcUaNodeId& eventType,
            std::list<OpcUaQualifiedName::SPtr>& browseNameList,
            EventResult::Code& resultCode
        );
        //- EventBase interface
        
    
      private:
        EventVariables eventVariables_;
    
    };

}

#endif
