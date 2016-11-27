/**
* Listeners are the endpoints of the message passing system. They define how a
* message is sent on the system, as well as how a message is processed when
* recieved by this listener.
*
* @file listener.h
* @author Archibald Neil MacDonald
* @version 0.1 26/11/2016
*/

#ifndef LISTENER_H
#define LISTENER_H

#include <memory>
#include <functional>

#include "channel.h"
#include "messagewrapper.h"

namespace Gourd
{
    /**
    * A Listener subscribes to a predefined `channel`, and defines a callback
    * for when the channel passes a messages to be handled. The listener also
    * adds messages onto its channel. Consider a listner as a channel endpoint,
    * where there is 1 channel with potentially many listener endpoints.
    */
    template <typename T>
    class Listener
    {
    public:

        /**
        * Constructor.
        *
        * @param channel pointer to channel that messages will be recieved/sent
        *        from by this listener.
        * @param callback the callback function that is triggered when this
        *        listener recieves a message instance of type `T`.
        * @param recusrive when true signals fired by this listener endpoint
        *        will also be recieved by this listener endpoint.
        */
        Listener(std::shared_ptr<Channel<T>> channel,
                 const std::function<void (const T*)>& callback,
                 bool recursive = false):
            m_channel(channel),
            m_callback(callback),
            m_recursive(recursive)
        {
            m_channel.get()->m_listeners.push_front(this);
        }

        /**
        * Destructor. Removes this listener from the `channel`s list of attached
        * channels.
        */
        ~Listener()
        {
            m_channel.get()->m_listeners.remove(this);
        }

        /**
        * @return true if this listener allows for signals it sends to be caught
        *         by itself. Defaults to false.
        */
        inline bool isRecursive() const { return m_recursive; }

        /**
        * Calls the callback `callback` passing the message to the callback.
        * This is intended to be called by the `channel` and/or `broadcaster.`
        */
        inline void processMessage(const T* message)
        {
            m_callback(message);
        }

        /*
        * Adds a new message to the message queue of the bound channel. 
        *
        * @param message the message to add onto the attached channel queue.
        *        This takes ownership of the pointer.
        */
        inline void pushMessage(const T* message)
        {
            m_channel.get()->pushMessage(
                std::unique_ptr<MessageWrapper<T>>(
                    new MessageWrapper<T>(message, this)));
        }

    private:
        std::shared_ptr<Channel<T>> m_channel;
        std::function<void (const T*)> m_callback;
        bool m_recursive;
    };
}

#endif