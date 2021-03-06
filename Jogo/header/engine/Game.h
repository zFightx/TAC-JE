#ifndef __Game_H__
#define __Game_H__

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include "State.h"

#include <iostream>
using namespace std;

const string name = "Alexandre Souza Costa Oliveira - 170098168";

class Game{
    private:
        static Game *instance;
        SDL_Window *window;
        SDL_Renderer *renderer;
        State *state;

        int frameStart;
        float dt;

        void CalculateDeltaTime();

        Game(string title, int width = 1024, int height = 600);
    
    public:
        ~Game();
        void Run();
        static Game &GetInstance();
        SDL_Renderer *GetRenderer();
        State &GetState();

        float GetDeltaTime();
};

#endif