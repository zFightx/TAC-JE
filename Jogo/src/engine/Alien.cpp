#include "../../header/engine/Alien.h"
#include "../../header/engine/Minion.h"
#include "../../header/engine/InputManager.h"
#include "../../header/engine/Camera.h"
#include "../../header/engine/Sprite.h"
#include "../../header/engine/Game.h"

#include <math.h>

using namespace std;

Alien::Action::Action(){

}

Alien::Action::Action(ActionType type, float x, float y){
    this->type = type;
    this->pos = Vec2(x, y);
}

Alien::Alien(GameObject &gameObject, int nMinions) : Component(gameObject){
    this->hp = 100;
    this->nMinions = nMinions;
}

Alien::~Alien(){
    this->minionArray.clear();
}

void Alien::Start(){
    Game &game = Game::GetInstance();
    State &state = game.GetState();
    weak_ptr<GameObject> alienPtr = state.GetObjectPtr(&this->associated);

    float arc = 360.0f / this->nMinions;

    for(int i = 0; i < this->nMinions; i++){
        GameObject *minionObject = new GameObject();
        Sprite *minionImg = new Sprite(*minionObject, "assets/img/minion.png");

        const float scale = float(rand())/float((RAND_MAX)) * 1.5;
        if(scale > 1.0)
            minionImg->SetScaleX(scale, scale);

        Minion *minion = new Minion(*minionObject, alienPtr, arc*i);

        minionObject->AddComponent((Component*) minionImg);
        minionObject->AddComponent((Component*) minion);

        Vec2 pos = this->associated.box.CenterSquare();

        minionObject->box.x = pos.x - (minionObject->box.w / 2);
        minionObject->box.y = pos.y - (minionObject->box.h / 2);

        weak_ptr<GameObject> minionPtr = state.AddObject(minionObject);
        this->minionArray.push_back(minionPtr);
    }
}

void Alien::Update(float dt){
    InputManager instance = InputManager::GetInstance();
    Vec2 posCamera = Camera::pos;

    Sprite * sprite = (Sprite*) this->associated.GetComponent("Sprite");
    sprite->angleDeg = sprite->angleDeg <= 0.0 ? 360.0 : sprite->angleDeg - 1;

    if(instance.MousePress(RIGHT_MOUSE_BUTTON)){
        float x = ((instance.GetMouseX()) - (this->associated.box.w/2));
        float y = ((instance.GetMouseY()) - (this->associated.box.h/2));

        Action action(ActionType::MOVE, x, y);
        this->taskQueue.push(action);
    }

    if(instance.MousePress(LEFT_MOUSE_BUTTON)){
        float x = instance.GetMouseX();
        float y = instance.GetMouseY();

        Action action(ActionType::SHOOT, x, y);
        this->taskQueue.push(action);
    }
    
    if(this->taskQueue.size() > 0){
        Action action = this->taskQueue.front();

        if(action.type == ActionType::MOVE){
            float speed = 5.0f;

            Vec2 posI = Vec2(this->associated.box.x, this->associated.box.y);
            Vec2 posDt = action.pos - posI;

            this->speed += posDt.GetNormalize() * speed * dt;

            Vec2 posF = posI + this->speed;

            if (posI.GetDistance(posF) > posI.GetDistance(action.pos)) {
                this->speed.x = 0.0f;
                this->speed.y = 0.0f;

                this->associated.box.x = action.pos.x;
                this->associated.box.y = action.pos.y;

                this->taskQueue.pop();
            }
            else {
                this->associated.box.x += this->speed.x;
                this->associated.box.y += this->speed.y; 
            }
        }
        else if(action.type == ActionType::SHOOT){
            int minionId = std::rand() % this->nMinions;

            Minion *minion = (Minion *) this->minionArray[minionId].lock().get()->GetComponent("Minion");
            minion->Shoot(this->taskQueue.front().pos);

            this->taskQueue.pop();
        }
    }

    if(this->hp <= 0){
        this->associated.RequestDelete();
    }
}

void Alien::Render(){

}

bool Alien::Is(std::string type){
    return type == "Alien";
}
