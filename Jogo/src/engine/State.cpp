#include "../../header/engine/State.h"

State::State(){
    this->quitRequested = false;

    // Instanciar Sprite aqui
    this->bg = Sprite();
    this->music = Music();
}

bool State::QuitRequested(){
    return this->quitRequested;
}

void State::LoadAssets(){
    this->bg.Open("assets/img/ocean.jpg");
    this->music.Open("assets/audio/stageState.ogg");

    if(this->music.IsOpen()){
        this->music.Play();
    }
}

void State::Update(float dt){
    this->quitRequested = SDL_QuitRequested();
}

void State::Render(){
    this->bg.Render(0,0);
}