#include "../../header/engine/Sprite.h"
#include "../../header/engine/Game.h"
#include "../../header/engine/Resources.h"
#include "../../header/engine/Camera.h"

#include <math.h>

Sprite::Sprite(GameObject &associated) : Component::Component(associated){
    this->texture = nullptr;
    this->scale = Vec2(1.0, 1.0);
    this->angleDeg = this->associated.angleDeg;
}

Sprite::Sprite(GameObject &associated, string file) : Component::Component(associated){
    this->texture = nullptr;
    this->scale = Vec2(1.0, 1.0);
    this->angleDeg = this->associated.angleDeg;
    this->Open(file);
}

Sprite::~Sprite(){
    this->texture = nullptr;
}

void Sprite::Open(string file){
    if(this->texture != nullptr){
        this->texture = nullptr;
    }

    this->texture = Resources::GetImage(file);
    // this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

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
    this->Render(this->associated.box.x  - Camera::pos.x, this->associated.box.y - Camera::pos.y);
}

void Sprite::Render(int x, int y){
    SDL_Renderer * renderer = Game::GetInstance().GetRenderer();
    SDL_Rect dstrect;

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = (int) round(this->clipRect.w * this->scale.x);
    dstrect.h = (int) round(this->clipRect.h * this->scale.y);    

    SDL_RenderCopyEx(renderer, this->texture, &this->clipRect, &dstrect, this->angleDeg, nullptr, SDL_FLIP_NONE);
}

bool Sprite::Is(string type){
    return type == "Sprite";
}

int Sprite::GetWidth(){
    return this->width*this->scale.x;
}

int Sprite::GetHeight(){
    return this->height*this->scale.y;
}

void Sprite::SetScaleX(float scaleX, float scaleY){
    this->scale.x = scaleX != 0.0 ? scaleX : this->scale.x;
    this->scale.y = scaleY != 0.0 ? scaleY : this->scale.y;

    this->associated.box.w = this->GetWidth();
    this->associated.box.h = this->GetHeight();
    this->associated.box.x -= this->associated.box.w/2;
    this->associated.box.y -= this->associated.box.h/2;
}

Vec2 Sprite::GetScale(){
    return this->scale;
}

bool Sprite::IsOpen(){
    return this->texture != nullptr;
}