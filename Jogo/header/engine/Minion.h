#ifndef __Minion_H__
#define __Minion_H__

#include <iostream>
#include "GameObject.h"

class GameObject;

class Minion : Component{
    private:
        std::weak_ptr<GameObject> alienCenter;
        float arc;

    public:
        Minion(GameObject &gameObject, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);
        ~Minion();

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        void Shoot(Vec2 target);
};

#endif