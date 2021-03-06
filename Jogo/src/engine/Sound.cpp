#include "../../header/engine/Sound.h"
#include "../../header/engine/Resources.h"

Sound::Sound(GameObject &associated) : Component(associated){
    this->chunk = nullptr;
}

Sound::Sound(GameObject &associated, std::string file) : Component(associated){
    this->Open(file);
}

void Sound::Play(int times){
    if(this->chunk != nullptr)
        this->channel = Mix_PlayChannel(-1, this->chunk, times-1);
}

bool Sound::IsPlaying(){
    return Mix_Playing(this->channel);
}

void Sound::Stop(){
    if(this->chunk != nullptr)
        Mix_HaltChannel(this->channel);
}

void Sound::Open(std::string file){
    this->chunk = Resources::GetSound(file);
    // this->chunk = Mix_LoadWAV( file.c_str() );

    if(this->chunk == nullptr){
        // Tratar erro de carregamento de musica
        printf("Sound: Erro ao abrir sound, ponteiro nullptr\n");
        printf(SDL_GetError());
    }
}

bool Sound::IsOpen(){
    return this->chunk != nullptr;
}

Sound::~Sound(){
    this->Stop();
}

void Sound::Update(float dt){

}
void Sound::Render(){

}
bool Sound::Is(std::string type){
    return type == "Sound";
}