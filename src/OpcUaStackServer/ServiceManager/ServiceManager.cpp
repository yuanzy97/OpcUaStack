/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceManager/ServiceManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServiceManager::ServiceManager(void)
	: transactionManager_(boost::make_shared<TransactionManager>())
	, applicationService_(boost::make_shared<ApplicationService>())
	, discoveryService_(boost::make_shared<DiscoveryService>())
	, forwardGlobalSync_(boost::make_shared<ForwardGlobalSync>())
	{
		applicationService_->componentName("ApplicationService");
		discoveryService_->componentName("DiscoveryService");

		initForwardGlobalSync();
	}

	ServiceManager::~ServiceManager(void)
	{
	}

	void
	ServiceManager::initForwardGlobalSync(void)
	{
		applicationService_->forwardGlobalSync(forwardGlobalSync_);
		discoveryService_->forwardGlobalSync(forwardGlobalSync_);
	}

	void
	ServiceManager::initAttributeService(void)
	{
		attributeService_ = boost::make_shared<AttributeService>(
			"AttributeServiceServer",
			ioThread_,
			messageBus_
		);
		attributeService_->componentName("AttributeService");		// FIXME: obsolete
		attributeService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionRead::name("Read");
		ServiceTransactionWrite::name("Write");
		ServiceTransactionHistoryRead::name("HistoryRead");
		ServiceTransactionHistoryUpdate::name("HistoryUpdate");

		auto serviceTransactionRead = boost::make_shared<ServiceTransactionRead>();
		auto serviceTransactionWrite = boost::make_shared<ServiceTransactionWrite>();
		auto serviceTransactionHistoryRead = boost::make_shared<ServiceTransactionHistoryRead>();
		auto serviceTransactionHistoryUpdate = boost::make_shared<ServiceTransactionHistoryUpdate>();

		serviceTransactionRead->componentService(&*attributeService_);
		serviceTransactionWrite->componentService(&*attributeService_);
		serviceTransactionHistoryRead->componentService(&*attributeService_);
		serviceTransactionHistoryUpdate->componentService(&*attributeService_);

		transactionManager_->registerTransaction(serviceTransactionRead);
		transactionManager_->registerTransaction(serviceTransactionWrite);
		transactionManager_->registerTransaction(serviceTransactionHistoryRead);
		transactionManager_->registerTransaction(serviceTransactionHistoryUpdate);
	}

	void
	ServiceManager::initMethodService(void)
	{
		methodService_ = boost::make_shared<MethodService>(
			"MethodServiceServer",
			ioThread_,
			messageBus_
		);
		methodService_->componentName("MethodService");		// FIXME: obsolete
		methodService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCall::name("Call");

		auto serviceTransactionCall = boost::make_shared<ServiceTransactionCall>();

		serviceTransactionCall->componentService(&*methodService_);

		transactionManager_->registerTransaction(serviceTransactionCall);
	}

	void
	ServiceManager::initNodeManagementService(void)
	{
		nodeManagementService_ = boost::make_shared<NodeManagementService>(
			"NodeManagementServiceServer",
			ioThread_,
			messageBus_
		);
		nodeManagementService_->componentName("NodeManagementService");		// FIXME: obsolete
		nodeManagementService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionAddNodes::name("AddNodes");
		ServiceTransactionAddReferences::name("AddReferences");
		ServiceTransactionDeleteNodes::name("DeleteNodes");
		ServiceTransactionDeleteReferences::name("DeleteReferences");

		auto serviceTransactionAddNodes = boost::make_shared<ServiceTransactionAddNodes>();
		auto serviceTransactionAddReferences = boost::make_shared<ServiceTransactionAddReferences>();
		auto serviceTransactionDeleteNodes = boost::make_shared<ServiceTransactionDeleteNodes>();
		auto serviceTransactionDeleteReferences = boost::make_shared<ServiceTransactionDeleteReferences>();

		serviceTransactionAddNodes->componentService(&*nodeManagementService_);
		serviceTransactionAddReferences->componentService(&*nodeManagementService_);
		serviceTransactionDeleteNodes->componentService(&*nodeManagementService_);
		serviceTransactionDeleteReferences->componentService(&*nodeManagementService_);

		transactionManager_->registerTransaction(serviceTransactionAddNodes);
		transactionManager_->registerTransaction(serviceTransactionAddReferences);
		transactionManager_->registerTransaction(serviceTransactionDeleteNodes);
		transactionManager_->registerTransaction(serviceTransactionDeleteReferences);
	}

	void
	ServiceManager::initSubscriptionService(void)
	{
		subscriptionService_ = boost::make_shared<SubscriptionService>(
			"SubscriptionServiceServer",
			ioThread_,
			messageBus_
		);
		subscriptionService_->componentName("SubscriptionService");		// FIXME: obsolete
		subscriptionService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCreateSubscription::name("CreateSubscription");
		ServiceTransactionDeleteSubscriptions::name("DeleteSubscription");
		ServiceTransactionModifySubscription::name("ModifySubscription");
		ServiceTransactionPublish::name("Publish");
		ServiceTransactionRepublish::name("Republish");
		ServiceTransactionSetPublishingMode::name("SetPublishingMode");
		ServiceTransactionTransferSubscriptions::name("TransferSubscription");

		auto serviceTransactionCreateSubscription = boost::make_shared<ServiceTransactionCreateSubscription>();
		auto serviceTransactionDeleteSubscriptions = boost::make_shared<ServiceTransactionDeleteSubscriptions>();
		auto serviceTransactionModifySubscription = boost::make_shared<ServiceTransactionModifySubscription>();
		auto serviceTransactionPublish = boost::make_shared<ServiceTransactionPublish>();
		auto serviceTransactionRepublish = boost::make_shared<ServiceTransactionRepublish>();
		auto serviceTransactionSetPublishingMode = boost::make_shared<ServiceTransactionSetPublishingMode>();
		auto serviceTransactionTransferSubscriptions = boost::make_shared<ServiceTransactionTransferSubscriptions>();

		serviceTransactionCreateSubscription->componentService(&*subscriptionService_);
		serviceTransactionDeleteSubscriptions->componentService(&*subscriptionService_);
		serviceTransactionModifySubscription->componentService(&*subscriptionService_);
		serviceTransactionPublish->componentService(&*subscriptionService_);
		serviceTransactionRepublish->componentService(&*subscriptionService_);
		serviceTransactionSetPublishingMode->componentService(&*subscriptionService_);
		serviceTransactionTransferSubscriptions->componentService(&*subscriptionService_);

		transactionManager_->registerTransaction(serviceTransactionCreateSubscription);
		transactionManager_->registerTransaction(serviceTransactionDeleteSubscriptions);
		transactionManager_->registerTransaction(serviceTransactionModifySubscription);
		transactionManager_->registerTransaction(serviceTransactionPublish);
		transactionManager_->registerTransaction(serviceTransactionRepublish);
		transactionManager_->registerTransaction(serviceTransactionSetPublishingMode);
		transactionManager_->registerTransaction(serviceTransactionTransferSubscriptions);
	}

	void
	ServiceManager::initMonitoredItemService(void)
	{
		monitoredItemService_ = boost::make_shared<MonitoredItemService>(
			"MonitoredItemServiceServer",
			ioThread_,
			messageBus_
		);
		monitoredItemService_->componentName("MonitoredItemService");		// FIXME: obsolete
		monitoredItemService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCreateMonitoredItems::name("CreateMonitorItems");
		ServiceTransactionDeleteMonitoredItems::name("DeleteMonitorItems");
		ServiceTransactionModifyMonitoredItems::name("ModifyMonitorItems");
		ServiceTransactionSetMonitoringMode::name("SetMonitoringMode");
		ServiceTransactionSetTriggering::name("SetTriggering");

		auto serviceTransactionCreateMonitoredItems = boost::make_shared<ServiceTransactionCreateMonitoredItems>();
		auto serviceTransactionDeleteMonitoredItems = boost::make_shared<ServiceTransactionDeleteMonitoredItems>();
		auto serviceTransactionModifyMonitoredItems = boost::make_shared<ServiceTransactionModifyMonitoredItems>();
		auto serviceTransactionSetMonitoringMode = boost::make_shared<ServiceTransactionSetMonitoringMode>();
		auto serviceTransactionSetTriggering = boost::make_shared<ServiceTransactionSetTriggering>();

		serviceTransactionCreateMonitoredItems->componentService(&*subscriptionService_);
		serviceTransactionDeleteMonitoredItems->componentService(&*subscriptionService_);
		serviceTransactionModifyMonitoredItems->componentService(&*subscriptionService_);
		serviceTransactionSetMonitoringMode->componentService(&*subscriptionService_);
		serviceTransactionSetTriggering->componentService(&*subscriptionService_);

		transactionManager_->registerTransaction(serviceTransactionCreateMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionDeleteMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionModifyMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionSetMonitoringMode);
		transactionManager_->registerTransaction(serviceTransactionSetTriggering);
	}

	void
	ServiceManager::initViewService(void)
	{
		viewService_ = boost::make_shared<ViewService>(
			"ViewServiceServer",
			ioThread_,
			messageBus_
		);
		viewService_->componentName("ViewService");		// FIXME: obsolete
		viewService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionBrowse::name("Browse");
		ServiceTransactionBrowseNext::name("BrowseNext");
		ServiceTransactionTranslateBrowsePathsToNodeIds::name("TranslateBrowsePathsToNodeIds");
		ServiceTransactionRegisterNodes::name("RegisterNodes");
		ServiceTransactionUnregisterNodes::name("UnregisterNodes");

		ServiceTransactionBrowse::SPtr serviceTransactionBrowse = boost::make_shared<ServiceTransactionBrowse>();
		ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext = boost::make_shared<ServiceTransactionBrowseNext>();
		ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds = boost::make_shared<ServiceTransactionTranslateBrowsePathsToNodeIds>();
		ServiceTransactionRegisterNodes::SPtr serviceTransactionRegisterNodes = boost::make_shared<ServiceTransactionRegisterNodes>();
		ServiceTransactionUnregisterNodes::SPtr serviceTransactionUnregisterNodes = boost::make_shared<ServiceTransactionUnregisterNodes>();

		serviceTransactionBrowse->componentService(&*viewService_);
		serviceTransactionBrowseNext->componentService(&*viewService_);
		serviceTransactionTranslateBrowsePathsToNodeIds->componentService(&*viewService_);
		serviceTransactionRegisterNodes->componentService(&*viewService_);
		serviceTransactionUnregisterNodes->componentService(&*viewService_);

		transactionManager_->registerTransaction(serviceTransactionBrowse);
		transactionManager_->registerTransaction(serviceTransactionBrowseNext);
		transactionManager_->registerTransaction(serviceTransactionTranslateBrowsePathsToNodeIds);
		transactionManager_->registerTransaction(serviceTransactionRegisterNodes);
		transactionManager_->registerTransaction(serviceTransactionUnregisterNodes);
	}

	void
	ServiceManager::initQueryService(void)
	{
		queryService_ = boost::make_shared<QueryService>(
			"QueryServiceServer",
			ioThread_,
			messageBus_
		);
		queryService_->componentName("QueryService");		// FIXME: obsolete
		queryService_->forwardGlobalSync(forwardGlobalSync_);
	}

	bool
	ServiceManager::init(SessionManager& sessionManager)
	{
		initAttributeService();
		initMethodService();
		initNodeManagementService();
		initSubscriptionService();
		initMonitoredItemService();
		initViewService();
		initQueryService();

		//
		// discovery service service
		//
		ServiceTransactionRegisterServer::name("RegisterServer");

		ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer = boost::make_shared<ServiceTransactionRegisterServer>();

		serviceTransactionRegisterServer->componentService(&*discoveryService_);

		transactionManager_->registerTransaction(serviceTransactionRegisterServer);

		//
		// application service
		//
		ServiceTransactionRegisterForwardNode::name("RegisterForwardNode");
		ServiceTransactionRegisterForwardMethod::name("RegisterForwardMethod");
		ServiceTransactionRegisterForwardGlobal::name("RegisterForwardGlobal");

		ServiceTransactionRegisterForwardNode::SPtr serviceTransactionRegisterForwardNode = boost::make_shared<ServiceTransactionRegisterForwardNode>();
		ServiceTransactionRegisterForwardMethod::SPtr serviceTransactionRegisterForwardMethod = boost::make_shared<ServiceTransactionRegisterForwardMethod>();
		ServiceTransactionRegisterForwardGlobal::SPtr serviceTransactionRegisterForwardGlobal = boost::make_shared<ServiceTransactionRegisterForwardGlobal>();

		serviceTransactionRegisterForwardNode->componentService(&*applicationService_);
		serviceTransactionRegisterForwardMethod->componentService(&*applicationService_);
		serviceTransactionRegisterForwardGlobal->componentService(&*applicationService_);

		transactionManager_->registerTransaction(serviceTransactionRegisterForwardNode);
		transactionManager_->registerTransaction(serviceTransactionRegisterForwardMethod);
		transactionManager_->registerTransaction(serviceTransactionRegisterForwardGlobal);
	
		sessionManager.discoveryService(discoveryService_);
		sessionManager.transactionManager(transactionManager_);
		sessionManager.forwardGlobalSync(forwardGlobalSync_);
		return true;
	}

	bool 
	ServiceManager::informationModel(InformationModel::SPtr informationModel)
	{
		attributeService_->informationModel(informationModel);
		methodService_->informationModel(informationModel);
		monitoredItemService_->informationModel(informationModel);
		nodeManagementService_->informationModel(informationModel);
		queryService_->informationModel(informationModel);
		subscriptionService_->informationModel(informationModel);
		viewService_->informationModel(informationModel);
		applicationService_->informationModel(informationModel);
		discoveryService_->informationModel(informationModel);
		return true;
	}

	bool 
	ServiceManager::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;

		// FIXME: use IOThread in services...
		applicationService_->ioThread(ioThread.get());
		discoveryService_->ioThread(ioThread.get());
		return true;
	}

	bool
	ServiceManager::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
		return true;
	}

	bool
	ServiceManager::init(void)
	{
		bool rc = true;
		rc = rc && attributeService_->init();
		rc = rc && methodService_->init();
		rc = rc && monitoredItemService_->init();
		rc = rc && nodeManagementService_->init();
		rc = rc && queryService_->init();
		rc = rc && subscriptionService_->init();
		rc = rc && viewService_->init();
		rc = rc && applicationService_->init();
		rc = rc && discoveryService_->init();
		return rc;
	}

	bool
	ServiceManager::shutdown(void)
	{
		applicationService_->shutdown();
		viewService_->shutdown();
		subscriptionService_->shutdown();
		queryService_->shutdown();
		nodeManagementService_->shutdown();
		monitoredItemService_->shutdown();
		methodService_->shutdown();
		attributeService_->shutdown();
		discoveryService_->shutdown();
		return true;
	}

	ApplicationService::SPtr
	ServiceManager::applicationService(void)
	{
		return applicationService_;
	}

	DiscoveryService::SPtr
	ServiceManager::discoveryService(void)
	{
		return discoveryService_;
	}

}
