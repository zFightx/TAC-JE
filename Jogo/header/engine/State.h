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

        bool started;
        bool quitRequested;

        std::vector<std::shared_ptr<GameObject>> objectArray;

        void Input ();
    public:
        State();
        ~State();

        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        void Start();

        std::weak_ptr<GameObject> AddObject (GameObject *go);
        std::weak_ptr<GameObject> GetObjectPtr(GameObject *go);
};

#endif