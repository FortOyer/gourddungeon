#include "internal/broadcasting/broadcaster.h"

namespace Gourd
{
    std::shared_ptr<AbstractChannel>  Broadcaster::addChannel( 
        std::shared_ptr<AbstractChannel> channel)
    {
        // Create our new channel and add.
        auto result = m_channels.insert(
            std::make_pair(channel.get()->getName(), channel));

        if (result.second)
        {
            // Successful add, return!
            return channel;
        }
        else
        {
            // Already exists. Get existant.
            auto existing = result.first->second;
            result.first->second = channel;
            return existing.lock();
        }
    }

    std::shared_ptr<AbstractChannel> Broadcaster::getChannel(
        const std::string& name) const
    {
        return m_channels.at(name).lock();
    }

    bool Broadcaster::processMessages()
    {
        bool messagesRemaining = false;
        for (auto& channelPtr : m_channels)
        {
            if (!channelPtr.second.expired())
            {
                // Go through channels. Process messages for attached listeners.
                // Check if messages remain in at least one message queue.
                auto channel = channelPtr.second.lock();
                messagesRemaining |= channel.get()->processFrontMessage();
            }
        }
        return messagesRemaining;
    }
}