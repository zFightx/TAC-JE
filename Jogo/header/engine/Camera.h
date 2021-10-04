#ifndef __Camera_H__
#define __Camera_H__

#include "GameObject.h"
#include "Vec2.h"

class Camera{
    private:
        GameObject *focus;

    public:
        Vec2 pos;
        Vec2 speed;

        void Follow(GameObject *newFocus);
        void Unfollow();
        void Update(float dt);
};

#endif