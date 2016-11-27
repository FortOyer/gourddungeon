#ifndef CAPABILITY_H
#define CAPABILITY_H

namespace Gourd
{
    class Capability
    {
    public:
        Capability(bool loreVisible = true) : m_loreVisible(loreVisible) { }

        /**
        * Some capabilities are entirely internal (and while part of an instance
        * behaviour) should not be visible to the end user.
        *
        * @return whether this capability is part of lore visibility.
        *         (Whether users can see this capability description/name by
        *         default.)
        */
        inline bool isLoreVisible() const { return m_loreVisible; }

    private:
        bool m_loreVisible;
    };
}

#endif