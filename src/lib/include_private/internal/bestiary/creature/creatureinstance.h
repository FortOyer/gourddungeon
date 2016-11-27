/**
* The CreatureInstance is an in game-creature, that interacts with the gameworld
* and other instances.
*
* @file creatureinstance.h
* @author Archibald Neil MacDonald
* @version 0.1 24/11/2016
*/

#ifndef CREATUREINSTANCE_H
#define CREATUREINSTANCE_H

#include <memory.h>

#include "internal/manager/instance.h"
#include "capabilities/capability.h"

namespace Gourd
{
    class Creature;

    /**
    * A CreatureInstance is a defined in-game interactable entity. Its entire
    * look / feel / nature is defined by the creature prototype (genome), 
    * but individual instances can differentiate from one another depending
    * on the variability of the instance-specific capabilities they may inheret
    * from the genome.
    */
    class CreatureInstance : public Instance
    {
    public:
        CreatureInstance(const Creature& prototype);
    private:
        const Creature& m_prototype;
        InstanceCapabilities m_capabilities;
    };
}

#endif