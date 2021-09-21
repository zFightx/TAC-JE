
#include "../../header/engine/Resources.h"
#include "../../header/engine/Game.h"

std::unordered_map<string, SDL_Texture *> Resources::imageTable;
std::unordered_map<string, Mix_Music *> Resources::musicTable;
std::unordered_map<string, Mix_Chunk *> Resources::soundTable;

SDL_Texture * Resources::GetImage(string file){
    std::unordered_map<string, SDL_Texture*>::const_iterator found = Resources::imageTable.find(file);

    if(found == Resources::imageTable.end()){
        // not found
        SDL_Texture *newTexture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
        if(newTexture){
            Resources::imageTable.emplace(file, newTexture);

            return newTexture;
        }

        return nullptr;
    }
    else{
        return found->second;
    }
}
void Resources::ClearImages(){
    for(std::pair<string, SDL_Texture*> element : Resources::imageTable){
        SDL_DestroyTexture(element.second);
    }

    Resources::imageTable.clear();
}

Mix_Music * Resources::GetMusic(string file){
    std::unordered_map<string, Mix_Music*>::const_iterator found = Resources::musicTable.find(file);

    if(found == Resources::musicTable.end()){
        // not found
        Mix_Music *newMusic = Mix_LoadMUS( file.c_str() );
        if(newMusic){
            Resources::musicTable.emplace(file, newMusic);

            return newMusic;
        }
        else{
            return nullptr;
        }
    }
    else{
        return found->second;
    }
}
void Resources::ClearMusics(){
    for(std::pair<string, Mix_Music *> element : Resources::musicTable){
        Mix_FreeMusic(element.second);
    }

    Resources::musicTable.clear();
}

Mix_Chunk * Resources::GetSound(string file){
    std::unordered_map<string, Mix_Chunk*>::const_iterator found = Resources::soundTable.find(file);

    if(found == Resources::soundTable.end()){
        // not found
        Mix_Chunk *newSound = Mix_LoadWAV( file.c_str() );
        if(newSound){
            Resources::soundTable.emplace(file, newSound);

            return newSound;
        }
        else{
            return nullptr;
        }
    }
    else{
        return found->second;
    }
}
void Resources::ClearSounds(){
    for(std::pair<string, Mix_Chunk*> element : Resources::soundTable){
        Mix_FreeChunk(element.second);
    }

    Resources::soundTable.clear();
}