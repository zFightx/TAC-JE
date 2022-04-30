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
        Vec2 scale;

    public:
        double angleDeg;
        
        Sprite(GameObject &associated);
        Sprite(GameObject &associated, string file);
        ~Sprite();

        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Update(float dt);
        void Render();
        void Render(int x, int y);
        bool Is(string type);
        int GetWidth();
        int GetHeight();
        void SetScaleX(float scaleX, float scaleY);
        Vec2 GetScale();
        bool IsOpen();
};

#endif