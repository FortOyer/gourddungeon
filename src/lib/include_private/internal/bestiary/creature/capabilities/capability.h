#ifndef CAPABILITY_H
#define CAPABILITY_H

#include <memory>
#include <forward_list>

#include "internal/manager/capability.h"

namespace Gourd
{
    /**
    * CapabilityChance is a wrapper around a capability and an associated float
    * which describes a weight value describing the likeliness of a 
    * `CreatureInstance` inhereting this capability from the `Creature`
    * prototype. 
    */
    struct CapabilityChance
    {
        CapabilityChance(float w, std::shared_ptr<const Capability> c);

        float m_weighting;
        
        std::shared_ptr<const Capability> m_capability;
    };

    using ProtoCapabilities = std::forward_list<
                                std::shared_ptr<const Capability>>;
                                
    using InstanceCapabilities = std::forward_list<CapabilityChance>;
}

#endif