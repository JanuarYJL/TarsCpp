﻿/**
 * Tencent is pleased to support the open source community by making Tars available.
 *
 * Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this file except 
 * in compliance with the License. You may obtain a copy of the License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software distributed 
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the 
 * specific language governing permissions and limitations under the License.
 */
#include "util/tc_platform.h"
#include "servant/AdminServant.h"
#include "servant/NotifyObserver.h"
#include "servant/ServantHelper.h"
#include "servant/RemoteNotify.h"
#include "servant/RemoteLogger.h"
#include "servant/Application.h"

namespace tars
{

AdminServant::AdminServant()
{
}

AdminServant::~AdminServant()
{
}

void AdminServant::initialize()
{
}

void AdminServant::destroy()
{
}

void AdminServant::shutdown(CurrentPtr current)
{
	TLOGERROR("[TARS][AdminServant::shutdown] from node" << endl);

    std::thread th([=]{
        _application->terminate();
    });
    th.detach();
}

string AdminServant::notify(const string &command, CurrentPtr current)
{
    RemoteNotify::getInstance()->report("AdminServant::notify:" + command);

    return this->getApplication()->getNotifyObserver()->notify(command, current);
}

tars::Int64 AdminServant::getPid(CurrentPtr current)
{
    return getpid();
}

///////////////////////////////////////////////////////////////////////
}
