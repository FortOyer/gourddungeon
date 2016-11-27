/*
* Defines the creature generator which deals with creating new balanced and 
* interesting species within the dungeon.
*
* @file creaturegenerator.h
* @author Archibald Neil MacDonald
* @version 0.1 23/11/2016
*/

#ifndef CREATUREGENERATOR_H
#define CREATUREGENERATOR_H

#include "internal/manager/prototypemanager.h"
#include "creature.h"

namespace Gourd
{
    /**
    * CreatureGenerator deals with creature prototype generation. It does this
    * by randomly selecting weighted properties from properties lists and 
    * creating a new creature based on these properties plus any additional
    * narrative and visual information.
    * Creatures can also be created by splicing the capability and narrative
    * lists of two parent creatures.
    */
    class CreatureGenerator : public PrototypeManager
    {
    public:
        std::unique_ptr<Creature> generateCreature(const Creature& parentA,
                                  const Creature& parentB) const;
        
        std::unique_ptr<Creature> generateCreature() const;
    private:

    };
}

#endif