#include "internal/bestiary/creature/creatureinstance.h"

#include "internal/bestiary/creature/creature.h"

namespace Gourd
{
    CreatureInstance::CreatureInstance(const Creature& prototype) :
        m_prototype(prototype)
    {

    }
}