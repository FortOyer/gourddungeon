#include <catch.hpp>

#include "internal/world/tilemanager.h"
#include "internal/world/layermeta.h"
#include "internal/world/mapgenerator.h"
#include "internal/world/tile.h"

TEST_CASE("World generation", "[worldbuilding]")
{
    Gourd::Tile* tile = new Gourd::Tile;

    Gourd::TileManager manager;

    Gourd::MapGenerator mapGen(manager);
    auto world = mapGen.generateWorld({
        Gourd::LayerMeta("Terrestrial", tile, 100, 100),
        Gourd::LayerMeta("Sublayer", tile, 100, 100)
    });
}