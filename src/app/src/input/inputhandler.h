#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <memory>
#include "command.h"

class InputHandler 
{
    std::unique_ptr<Command> m_panLeft;
    std::unique_ptr<Command> m_panRight;
    std::unique_ptr<Command> m_panUp;
    std::unique_ptr<Command> m_panDown;
};

#endif