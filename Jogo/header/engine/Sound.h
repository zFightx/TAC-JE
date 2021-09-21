#ifndef __Sound_H__
#define __Sound_H__

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Component.h"

class Sound : Component{
    private:
        Mix_Chunk * chunk;
        int channel;
    public:
        Sound(GameObject &associated);
        Sound(GameObject &associated, std::string file);
        ~Sound();

        void Play(int times = 1);
        void Stop();
        void Open(std::string file);
        bool IsOpen();
        bool IsPlaying();

        void Update(float dt);
        void Render();
        bool Is(std::string type);
};

#endif