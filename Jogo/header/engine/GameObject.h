#ifndef __GameObject_H__
#define __GameObject_H__

#include "Component.h"

#include <iostream>
#include <vector>
#include <memory>

#include "Rect.h"

class Component;

class GameObject{
    private:
        std::vector< std::unique_ptr<Component> > components;
        bool isDead;
        bool started; 
    protected:
        
    public:
        Rect box;
        double angleDeg;

        GameObject();
        ~GameObject();

        void Start();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component *cpt);
        void RemoveComponent(Component *cpt);
        Component *GetComponent(std::string type);
};

#endif