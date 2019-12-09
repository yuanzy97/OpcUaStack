/*
    VariableTypeClass: AuditCertificateUntrustedEventType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/AuditCertificateUntrustedEventType.h"

namespace OpcUaStackServer
{
    
    AuditCertificateUntrustedEventType::AuditCertificateUntrustedEventType(void)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , certificate_Variable_(boost::make_shared<ServerVariable>("Certificate_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2087);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(certificate_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    AuditCertificateUntrustedEventType::AuditCertificateUntrustedEventType(const AuditCertificateUntrustedEventType& value)
    : ObjectBase()
    , actionTimeStamp_Variable_(boost::make_shared<ServerVariable>("ActionTimeStamp_Variable"))
    , certificate_Variable_(boost::make_shared<ServerVariable>("Certificate_Variable"))
    , clientAuditEntryId_Variable_(boost::make_shared<ServerVariable>("ClientAuditEntryId_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , serverId_Variable_(boost::make_shared<ServerVariable>("ServerId_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , statusCodeId_Variable_(boost::make_shared<ServerVariable>("StatusCodeId_Variable"))
    , status_Variable_(boost::make_shared<ServerVariable>("Status_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2087);
        setServerVariable(actionTimeStamp_Variable_);
        setServerVariable(certificate_Variable_);
        setServerVariable(clientAuditEntryId_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(serverId_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(statusCodeId_Variable_);
        setServerVariable(status_Variable_);
        setServerVariable(time_Variable_);
    }
    
    AuditCertificateUntrustedEventType::~AuditCertificateUntrustedEventType(void)
    {
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::actionTimeStamp_Variable(void)
    {
        return actionTimeStamp_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::certificate_Variable(void)
    {
        return certificate_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::clientAuditEntryId_Variable(void)
    {
        return clientAuditEntryId_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::serverId_Variable(void)
    {
        return serverId_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::statusCodeId_Variable(void)
    {
        return statusCodeId_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::status_Variable(void)
    {
        return status_Variable_;
    }

    ServerVariable::SPtr&
    AuditCertificateUntrustedEventType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    AuditCertificateUntrustedEventType::actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        actionTimeStamp_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::certificate_Variable(ServerVariable::SPtr& serverVariable)
    {
        certificate_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientAuditEntryId_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::serverId_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverId_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::statusCodeId_Variable(ServerVariable::SPtr& serverVariable)
    {
        statusCodeId_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::status_Variable(ServerVariable::SPtr& serverVariable)
    {
        status_Variable_ = serverVariable;
    }

    void
    AuditCertificateUntrustedEventType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    AuditCertificateUntrustedEventType::get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_Certificate_Variable(OpcUaDataValue& dataValue)
    {
        return certificate_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_ServerId_Variable(OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_StatusCodeId_Variable(OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_Status_Variable(OpcUaDataValue& dataValue)
    {
        return status_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue)
    {
        return actionTimeStamp_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_Certificate_Variable(const OpcUaDataValue& dataValue)
    {
        return certificate_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientAuditEntryId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_ServerId_Variable(const OpcUaDataValue& dataValue)
    {
        return serverId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_StatusCodeId_Variable(const OpcUaDataValue& dataValue)
    {
        return statusCodeId_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_Status_Variable(const OpcUaDataValue& dataValue)
    {
        return status_Variable_->setDataValue(dataValue);
    }

    bool
    AuditCertificateUntrustedEventType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

}