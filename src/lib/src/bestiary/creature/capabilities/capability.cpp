#include "internal/bestiary/creature/capabilities/capability.h"

namespace Gourd
{
    CapabilityChance::CapabilityChance(
        float w, std::shared_ptr<const Capability> c) :
        m_weighting(w), m_capability(c) 
    { }
}