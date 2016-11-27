#include "internal/world/world.h"

namespace Gourd
{
    World::World(std::vector<std::unique_ptr<Layer>>&& layers) :
        m_layers(std::move(layers))
    { }
}