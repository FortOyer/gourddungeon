#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "tilemanager.h"
#include "world.h"

namespace Gourd
{
    class Layer;

    class MapGenerator
    {
    public:
        MapGenerator(TileManager& tileManager);

        std::unique_ptr<World> generateWorld(std::vector<LayerMeta> layers);
    
    private:
        void addTileVeins(Layer* layer);

    private:
        TileManager& m_tileManager;
    };

}

#endif