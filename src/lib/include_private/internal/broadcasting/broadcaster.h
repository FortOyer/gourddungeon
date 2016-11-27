/**
* Broadcasters are the heart of message passing and processing. 
*
* Broadcasters collect channels which are the links between `Listeners` and 
* will process them in batches.
*
* @file broadcaster.h
* @author Archibald Neil MacDonald
* @version 0.1 26/11/2016
*/

#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <memory>
#include <unordered_map>

#include "channel.h"

namespace Gourd
{
    /**
    * Manages a collection of channels and is the heartbeat that processes
    * all of them. Channels are added to the Broadcaster, but the broadcaster
    * does not own them. It will check for valid channels and process these.
    */
    class Broadcaster
    {
    public:
        /**
        * Processes all added channels. Channels are guaranteed to process their
        * messages in the order the messages were added to the queue of that
        * channel. Channels themselves are *not* guaranteed to be processed in
        * any order, and messages should be processed with this in mind.
        *
        * All (valid) channels release their messages down across all attached
        * listeners for processing.
        * 
        * @return true if any one channel still has messages in its queue.
        *         false if all attached channels have empty message queues.
        */
        bool processMessages();

        /**
        * Gets the channel with name `name.` Throws if channel does not exist.
        * The pointer can have expired if all listeners to the channel outside 
        * of the broadcaster have been lost.
        * @param name `name` of channel to retrieve.
        * @return shared_ptr to existing channel. May be null if channel has
        *         expired.
        */
        std::shared_ptr<AbstractChannel> getChannel(
            const std::string& name) const;

        /**
        * Gets the number of channels owned by this broadcaster.
        * @return total number of channels.
        */
        inline std::size_t totalChannels() const { return m_channels.size(); }

        /**
        * Adds a new channel to broacaster with key `channel.getName()`. If a
        * channel with `name` already exists then this function will replace it,
        * and return the old channel.
        *
        * Internally the broadcaster only stores weak_ptrs to channels,
        * so `channel` only exist for as long as there are listeners to use it.
        *
        * @param channel Channel to add to this broadcaster for processing.
        * @return `channel` if `channel` has a unique name. Otherwise will
        *         return the pointer that `channel` has now replaced in the
        *         `broadcaster`. If the old channel has expired this value
        *         will be null. 
        */
        std::shared_ptr<AbstractChannel>  addChannel(
            std::shared_ptr<AbstractChannel> channel);

    private:
        std::unordered_map<std::string,
                           std::weak_ptr<AbstractChannel>> m_channels; 
    };
}

#endif