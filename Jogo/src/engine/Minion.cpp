#include "../../header/engine/Minion.h"
#include "../../header/engine/Bullet.h"
#include "../../header/engine/Game.h"

using namespace std;

Minion::Minion(GameObject &gameObject, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(gameObject){
    this->alienCenter = alienCenter;
    this->arc = arcOffsetDeg;
}

Minion::~Minion(){
    
}

void Minion::Update(float dt){
    float speed = 80.0f;   
    Vec2 offset = Vec2(200.0f, 0.0f);

    shared_ptr<GameObject> sharedAlien = this->alienCenter.lock();
    
    if(sharedAlien){
        GameObject *alien = sharedAlien.get();

        this->arc += speed * dt;
        Vec2 rotate = offset.GetRotate((this->arc*3.14)/180);

        Vec2 pos = alien->box.CenterSquare();
        pos += rotate;

        this->associated.box.x = (pos.x - (this->associated.box.w / 2));
        this->associated.box.y = (pos.y - (this->associated.box.h / 2));

        // translação
        Vec2 pos2 = this->associated.box.CenterSquare();
        float angle = pos2.GetSlopeVectors(alien->box.CenterSquare());

        Sprite *sprite = (Sprite*) this->associated.GetComponent("Sprite");
        sprite->angleDeg = angle;
    }
    else{
        this->associated.RequestDelete();
    }
}

void Minion::Shoot(Vec2 target){
    GameObject *bulletObject = new GameObject();

    std::string sprite = "assets/img/minionbullet1.png";
    float angle = this->associated.box.CenterSquare().GetSlopeVectors(target);
    float speed = 400.0f;
    float maxDistance = 1000.0f;

    Bullet *bullet = new Bullet(*bulletObject, ((angle+180.0)*3.14)/180, speed, maxDistance, sprite);

    bulletObject->box.x = this->associated.box.CenterSquare().x;
    bulletObject->box.y = this->associated.box.CenterSquare().y;

    bulletObject->AddComponent((Component*) bullet);

    Game::GetInstance().GetState().AddObject(bulletObject);
}

void Minion::Render(){

}

bool Minion::Is(std::string type){
    return type == "Minion";
}
