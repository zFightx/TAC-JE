#include "../../header/engine/Sprite.h"
#include "../../header/engine/Game.h"

Sprite::Sprite(GameObject &associated) : Component::Component(associated){
    this->texture = nullptr;
}

Sprite::Sprite(GameObject &associated, string file) : Component::Component(associated){
    this->texture = nullptr;
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
        
        this->associated.box.w = this->width;
        this->associated.box.h = this->height;
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

void Sprite::Update(float dt){

}

void Sprite::Render(){
    SDL_Renderer * renderer = Game::GetInstance().GetRenderer();
    SDL_Rect dstrect = this->clipRect;

    dstrect.x = this->associated.box.x;
    dstrect.y = this->associated.box.y;

    SDL_RenderCopy(renderer, this->texture, &this->clipRect, &dstrect);
}

bool Sprite::Is(string type){
    return type == "Sprite";
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