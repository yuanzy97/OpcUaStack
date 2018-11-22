/*
    DataTypeClass: EventFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EventFilterResult.h"

namespace OpcUaStackCore
{
    
    EventFilterResult::EventFilterResult(void)
    : MonitoringFilterResult()
    , selectClauseResults_()
    , selectClauseDiagnosticInfos_()
    , whereClauseResult_()
    {
    }
    
    EventFilterResult::~EventFilterResult(void)
    {
    }
    
    OpcUaStatusArray&
    EventFilterResult::selectClauseResults(void)
    {
        return selectClauseResults_;
    }
    
    OpcUaDiagnosticInfoArray&
    EventFilterResult::selectClauseDiagnosticInfos(void)
    {
        return selectClauseDiagnosticInfos_;
    }
    
    ContentFilterResult&
    EventFilterResult::whereClauseResult(void)
    {
        return whereClauseResult_;
    }
    
    bool
    EventFilterResult::operator==(const EventFilterResult& value)
    {
        EventFilterResult* dst = const_cast<EventFilterResult*>(&value);
        if (selectClauseResults_ != dst->selectClauseResults()) return false;
        if (selectClauseDiagnosticInfos_ != dst->selectClauseDiagnosticInfos()) return false;
        if (whereClauseResult_ != dst->whereClauseResult()) return false;
        return true;
    }
    
    bool
    EventFilterResult::operator!=(const EventFilterResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    EventFilterResult::copyTo(EventFilterResult& value)
    {
        selectClauseResults_.copyTo(value.selectClauseResults());
        selectClauseDiagnosticInfos_.copyTo(value.selectClauseDiagnosticInfos());
        whereClauseResult_.copyTo(value.whereClauseResult());
    }
    
    EventFilterResult&
    EventFilterResult::operator=(const EventFilterResult& value)
    {
        const_cast<EventFilterResult*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    EventFilterResult::factory(void)
    {
    	return constructSPtr<EventFilterResult>();
    }
    
    std::string
    EventFilterResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EventFilterResult::typeName(void)
    {
    	return "EventFilterResult";
    }
    
    OpcUaNodeId
    EventFilterResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)734,0);
    }
    
    OpcUaNodeId
    EventFilterResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)736, 0);
    }
    
    OpcUaNodeId
    EventFilterResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)735, 0);
    }
    
    OpcUaNodeId
    EventFilterResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15314, 0);
    }
    
    void
    EventFilterResult::opcUaBinaryEncode(std::ostream& os) const
    {
        MonitoringFilterResult::opcUaBinaryEncode(os);
        selectClauseResults_.opcUaBinaryEncode(os);
        selectClauseDiagnosticInfos_.opcUaBinaryEncode(os);
        whereClauseResult_.opcUaBinaryEncode(os);
    }
    
    void
    EventFilterResult::opcUaBinaryDecode(std::istream& is)
    {
        MonitoringFilterResult::opcUaBinaryDecode(is);
        selectClauseResults_.opcUaBinaryDecode(is);
        selectClauseDiagnosticInfos_.opcUaBinaryDecode(is);
        whereClauseResult_.opcUaBinaryDecode(is);
    }
    
    bool
    EventFilterResult::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    EventFilterResult::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    EventFilterResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EventFilterResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!selectClauseResults_.xmlEncode(elementTree, "Status", xmlns)) return false;
        pt.push_back(std::make_pair("SelectClauseResults", elementTree));
    
        elementTree.clear();
        if (!selectClauseDiagnosticInfos_.xmlEncode(elementTree, "DiagnosticInfo", xmlns)) return false;
        pt.push_back(std::make_pair("SelectClauseDiagnosticInfos", elementTree));
    
        elementTree.clear();
        if (!whereClauseResult_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("WhereClauseResult", elementTree));
    
        return true;
    }
    
    bool
    EventFilterResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EventFilterResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("SelectClauseResults");
        if (!tree) return false;
        if (!selectClauseResults_.xmlDecode(*tree, "Status", xmlns)) return false;
    
        tree = pt.get_child_optional("SelectClauseDiagnosticInfos");
        if (!tree) return false;
        if (!selectClauseDiagnosticInfos_.xmlDecode(*tree, "DiagnosticInfo", xmlns)) return false;
    
        tree = pt.get_child_optional("WhereClauseResult");
        if (!tree) return false;
        if (!whereClauseResult_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    EventFilterResult::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    EventFilterResult::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    EventFilterResult::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    EventFilterResult::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    EventFilterResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EventFilterResult* dst = dynamic_cast<EventFilterResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EventFilterResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EventFilterResult* dst = dynamic_cast<EventFilterResult*>(&extensionObjectBase);
    	return *const_cast<EventFilterResult*>(this) == *dst;
    }
    
    void
    EventFilterResult::out(std::ostream& os)
    {
        os << "SelectClauseResults="; selectClauseResults_.out(os);
        os << ", SelectClauseDiagnosticInfos="; selectClauseDiagnosticInfos_.out(os);
        os << ", WhereClauseResult="; whereClauseResult_.out(os);
    }

}
