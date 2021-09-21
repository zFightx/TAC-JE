#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <iostream>
#include <unordered_map>

using std::string;

class Resources{
    private:
        static std::unordered_map<string, SDL_Texture *> imageTable;
        static std::unordered_map<string, Mix_Music *> musicTable;
        static std::unordered_map<string, Mix_Chunk *> soundTable;

    public:
        static SDL_Texture *GetImage(string file);
        static void ClearImages();
        
        static Mix_Music *GetMusic(string file);
        static void ClearMusics();

        static Mix_Chunk *GetSound(string file);
        static void ClearSounds();
};

#endif