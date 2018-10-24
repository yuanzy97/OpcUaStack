/*
    EnumTypeClass: IdType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/IdType.h"

namespace OpcUaStackCore
{
    
    IdType::IdType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    IdType::~IdType(void)
    {
    }
    
    uint32_t&
    IdType::value(void)
    {
        return value_;
    }
    
    void
    IdType::enumeration(IdType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    IdType::Enum
    IdType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    IdType::Enum
    IdType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Numeric") return (Enum)0;
        if (enumerationString == "String") return (Enum)1;
        if (enumerationString == "Guid") return (Enum)2;
        if (enumerationString == "Opaque") return (Enum)3;
        return (Enum)0;
    }
    
    std::string
    IdType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Numeric";
        if (enumeration == 1) return "String";
        if (enumeration == 2) return "Guid";
        if (enumeration == 3) return "Opaque";
        return "Unknown";
    }
    
    bool
    IdType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Numeric") return true;
        if (enumerationString == "String") return true;
        if (enumerationString == "Guid") return true;
        if (enumerationString == "Opaque") return true;
        return false;
    }
    
    bool
    IdType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    IdType::operator==(const IdType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    IdType::operator!=(const IdType& value) const
    {
        return !this->operator==(value);
    }
    
    void
    IdType::copyTo(IdType& value)
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
    IdType::factory(void)
    {
    	return constructSPtr<IdType>();
    }
    
    OpcUaNodeId
    IdType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    IdType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    IdType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    IdType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    IdType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    IdType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    IdType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    IdType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    IdType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    IdType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	IdType* dst = dynamic_cast<IdType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    IdType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	IdType* dst = dynamic_cast<IdType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    IdType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
