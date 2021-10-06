#include "../../header/engine/Camera.h"
#include "../../header/engine/InputManager.h"

Vec2 Camera::pos = Vec2(0.0, 0.0);
Vec2 Camera::speed = Vec2(0.0, 0.0);
GameObject* Camera::focus = nullptr;

void Camera::Follow(GameObject *newFocus){
    Camera::focus = newFocus;
}
void Camera::Unfollow(){
    Camera::focus = nullptr;
}
void Camera::Update(float dt){
    if(Camera::focus){
        Vec2 center = Camera::focus->box.CenterSquare();
        Camera::pos = center;
    }
    else if(!Camera::focus){
        Camera::speed.x = 0.0;
        Camera::speed.y = 0.0;

        if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)){
            Camera::speed.x = 100 * dt * -1.0;
        }
        if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)){
            Camera::speed.x = 100 * dt;
        }
        if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)){
            Camera::speed.y = 100 * dt * -1.0;
        }
        if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)){
            Camera::speed.y = 100 * dt;
        }

        Camera::pos += Camera::speed;
    }
}