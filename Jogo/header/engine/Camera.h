#ifndef __Camera_H__
#define __Camera_H__

#include "GameObject.h"
#include "Vec2.h"

class Camera{
    private:
        static GameObject *focus;

    public:
        static Vec2 pos;
        static Vec2 speed;

        static void Follow(GameObject *newFocus);
        static void Unfollow();
        static void Update(float dt);
};

#endif