#include "internal/world/mapgenerator.h"

#include <algorithm>

namespace Gourd
{
    MapGenerator::MapGenerator(TileManager& tileManager) :
        m_tileManager(tileManager)
    { }

    std::unique_ptr<World> MapGenerator::generateWorld(
        std::vector<LayerMeta> metaLayers)
    {
        std::vector<std::unique_ptr<Layer>> layers;
        layers.reserve(layers.size());

        // Generate layers from metadata.
        std::transform(metaLayers.begin(), metaLayers.end(), layers.begin(),
            [&](const LayerMeta& meta)
            {
                return std::unique_ptr<Layer>(new Layer(
                    meta.name,
                    meta.width,
                    meta.height,
                    std::move(m_tileManager.instances(
                        meta.baseTile, 
                        meta.width*meta.height))));
            }
        );

        // Affect the layers.
        for (auto& layer : layers)
        {
            addTileVeins(layer.get());
        }

        World* world = new World(std::move(layers));

        return std::move(std::unique_ptr<World>(world));
    }

    void MapGenerator::addTileVeins(Layer* layer)
    {

    } 
}