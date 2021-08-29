// #include "../../header/engine/Component.h"
#include "../../header/engine/GameObject.h"

GameObject::GameObject(){
    this->isDead = false;
    
}
GameObject::~GameObject(){
    this->components.clear();
}

void GameObject::Update(float dt){
    for(unsigned i = 0; i < this->components.size(); i++)
        this->components[i]->Update(dt);
}
void GameObject::Render(){
    for(unsigned i = 0; i < this->components.size(); i++)
        this->components[i]->Render();
}
bool GameObject::IsDead(){
    return this->isDead;
}
void GameObject::RequestDelete(){
    this->isDead = true;
}
void GameObject::AddComponent(Component *cpt){
    this->components.emplace_back(cpt);
}
void GameObject::RemoveComponent(Component *cpt){
    for(unsigned i = 0; i < this->components.size(); i++){
        if((Component *) this->components[i].get() == cpt){
            this->components.erase(this->components.begin() + i);
            break;
        }
    }
}

Component *GameObject::GetComponent(std::string type){
    for(unsigned i = 0; i < this->components.size(); i++){
        if(this->components[i]->Is(type))
            return (Component *) this->components[i].get();
    }

    return nullptr;
}