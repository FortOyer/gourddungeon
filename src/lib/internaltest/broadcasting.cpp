#include <catch.hpp>

#include "internal/broadcasting/broadcaster.h"
#include "internal/broadcasting/listener.h"

class Message 
{
public:
    Message();
    Message(const std::string& message) : m_message(message) { }

    const std::string& getMessage() const { return m_message; }

private:
    std::string m_message;
};

TEST_CASE("Single Instance Broadcaster with Recursion", "[broadcasting]") 
{
    bool messageProcessed = false;

    auto m = std::shared_ptr<Gourd::Channel<Message>>(
        new Gourd::Channel<Message>("Basic"));

    Gourd::Broadcaster broadcast;
    broadcast.addChannel(m);

    Gourd::Listener<Message> listener(
        m, 
        [&](const Message* message)
        {
            INFO("Call: " << message->getMessage());
            if (message->getMessage() == "Hello World!")
            {
                messageProcessed = true;
            }
        },
        true // recursive
    );

    SECTION("Processing a single message.") 
    {
        REQUIRE(m.get()->getMessageCount() == 0);

        listener.pushMessage(new Message("Hello World!"));
        
        REQUIRE(m.get()->getMessageCount() == 1);
        
        bool remaining = broadcast.processMessages();
        
        REQUIRE(remaining == false);
        REQUIRE(m.get()->getMessageCount() == 0);
        REQUIRE(messageProcessed == true);
    }

    SECTION("Processing multiple messages.")
    {
        REQUIRE(m.get()->getMessageCount() == 0);

        listener.pushMessage(new Message(""));
        listener.pushMessage(new Message(""));
        listener.pushMessage(new Message(""));

        REQUIRE(m.get()->getMessageCount() == 3);

        REQUIRE(true == broadcast.processMessages());
        REQUIRE(true == broadcast.processMessages());
        REQUIRE(false == broadcast.processMessages());
        REQUIRE(false == broadcast.processMessages());

        REQUIRE(m.get()->getMessageCount() == 0);
    }
}

TEST_CASE("Single Instance Broadcaster with no Recursion", "[broadcasting]")
{
    auto m = std::shared_ptr<Gourd::Channel<Message>>(
        new Gourd::Channel<Message>("Basic"));

    Gourd::Broadcaster broadcast;
    broadcast.addChannel(m);

    bool messageProcessed = false;
    Gourd::Listener<Message> listener(
        m, 
        [&](const Message* message)
        {
            WARN("Call: " << message->getMessage());
            if (message->getMessage() == "Hello World!")
            {
                messageProcessed = true;
            }
        }
    );

    SECTION("Processing a single message.") 
    {
        REQUIRE(m.get()->getMessageCount() == 0);

        listener.pushMessage(new Message("Hello World!"));
        
        REQUIRE(m.get()->getMessageCount() == 1);
        
        bool remaining = broadcast.processMessages();
        
        REQUIRE(remaining == false);
        REQUIRE(m.get()->getMessageCount() == 0);
        REQUIRE(messageProcessed == false);
    }
}

TEST_CASE("Multi-listener Broadcasters", "[broadcasting]")
{
    auto m = std::shared_ptr<Gourd::Channel<Message>>(
        new Gourd::Channel<Message>("Basic"));

    Gourd::Broadcaster broadcast;
    broadcast.addChannel(m);

    bool test = false;
    
    Gourd::Listener<Message> listener(
        m, 
        [&](const Message* message)
        {
            INFO("Call: " << message->getMessage());
            if (message->getMessage() == "Incomming2!")
            {
                REQUIRE(1 == m.get()->getMessageCount());
                listener.pushMessage(new Message("Incomming3!"));
                REQUIRE(2 == m.get()->getMessageCount());
            }
        }
    );

    Gourd::Listener<Message> secondListener(
        m, 
        [&](const Message* message)
        {
            INFO("Call: " << message->getMessage());
            if (message->getMessage() == "Incomming!")
            {
                REQUIRE(1 == m.get()->getMessageCount());
                secondListener.pushMessage(new Message("Incomming2!"));
                REQUIRE(2 == m.get()->getMessageCount());
            }
            else if (message->getMessage() == "Incomming3!")
            {
                REQUIRE(1 == m.get()->getMessageCount());
                test = true;
            }
        }
    );

    listener.pushMessage(new Message("Incomming!"));
    REQUIRE(test == false);
    int count = 0;
    while (broadcast.processMessages()) { ++count; }
    REQUIRE(test == true);
    REQUIRE(count == 2);
}
