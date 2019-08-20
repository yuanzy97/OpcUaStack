/*
    EventTypeClass: BaseModelChangeEventType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/BaseModelChangeEventType.h"

namespace OpcUaStackCore
{
    
    BaseModelChangeEventType::BaseModelChangeEventType(void)
    : BaseEventType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("EMPTY", OpcUaBuildInType_OpcUaVariant);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2132));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("BaseModelChangeEventType"));
        eventVariables_.namespaceUri("");
    }
    
    BaseModelChangeEventType::~BaseModelChangeEventType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    BaseModelChangeEventType::getBaseModelChangeEventType(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("EMPTY", value);
    	return value;
    }
    
    bool 
    BaseModelChangeEventType::setBaseModelChangeEventType(OpcUaVariant::SPtr& value)
    {
    	return eventVariables_.setValue("EMPTY", value);
    }
    
    void
    BaseModelChangeEventType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        BaseEventType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    BaseModelChangeEventType::get(
    	OpcUaNodeId& eventType,
    	std::list<OpcUaQualifiedName::SPtr>& browseNameList,
    	EventResult::Code& resultCode
    )
    {
        resultCode = EventResult::Success;

        // check whether eventType and typeNodeId are identical
        if (eventType == eventVariables_.eventType()) {
    	    return eventVariables_.get(browseNameList, resultCode);
        }

        // the start item was not found. We delegate the search to the base class
        OpcUaVariant::SPtr variant;
        variant = BaseEventType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
