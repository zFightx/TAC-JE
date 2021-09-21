#include "../../header/engine/Face.h"
#include "../../header/engine/Sound.h"
#include "../../header/engine/Sprite.h"

Face::Face(GameObject &associated) : Component(associated){
    this->hitpoints = 30;
}
void Face::Damage(int damage){
    this->hitpoints -= damage;

    if(this->hitpoints <= 0){
        Sound *sound = (Sound *) this->associated.GetComponent("Sound");
        if(sound != nullptr){
            if(!sound->IsPlaying())
                sound->Play();
        }

        Component *sprite = this->associated.GetComponent("Sprite");
        this->associated.RemoveComponent(sprite);
    }
}
void Face::Update(float dt){
    if(this->hitpoints <= 0){
        Sound *sound = (Sound *) this->associated.GetComponent("Sound");
        if(sound != nullptr){
            if(!sound->IsPlaying()){
                this->associated.RequestDelete();
            }
        }        
    }
}
void Face::Render(){

}
bool Face::Is(std::string type){
    return type == "Face";
}