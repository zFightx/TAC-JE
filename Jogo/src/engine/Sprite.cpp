#include "../../header/engine/Sprite.h"
#include "../../header/engine/Game.h"

Sprite::Sprite(){
    this->texture = nullptr;
}

Sprite::Sprite(string file){
    this->Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
    this->texture = nullptr;
}

void Sprite::Open(string file){
    if(this->texture != nullptr){
        SDL_DestroyTexture(this->texture);
        this->texture = nullptr;
    }

    this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

    if(this->texture != nullptr){
        SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);
        this->SetClip(0, 0, this->width, this->height);
    }
    else{
        printf("Sprite: Erro ao abrir um Sprit, pointeiro nullptr");
        printf(SDL_GetError());
    }
}

void Sprite::SetClip(int x, int y, int w, int h){
    this->clipRect.x = x;
    this->clipRect.y = y;
    this->clipRect.w = w;
    this->clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Renderer * renderer = Game::GetInstance().GetRenderer();
    SDL_Rect dstrect = this->clipRect;

    dstrect.x = x;
    dstrect.y = y;

    SDL_RenderCopy(renderer, this->texture, &this->clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return this->width;
}

int Sprite::GetHeight(){
    return this->height;
}

bool Sprite::IsOpen(){
    return this->texture != nullptr;
}