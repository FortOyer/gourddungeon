#include "internal/bestiary/populationcontrol.h"

#include <algorithm>

#include "internal/bestiary/creature/creature.h"

namespace Gourd 
{
    CreatureInstance PopulationControl::instance(const Creature* prototype)
    {
        incrementPop(prototype);
        return CreatureInstance(*prototype);
    }

    int PopulationControl::getTotalPops() const
    {
        return std::accumulate(
            m_popCount.cbegin(),
            m_popCount.cend(),
            0,
            [](int a, const std::pair<const Creature*, int>& b) 
            { 
                return a + b.second;
            });
    }

    int PopulationControl::getTotalPops(const Creature* prototype) const
    {
        // N.B: If prototype does not exist in map then this will throw.
        return m_popCount.at(prototype);
    }

    void PopulationControl::incrementPop(const Creature* prototype, int count)
    {
        auto result = m_popCount.insert(std::make_pair(prototype, count));
        if (!result.second)
        {
             // A pop count already exists. Append to this.
            result.first->second += count;
        }
    }
}