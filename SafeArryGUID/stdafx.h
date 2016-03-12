// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

// Import .NET framework mscorlib.
#import "mscorlib.tlb" raw_interfaces_only
//using namespace mscorlib;
typedef mscorlib::_TypePtr _TypePtr;
typedef mscorlib::Guid Guid;

// Import adapter related libs.
#import "DeviceConfig.tlb" named_guids
#import "AdaptorFactory.tlb" named_guids
//#import "VideoAdaptorWrapper.tlb" named_guids
//#import "ECConnectionManager.tlb" named_guids
//using namespace DeviceConfig;
//using namespace AdaptorFactory;
//using namespace VideoAdaptorWrapper;
//using namespace ECConnectionManager;
//
//// Import web-service synchronize related libs.
//#import "HUSCommunicationMsgBase.tlb" named_guids no_namespace
//#import "SiteImage.tlb" named_guids
//#import "SiteImageAdaptor.tlb" named_guids
//#import "SynchronizeClient.tlb" named_guids
//
//using namespace SiteImage;
//using namespace SiteImageAdaptor;
//using namespace SynchronizeClient;
//
//#import "HUS.DataManager.Search.tlb" named_guids
//#import "HUS.DataManager.Client.Contract.tlb" named_guids
//#import "HUS.DataManager.Search.Contract.tlb" named_guids
//
//using namespace HUS_DataManager_Search;
//using namespace HUS_DataManager_Client_Contract;
//using namespace HUS_DataManager_Search_Contract;