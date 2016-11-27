/**
* Defines a hard-coded human species so we have a common species to most tropey
* high fantasy.
*
* @file human.h
* @author Archibald Neil MacDonald
* @version 0.1 24/11/2016
*/

#ifndef HUMAN_H
#define HUMAN_H

#include "internal/bestiary/creature/creature.h"

namespace Gourd
{
    /**
    * A human is a typical Creature species that is hard-coded with some common
    * properties typical to human's in fantasy. They may typically be the common
    * species for campaigns and hero adventuring to give a narrative grounding.
    * Aside from this there is nothing special about human species which
    * differentaites it from other creatures.
    */
    class Human : public Creature
    {

    };
}

#endif