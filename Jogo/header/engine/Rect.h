#ifndef __Rect_H__
#define __Rect_H__

#include "Vec2.h"

class Rect{
    private:

    public:
        float x;
        float y;
        float w;
        float h;

        Rect(float x = 0.0, float y = 0.0, float w = 0.0, float h = 0.0);
        ~Rect();

        static Vec2 CenterSquare(Rect square);
        static Rect SumVec2(Rect rect, Vec2 vector);
        static float GetDistanceRect(Rect rect1, Rect rect2);
        static bool IsCoordInRect(Rect rect, Vec2 coord);

        Vec2 CenterSquare();
        void SumVec2(Vec2 vector);
        float GetDistanceRect(Rect rect);
        bool IsCoordInRect(Vec2 coord);
};

#endif