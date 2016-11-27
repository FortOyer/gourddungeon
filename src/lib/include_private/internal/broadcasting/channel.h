/**
* Channels are the sinews of the message passing and processing. 
* Channels have a simple interface of collecting `listener` endpoints. Whenever
* a message is added to the queue then that message is passed to all endpoints.
*
* @file channel.h
* @author Archibald Neil MacDonald
* @version 0.1 26/11/2016
*/

#ifndef CHANNEL_H
#define CHANNEL_H

#include <queue>
#include <forward_list>
#include <memory>

#include "abstractchannel.h"
#include "messagewrapper.h"

namespace Gourd
{
    // Forward declaration
    template <typename T> class Listener;

    /**
    * Channel class. Takes a collection of listener endpoints and takes messages
    * from the listeners and sends messages back to the listeners.
    *
    * @tparam T the message class this channel and listener endpoints will
    *         handle.
    */
    template<typename T>
    class Channel : public AbstractChannel
    {
        friend class Listener<T>;
    public: 
        /**
        * Constructor.
        *
        * @param name the name of this channel, used for lookup and storage of
        *        the channel instance inside the `broadcaster.`
        */
        Channel(const std::string& name) : AbstractChannel(name) { }

        /**
        * Destructor.
        */
        virtual ~Channel() = default;

        /**
        * @return the number of messages in this channel's message queue.
        */
        std::size_t getMessageCount() const { return m_messages.size(); }

        /**
        * Processes a message, sending the message down through all attached
        * listeners.
        *
        * @return true if there are messages still to process. False otherwise.
        */
        bool processFrontMessage() override
        {
            if (m_messages.size() > 0) // Process messages if they exist.
            {
                const auto& message = m_messages.front();
                for (auto listener: m_listeners)
                {
                    // All listeners get message, excluding the original sender.
                    // The original sender will recieve its message if it is
                    // set to recurisve.
                    if (listener->isRecursive() || 
                        message.get()->getSender() != listener)
                    {
                        listener->processMessage(message.get()->getMessage());
                    }
                }
                m_messages.pop();
            }
             // Return true if there are messages remaining.
             // N.B: Messages can be added to the queue from processed listener
             // callbacks.
            return m_messages.size() > 0;
        }

    private:
        /**
        *Adds a new message to the message queue. This is expected to be called
        * via the `Listener` friend class.
        *
        * @param message message to be added to the queue. Ownership of the
        *        pointer is taken by this instance.
        */
        inline void pushMessage(std::unique_ptr<MessageWrapper<T>>&& message) 
        { 
            m_messages.push(std::move(message)); 
        }

    private:
        std::queue<std::unique_ptr<MessageWrapper<T>>> m_messages;
        std::forward_list<Listener<T>*> m_listeners; // List of all listeners.
    };
}

#endif