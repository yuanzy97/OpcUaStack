/*
    DataTypeClass: StructureDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_StructureDefinition_h__
#define __OpcUaStackCore_StructureDefinition_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/StructureType.h"
#include "OpcUaStackCore/StandardDataTypes/StructureField.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT StructureDefinition
    : public DataTypeDefinition
    {
      public:
        typedef boost::shared_ptr<StructureDefinition> SPtr;
        typedef std::vector<StructureDefinition::SPtr> Vec;
    
        StructureDefinition(void);
        StructureDefinition(const StructureDefinition& value);
        virtual ~StructureDefinition(void);
        
        OpcUaNodeId& defaultEncodingId(void);
        OpcUaNodeId& baseDataType(void);
        StructureType& structureType(void);
        StructureFieldArray& fields(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
        void copyTo(StructureDefinition& value);
        bool operator==(const StructureDefinition& value);
        bool operator!=(const StructureDefinition& value);
        StructureDefinition& operator=(const StructureDefinition& value);
    
      private:
        OpcUaNodeId defaultEncodingId_;
        OpcUaNodeId baseDataType_;
        StructureType structureType_;
        StructureFieldArray fields_;
    
    };
    
    class DLLEXPORT StructureDefinitionArray
    : public OpcUaArray<StructureDefinition::SPtr, SPtrTypeCoder<StructureDefinition> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<StructureDefinitionArray> SPtr;
    };

}

#endif
