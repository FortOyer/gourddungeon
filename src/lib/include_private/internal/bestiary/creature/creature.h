/**
* A `Creature` in the beasiary is the prototype that defines the majority of the
* behaviour of individual `CreatureInstances`. A `Creature` protoype is
* generated from a `CreatureGenerator`. This can be purely random, based on 
* environental factors, or a mixture of traits from the unholy union of two
* other `CreatureInstances`.
*
* @file creature.h
* @author Archibald Neil MacDonald
* @version 0.1 23/11/2016
*/

#ifndef CREATURE_H
#define CREATURE_H

#include "internal/manager/prototype.h"
#include "capabilities/capability.h"
#include "creatureinstance.h"

namespace Gourd
{
    /**
    * A creature's proptype. This defines the properties and components that a
    * `CreatureInstance` uses to define its behaviour and description.
    */
    class Creature : public Prototype
    {
    public:
        enum class Regularity : int
        {
            UNIQUE, // There is only 1 in the whole world.
            RARE, // Not often found.
            COMMON // Seen everywhere.
        };
    public:
        Creature(Creature&) = delete;

        const std::string& name() const;
        const std::string& description() const;

    private:
        Regularity m_regularity;

        /**
        * Capabilities of this species.
        */
        ProtoCapabilities m_creatureCapabilities;
        
        /**
        * Capabilities that may be inhereted by an instance of this type.
        */
        InstanceCapabilities m_allPotentialCapabilities;
    };
}

#endif