#include "../../header/engine/Music.h"

Music::Music(){
    this->music = nullptr;
}

Music::Music(string file){
    this->Open(file);
}

void Music::Play(int times){
    if(this->music != nullptr)
        Mix_PlayMusic(this->music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    this->music = Mix_LoadMUS( file.c_str() );

    if(this->music == nullptr){
        // Tratar erro de carregamento de musica
        printf("Music: Erro ao abrir musica, ponteiro nullptr\n");
        printf(SDL_GetError());
    }
}

bool Music::IsOpen(){
    return this->music != nullptr;
}

Music::~Music(){
    this->Stop();
    Mix_FreeMusic(this->music);
}