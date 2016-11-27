#ifndef TILELIKELIEHOOD_H
#define TILELIKELIEHOOD_H

#include "tile.h"

#include <vector>

namespace Gourd
{
    struct TileLikeliehood
    {
        Tile* m_prototype;
        std::vector<Tile*> replaces;
    };
}

#endif