/*
 * ASTU - AST Utilities
 * A collection of Utilities for Advanced Software Techniques (AST).
 * 
 * Copyright (c) 2020 Roman Divotkey, Nora Loimayr. All rights reserved.
 */

#pragma once

#include <vector>
#include <memory>
#include "Service.h"

namespace astu {

    class IUpdatable {
    public:

        /**
         * Virtual destructor.
         */
        virtual ~IUpdatable() {}

        /**
         * Call when this updatable gets updated.
         */
        virtual void OnUpdate() = 0;

        /**
         * Returns the update priority.
         * Lower priorities get updated before higher priorities.
         * 
         * @return the update priority
         */
        virtual int GetUpdatePriority() const = 0;

    };

    class UpdateService : public BaseService {
    public:

        /**
         * Constructor.
         */
        UpdateService();

        /**
         * Adds an updatable.
         * 
         * @param updatable the updatable to be added
         */        
        void AddUpdatable(std::shared_ptr<IUpdatable> updatable);

        /**
         * Removes an updatable.
         * 
         * @param updatable the updatable to be removed
         */
        void RemoveUpdatable(std::shared_ptr<IUpdatable> updatable);

        /**
         * Tests whether a specific updatablel has already been added.
         * 
         * @param updatable the updatable to be tested
         * @return `true` if the updatale has already beed added
         */
        bool HasUpdatable(std::shared_ptr<IUpdatable> updatable);

        /***
         * Updates all registered updatables.
         */
        void UpdateAll();

    private:
        /** The list of updatables this service is managin. */
        std::vector<std::shared_ptr<IUpdatable>> updatables;
    };

    class UpdatableBaseService 
        : public BaseService
        , public IUpdatable
        , public std::enable_shared_from_this<UpdatableBaseService> 
    {
    public:

        /**
         * Constructor.
         * 
         * @param name      the name of this service
         * @param priority  the update priority of this service
         */
        UpdatableBaseService(const std::string & name = DEFAULT_NAME, int priority = 0);

        // Inherited via BaseService/IService
        virtual void Startup() override;
        virtual void Shutdown() override;

        // Inherited via IUpdatable.
        virtual int GetUpdatePriority() const override;

    private:
        /** The update priority of this updatable. */
        int updatePriority;
    };

} 