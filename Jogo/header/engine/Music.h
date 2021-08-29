#ifndef __Music_H__
#define __Music_H__

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <iostream>
using std::string;

class Music{
    private:
        Mix_Music * music;
    public:
        Music();
        Music(string file);
        ~Music();

        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(string file);
        bool IsOpen();
};

#endif