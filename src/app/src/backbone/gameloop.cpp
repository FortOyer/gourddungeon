#include "gameloop.h"

#include <SDL2/SDL.h>

void GameLoop::execute()
{
    while (false == iterate()) { }
}

bool GameLoop::iterate()
{
    bool exit = false;

    SDL_Event event;
    while (1 == SDL_PollEvent(&event)) // Do while event is queued.
    {
        switch(event.type)
        {
            // Audio Events
            case SDL_AUDIODEVICEADDED: break;
            case SDL_AUDIODEVICEREMOVED: break;

            // Controller Axis
            case SDL_CONTROLLERAXISMOTION: break;
            
            // Controller Buttons
            case SDL_CONTROLLERBUTTONDOWN: break;
            case SDL_CONTROLLERBUTTONUP: break;

            // // Controller Devices
            case SDL_CONTROLLERDEVICEADDED: break;
            case SDL_CONTROLLERDEVICEREMOVED: break;
            case SDL_CONTROLLERDEVICEREMAPPED: break;

            // Dollar Gesture
            case SDL_DOLLARGESTURE: break;
            case SDL_DOLLARRECORD: break;

            // Drop Events
            case SDL_DROPFILE: break;
            case SDL_DROPTEXT: break;
            case SDL_DROPBEGIN: break;
            case SDL_DROPCOMPLETE: break;

            case SDL_FINGERMOTION: break;
            case SDL_FINGERDOWN: break;
            case SDL_FINGERUP: break;

            case SDL_KEYDOWN: break;
            case SDL_KEYUP: break;

            case SDL_JOYAXISMOTION: break;

            case SDL_JOYBALLMOTION: break;

            case SDL_JOYHATMOTION: break;

            case SDL_JOYBUTTONDOWN: break;
            case SDL_JOYBUTTONUP: break;

            case SDL_JOYDEVICEADDED: break;
            case SDL_JOYDEVICEREMOVED: break;

            case SDL_MOUSEMOTION: break;

            case SDL_MOUSEBUTTONDOWN: break;
            case SDL_MOUSEBUTTONUP: break;

            case SDL_MOUSEWHEEL: break;

            case SDL_MULTIGESTURE: break;

            case SDL_QUIT:
            { 
                exit = true; 
                break;
            }

            case SDL_SYSWMEVENT: break;

            case SDL_TEXTEDITING: break;

            case SDL_TEXTINPUT: break;

            case SDL_USEREVENT: break;

            case SDL_WINDOWEVENT: break;

            // Common Event
            default: break;
        }
        return exit;
    }
}