#ifndef __Alien_H__
#define __Alien_H__

#include <iostream>
#include "GameObject.h"
#include <queue>

class GameObject;

enum ActionType {
    MOVE,
    SHOOT,
};

class Alien : Component{
    private:
        class Action{
            public: 
                ActionType type;
                Vec2 pos;

                Action();
                Action(ActionType type, float x, float y);
        };

        Action action;
        Vec2 speed;
        int hp;
        int nMinions;
        std::queue<Action> taskQueue;
        std::vector<std::weak_ptr<GameObject>> minionArray;

    public:
        Alien(GameObject &gameObject, int nMinions);
        ~Alien();

        void Start();
        void Update(float dt);
        void Render();
        bool Is(std::string type);

};

#endif