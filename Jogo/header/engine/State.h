#ifndef __State_H__
#define __State_H__

#define INCLUDE_SDL
#include "SDL_include.h"

#include <vector>
#include <memory>

#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"

class State{
    private:
        Sprite *bg;
        Music music;        

        bool quitRequested;

        std::vector<std::unique_ptr<GameObject>> objectArray;

        void Input ();
        void AddObject (int mouseX, int mouseY);
    public:
        State();
        ~State();

        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};

#endif