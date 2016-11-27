#ifndef LAYER_H
#define LAYER_H

#include <memory>
#include <vector>
#include <string>

#include "tileinstance.h"

namespace Gourd
{
    class Layer 
    {
    public:
        Layer(const std::string& name, int width, int height,
              std::vector<std::unique_ptr<TileInstance>>&& m_tileMap);

        Layer(const Layer&) = delete;

        TileInstance* at(int x, int y) const;

        std::vector<std::unique_ptr<TileInstance>> m_tileMap;
        const int m_width;
        const int m_height;
        std::string m_name;
    };
}

#endif