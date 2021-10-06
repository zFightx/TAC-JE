#include "../../header/engine/InputManager.h"
#include "../../header/engine/Camera.h"

void InputManager::Update(){
    SDL_Event event;

    this->quitRequested = false;
    SDL_GetMouseState(&this->mouseX, &this->mouseY);

    this->updateCounter = (updateCounter+1) % UINT32_MAX;

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            this->quitRequested = true;
        }

        else if(event.type == SDL_MOUSEBUTTONDOWN){
            this->mouseState[event.button.button] = true;
            this->mouseUpdate[event.button.button] = this->updateCounter;
        }
        else if(event.type == SDL_MOUSEBUTTONUP){
            this->mouseState[event.button.button] = false;
            this->mouseUpdate[event.button.button] = this->updateCounter;
        }
        else if(event.type == SDL_KEYDOWN){
            if(event.key.repeat == 0){
                if(event.key.keysym.sym >= 0x40000000 && event.key.keysym.sym <= 0x4000011A){
                    this->keyState[event.key.keysym.sym - 0x3FFFFF81] = true;
                    this->keyUpdate[event.key.keysym.sym - 0x3FFFFF81] = this->updateCounter;
                }
                else{
                    this->keyState[event.key.keysym.sym] = true;
                    this->keyUpdate[event.key.keysym.sym] = this->updateCounter;
                }
            }
        }
        else if(event.type == SDL_KEYUP){
            if(event.key.repeat == 0){
                if(event.key.keysym.sym >= 0x40000000 && event.key.keysym.sym <= 0x4000011A){   
                    this->keyState[event.key.keysym.sym - 0x3FFFFF81] = false;
                    this->keyUpdate[event.key.keysym.sym - 0x3FFFFF81] = this->updateCounter;
                }
                else{
                    this->keyState[event.key.keysym.sym] = false;
                    this->keyUpdate[event.key.keysym.sym] = this->updateCounter;
                }
            }
        }
    }
}
bool InputManager::KeyPress(unsigned int key){
    if(key >= 0x40000000 && key <= 0x4000011A)
        key -= 0x3FFFFF81;

    return this->keyState[key] && this->keyUpdate[key] == this->updateCounter;
}
bool InputManager::KeyRelease(unsigned int key){
    if(key >= 0x40000000 && key <= 0x4000011A)
        key -= 0x3FFFFF81;

    return !this->keyState[key] && this->keyUpdate[key] == this->updateCounter;
}
bool InputManager::IsKeyDown(unsigned int key){
    if(key >= 0x40000000 && key <= 0x4000011A)
        key -= 0x3FFFFF81;
        
    return this->keyState[key];
}
bool InputManager::MousePress(int button){
    return this->mouseState[button] && this->mouseUpdate[button] == this->updateCounter;
}
bool InputManager::MouseRelease(int button){
    return !this->mouseState[button] && this->mouseUpdate[button] == this->updateCounter;
}
bool InputManager::IsMouseDown(int button){
    return this->mouseState[button];
}
int InputManager::GetMouseX(){
    return this->mouseX + Camera::pos.x;
}
int InputManager::GetMouseY(){
    return this->mouseY + Camera::pos.y;
}
bool InputManager::QuitRequested(){
    return this->quitRequested;
}
InputManager & InputManager::GetInstance(){
    static InputManager instance;

    return instance;
}
InputManager::InputManager(){
    for(auto &i : mouseState)
        i = false;
    
    for(auto &i : mouseUpdate)
        i = 0;

    for(auto &i : keyState)
        i = false;

    for(auto &i : keyUpdate)
        i = 0;

    quitRequested = false;
    updateCounter = 0;

    mouseX = 0;
    mouseY = 0;
}
InputManager::~InputManager(){
    
}