#ifndef __InputManager_H__
#define __InputManager_H__

#define INCLUDE_SDL
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#include "SDL_include.h"

class InputManager{
    private:
        bool mouseState[6];
        int mouseUpdate[6];

        bool keyState[416];
        int keyUpdate[416];

        bool quitRequested;
        uint32_t updateCounter;

        int mouseX;
        int mouseY;

    public:
        void Update();
        
        bool KeyPress(int key);
        bool KeyRelease(int key);
        bool IsKeyDown(int key);

        bool MousePress(int button);
        bool MouseRelease(int button);
        bool IsMouseDown(int button);

        int GetMouseX();
        int GetMouseY();

        bool QuitRequested();

        static InputManager &GetInstance();

        InputManager();
        ~InputManager();
};

#endif