#ifndef __Component_H__
#define __Component_H__

#include <iostream>
#include "GameObject.h"

class GameObject;

class Component{
    private:

    protected:
        GameObject &associated;
        
    public:
        Component(GameObject &gameObject);
        virtual ~Component();

        virtual void Start();
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual bool Is(std::string type) = 0;

};

#endif