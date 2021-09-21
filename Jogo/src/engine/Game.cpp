#include <iostream>

#include "../../header/engine/Game.h"
#include "../../header/engine/Resources.h"

using std::cout;
using std::string;

Game *Game::instance = nullptr;

Game::Game(string title, int width, int height){
    if(Game::instance == nullptr){
        bool init1 = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0;
        bool init2 = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
        bool init3 = Mix_Init(MIX_INIT_OGG) == (MIX_INIT_OGG);
        bool openAudio = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == 0;
        bool allocateChannels = Mix_AllocateChannels(32) == 32;

        if(!init1 || !init2 || !init3){
            printf("Falha na inicializacao de Game");
            printf(SDL_GetError());
            return;
        }

        if(!openAudio){
            printf("Falha na inicializacao de Audio");
        }
        if(!allocateChannels){
            printf("Falha na alocacao de Channels");
        }

        this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

        this->state = new State();
    }
    else
        printf("Erro: Uma segunda instancia da classe Game criada.\n");
}

Game::~Game(){
    delete this->state;
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::Run(){
    while(this->state != nullptr && !this->state->QuitRequested()){
        this->state->Update(0.3);
        this->state->Render();

        SDL_RenderPresent(this->renderer);
        
        SDL_Delay(33);
    }

    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}

Game &Game::GetInstance(){
    if(Game::instance != nullptr) 
        return *Game::instance;
    
    Game::instance = new Game(name);
    return *Game::instance;
}

SDL_Renderer *Game::GetRenderer(){
    return this->renderer;
}

State &Game::GetState(){
    return *this->state;
}