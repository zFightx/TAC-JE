#ifndef __Sprite_H__
#define __Sprite_H__

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include "Component.h"

#include <iostream>
using std::string;

class Sprite : Component{
    private:
        SDL_Texture *texture;
        int width;
        int height;
        SDL_Rect clipRect;

    public:
        Sprite(GameObject &associated);
        Sprite(GameObject &associated, string file);
        ~Sprite();

        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Update(float dt);
        void Render();
        bool Is(string type);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
};

#endif