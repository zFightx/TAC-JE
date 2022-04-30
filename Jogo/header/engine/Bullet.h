#ifndef __Bullet_H__
#define __Bullet_H__

#include <iostream>
#include "GameObject.h"

class GameObject;


class Bullet : Component{
    private:
        Vec2 speed;
        float distanceLeft;
        int damage;

    public:
        Bullet(GameObject &gameObject, float angle, float speed, float maxDistance, std::string sprite);
        ~Bullet();

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        int GetDamage();

};

#endif