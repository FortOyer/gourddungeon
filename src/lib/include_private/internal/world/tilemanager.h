#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <vector>
#include <unordered_set>
#include <memory>

#include "internal/manager/prototypemanager.h"
#include "tile.h"
#include "tileinstance.h"
#include "tilelikeliehood.h"
#include "layermeta.h"

namespace Gourd
{  
    class TileManager  : public PrototypeManager
    {
    public:
        using Likeliehoods = std::vector<std::unique_ptr<TileLikeliehood>>;
    
        inline Likeliehoods& getLikeLiehoods() { return m_likeLiehoods; }

        std::unique_ptr<TileInstance> instance(Tile* tile);

        std::vector<std::unique_ptr<TileInstance>> instances(Tile* tile,
                                                             int count);

    private:
        Likeliehoods m_likeLiehoods;
        std::unordered_set<std::unique_ptr<Tile>> m_tiles;

    };

}

#endif