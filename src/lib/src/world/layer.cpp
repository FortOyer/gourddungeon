#include "internal/world/layer.h"

#include <stdexcept>

namespace Gourd
{
    Layer::Layer(const std::string& name, int width, int height,
        std::vector<std::unique_ptr<TileInstance>>&& tiles):
        m_tileMap(std::move(tiles)),
        m_width(width),
        m_height(height),
        m_name(name)
    { 

    }

    TileInstance* Layer::at(int x, int y) const 
    { 
        if (x > m_width  || x < 0 || 
            y > m_height || y < 0) 
        {
            throw std::out_of_range("Tile index out of range.");
        }
        return m_tileMap[m_height*y + x].get(); 
    }

}