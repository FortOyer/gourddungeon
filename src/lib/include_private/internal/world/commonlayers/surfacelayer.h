/**
* SurfaceLayer is a hard-coded common layer that includes surface entities
* and surface-like structures.
*
* @file surfacelayer.h
* @author Archibald Neil MacDonald
* @version 0.1 24/11/2016
*/

#ifndef SURFACELAYER_H
#define SURFACELAYER_H

#include "internal/world/layer.h"

namespace Gourd
{
    /**
    * Surfacelayer is the most interesting layer as it contains the surface 
    * world. This includes, trees, grass, villages, rivers.
    */
    class SurfaceLayer : public Layer
    {

    };
}

#endif