/*
 * ASTU - AST Utilities
 * A collection of Utilities for Advanced Software Techniques (AST).
 * 
 * Copyright (c) 2020 Roman Divotkey, Nora Loimayr. All rights reserved.
 */

#pragma once

#include <memory>
#include "ITimeService.h"
#include "UpdateService.h"
#include "EntityService.h"

namespace astu {

    class IteratingEntitySystem 
        : public BaseService
        , public IUpdatable
        , public IEntityListener 
        , private std::enable_shared_from_this<IteratingEntitySystem>        
    {
    public:

        /**
         * Constructor.
         * 
         * @param iterateFamily the family of entities this service is processing
         * @param priority      the priority used to update this service
         */
        IteratingEntitySystem(const EntityFamily & iterateFamily, int priority);

        /**
         * Virtual destructor.
         */
        virtual ~IteratingEntitySystem() {}

    protected:

        /**
         * Returns the slapsed time since the last update.
         * 
         * @return the delta time in seconds
         */
        double GetDeltaTime() const {
            return timeService->GetElapsedTime();
        }

        /**
         * Called by this base class for processed entities.
         * 
         * @param entity    the current entity to process
         */
        virtual void ProcessEntity(Entity & e) = 0;

        // Inherited via Base Service
        virtual void OnStartup() override;
        virtual void OnShutdown() override;

        // Inherited via IUpdatable
        virtual void OnUpdate() override;

        // Inherited via IEntityListener
        virtual void OnEntityAdded(std::shared_ptr<Entity> entity) override {};
        virtual void OnEntityRemoved(std::shared_ptr<Entity> entity) override {};

    private:
        /** The updatae priority of this updatable. */
        int updatePriority;

        /** The family of entities this system is processing. */
        EntityFamily    iterateFamily;

        /** The view to the entities to be processed. */
        std::shared_ptr<EntityView> entityView;

        /** The time service used to offer elapsed delta time. */
        std::shared_ptr<ITimeService> timeService;
    };

} // end of namespace