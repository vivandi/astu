/*
 * ASTU - AST Utilities
 * A collection of Utilities for Advanced Software Techniques (AST).
 * 
 * Copyright (c) 2020 Roman Divotkey, Nora Loimayr. All rights reserved.
 */

#include <stdexcept>
#include "Service.h"

namespace astu {

BaseService::BaseService(const std::string & aName)
    : name(aName)
    , running(false)
{
    // Intentionally left empty
}

const std::string & BaseService::GetName() const
{
    return name;
}

void BaseService::Startup()
{
    if (IsRunning()) {
        throw std::logic_error("Service " + GetName() + " already running");
    }
    OnStartup();
    running = true;
}

void BaseService::Shutdown()
{
    // Best practice: ignore shut down calls on not-running services.
    if (IsRunning()) {
        OnShutdown();        
        running = false;
    }
}

bool BaseService::IsRunning() const
{
    return running;
}


} // end of namespace