/**
* Defines the `PopulationControl`. This is used to keep track of world total
* population and  help keep populations on the world map at the correct levels.
*
* @file population.h
* @author Archibald Neil MacDonald
* @version 0.1 22/11/2016
*/

#ifndef POPULATIONCONTROL_H
#define POPULATIONCONTROL_H

#include <unordered_map>

#include "creature/creatureinstance.h"

namespace Gourd
{
    class Creature;

    /**
    * PopulationControl keeps tabs on the world population and will adjust the
    * population levels accordingly to keep them consistent to the control's
    * parameters.
    *
    * The responsibilities of PopulationControl are generating monsters in the
    * world, including hero / unique creature generation available from the
    * `CreatureGenerator` bestiary. This can include gods, heros, demons, as
    * well as common beasts.
    */
    class PopulationControl
    {
    public:
        CreatureInstance instance(const Creature* prototype);

        /**
        * Get the total population count of the entire world.
        * @return population count.
        */
        int getTotalPops() const;

        /**
        * Get the total population count of one species in the entire world.
        * @return population count for species `protoype`.
        */
        int getTotalPops(const Creature* prototype) const;

    private:
        void incrementPop(const Creature* protoype, int count = 1);

    private:
        std::unordered_map<const Creature*, int> m_popCount;
    };
};

#endif