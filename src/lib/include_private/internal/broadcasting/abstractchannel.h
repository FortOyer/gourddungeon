/**
* AbstractChannel defines the base functions required by `broadcaster` to
* process channel actions. 
* `Channel` is the typical channel instance which defines the message type that
* a channel can process.
*
* @file abstractchannel.h
* @author Archibald Neil MacDonald
* @version 0.1 26/11/2016
*/

#ifndef ABSTRACTCHANNEL_H
#define ABSTRACTCHANNEL_H

#include <string>

namespace Gourd
{
    /**
    * Base class used for defining a common interface as required by the
    * broadcaster class to process messages through channels.
    */
    class AbstractChannel 
    { 
    public:
        /**
        * Constructor.
        *
        * @param name the name of this channel, used for lookup and storage of
        *        the channel instance inside the `broadcaster.`
        */
        AbstractChannel(const std::string& name) : m_name(name) { }
        
        /**
        * Destructor.
        */
        virtual ~AbstractChannel() = default;

        /**
        * Processes a message, sending the message down through all attached
        * listeners.
        *
        * @return true if there are messages still to process. False otherwise.
        */
        virtual bool processFrontMessage() = 0;
        
        /**
        * @return the name of this channel.
        */
        inline const std::string& getName() const { return m_name; }

    private:
        const std::string m_name;
    };
}

#endif