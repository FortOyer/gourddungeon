#ifndef LAYERMETA_H
#define LAYERMETA_H

#include <string>
#include <vector>
#include <memory>

namespace Gourd
{
    class Tile;
    class TileLikeliehood;

    struct LayerMeta
    {
        LayerMeta(std::string name, Tile* baseTile, int width, int height) :
        name(name), baseTile(baseTile), width(width), height(height) { }

        std::string name;
        Tile* baseTile;
        int width;
        int height;
    };
}

#endif