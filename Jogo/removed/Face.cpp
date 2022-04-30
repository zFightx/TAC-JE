#include "../../header/engine/Face.h"
#include "../../header/engine/Sound.h"
#include "../../header/engine/Sprite.h"
#include "../../header/engine/InputManager.h"

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
    }else{
        if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
            int mouseX = InputManager::GetInstance().GetMouseX();
            int mouseY = InputManager::GetInstance().GetMouseY();

            if(this->associated.box.IsCoordInRect( {(float)mouseX, (float)mouseY} ) ) {
                this->Damage(std::rand() % 10 + 10);
            }
        }
    }
}
void Face::Render(){

}
bool Face::Is(std::string type){
    return type == "Face";
}