#include "../../header/engine/Bullet.h"
#include "../../header/engine/Game.h"

using namespace std;

Bullet::Bullet(GameObject &gameObject, float angle, float speed, float maxDistance, std::string sprite) : Component(gameObject){
    this->distanceLeft = maxDistance;
    
    this->speed.x = speed;
    this->speed = this->speed.GetRotate(angle);

    Sprite *bulletImg = new Sprite(this->associated, sprite);
    bulletImg->angleDeg = angle*180/3.14;

    cout << bulletImg->angleDeg  << endl;
    this->associated.AddComponent((Component*) bulletImg);

    this->damage = 5;
}

Bullet::~Bullet(){
    
}

void Bullet::Update(float dt){
    
    Vec2 move = this->speed * dt;

    this->associated.box.x += move.x;
    this->associated.box.y += move.y;

    this->distanceLeft -= move.Magnitude();

    if(this->distanceLeft <= 0){
        this->associated.RequestDelete();
    }
}

void Bullet::Render(){

}

int Bullet::GetDamage(){
    return this->damage;
}

bool Bullet::Is(std::string type){
    return type == "Bullet";
}
