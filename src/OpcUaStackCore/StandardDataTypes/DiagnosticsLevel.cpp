/*
    EnumTypeClass: DiagnosticsLevel

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DiagnosticsLevel.h"

namespace OpcUaStackCore
{
    
    DiagnosticsLevel::DiagnosticsLevel(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    DiagnosticsLevel::~DiagnosticsLevel(void)
    {
    }
    
    uint32_t&
    DiagnosticsLevel::value(void)
    {
        return value_;
    }
    
    void
    DiagnosticsLevel::enumeration(DiagnosticsLevel::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    DiagnosticsLevel::Enum
    DiagnosticsLevel::enumeration(void)
    {
        return (Enum)value_;
    }
    
    DiagnosticsLevel::Enum
    DiagnosticsLevel::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Basic") return (Enum)0;
        if (enumerationString == "Advanced") return (Enum)1;
        if (enumerationString == "Info") return (Enum)2;
        if (enumerationString == "Log") return (Enum)3;
        if (enumerationString == "Debug") return (Enum)4;
        return (Enum)0;
    }
    
    std::string
    DiagnosticsLevel::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Basic";
        if (enumeration == 1) return "Advanced";
        if (enumeration == 2) return "Info";
        if (enumeration == 3) return "Log";
        if (enumeration == 4) return "Debug";
        return "Unknown";
    }
    
    bool
    DiagnosticsLevel::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Basic") return true;
        if (enumerationString == "Advanced") return true;
        if (enumerationString == "Info") return true;
        if (enumerationString == "Log") return true;
        if (enumerationString == "Debug") return true;
        return false;
    }
    
    bool
    DiagnosticsLevel::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        return false;
    }
    
    bool
    DiagnosticsLevel::operator==(const DiagnosticsLevel& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    DiagnosticsLevel::operator!=(const DiagnosticsLevel& value) const
    {
        return !this->operator==(value);
    }
    
    void
    DiagnosticsLevel::copyTo(DiagnosticsLevel& value)
    {
        value.value_ = value_;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    DiagnosticsLevel::factory(void)
    {
    	return constructSPtr<DiagnosticsLevel>();
    }
    
    OpcUaNodeId
    DiagnosticsLevel::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DiagnosticsLevel::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    DiagnosticsLevel::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    DiagnosticsLevel::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    DiagnosticsLevel::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DiagnosticsLevel::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DiagnosticsLevel::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    DiagnosticsLevel::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DiagnosticsLevel::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    DiagnosticsLevel::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DiagnosticsLevel* dst = dynamic_cast<DiagnosticsLevel*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DiagnosticsLevel::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DiagnosticsLevel* dst = dynamic_cast<DiagnosticsLevel*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    DiagnosticsLevel::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
