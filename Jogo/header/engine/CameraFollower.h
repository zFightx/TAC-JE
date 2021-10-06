#ifndef __CameraFollower_H__
#define __CameraFollower_H__

#include "Component.h"

class CameraFollower : Component{
    public:
        CameraFollower(GameObject &go);

        void Update(float dt);
        void Render();
        bool Is(std::string type);

};

#endif