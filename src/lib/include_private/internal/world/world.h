#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>

#include "layer.h"

namespace Gourd
{
    class World
    {
    public:
        World(std::vector<std::unique_ptr<Layer>>&& layers);

    private:
        std::vector<std::unique_ptr<Layer>> m_layers;
    };
}

#endif