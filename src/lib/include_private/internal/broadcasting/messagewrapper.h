/**
* Messagewrapper is a simple class designed to handle ownership of the message,
* and track who initially sent the message.
*
* @file messagewrapper.h
* @author Archibald Neil MacDonald
* @version 0.1 27/11/2016
*/
#ifndef MESSAGEWRAPPER_H
#define MESSAGEWRAPPER_H

namespace Gourd
{
    // Forward declarations.
    template <typename> class Listener;

    /**
    * MessageWrapper is used to faciliate the ownership of messages, and track
    * who sent the initial message. This is motivated by ensuring message
    * recursion does not happen by the sender recieving its own message again.
    *
    * @tparam T the type of message this wrapper is allowed to own.
    */
    template<typename T>
    class MessageWrapper
    {
    public:
        /**
        * Constructor.
        *
        * @param message message to hold and own.
        * @param sender sender of message this takes responsibility for.
        */
        MessageWrapper(const T* message, const Listener<T>* sender) : 
            m_sender(sender), 
            m_message(message) { }
        
        // (No copy constructor allowed. Messages must be unique.)
        MessageWrapper(const MessageWrapper&) = delete;

        /**
        * Move constructor.
        * @param other Transfers message ownership from other. Other left with 
        *        nullptr.
        */
        MessageWrapper(MessageWrapper&& other)
        {
            m_sender = other.m_sender;
            
            m_message = other.m_message;
            other.m_message = nullptr;
        }

        /**
        * Destructor. Destroy's message.
        */
        ~MessageWrapper() { delete m_message; }

        /**
        * @return get the message instance.
        */
        inline const T* getMessage() const { return m_message; }

        /**
        * @return get the message's sender.
        */
        inline const Listener<T>* getSender() const { return m_sender; }

    private:
        const T* m_message;
        const Listener<T>* m_sender;
    };
}


#endif