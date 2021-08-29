#ifndef __Vec2_H__
#define __Vec2_H__

class Vec2{
    private:

    public:
        float x;
        float y;

        Vec2(float x = 0.0, float y = 0.0);
        ~Vec2();

        static Vec2 Sum(Vec2 vector1, Vec2 vector2);
        static Vec2 Subtract(Vec2 vector1, Vec2 vector2);
        static Vec2 MultScalar(Vec2 vector, float scalar);
        static Vec2 GetNormalize(Vec2 vector);

        static float Magnitude(Vec2 vector);
        static float GetDistance(Vec2 vector1, Vec2 vector2);
        static float GetSlopeX(Vec2 vector);
        static float GetSlopeVectors(Vec2 vector1, Vec2 vector2);
        static Vec2 GetRotate(Vec2 vector, float angle);

        void Sum(Vec2 vector);
        void Subtract(Vec2 vector);
        void MultScalar(float scalar);

        Vec2 GetNormalize();
        float Magnitude();
        float GetDistance(Vec2 vector);
        float GetSlopeX();
        float GetSlopeVectors(Vec2 vector);
        Vec2 GetRotate(float angle);

        Vec2 operator+(Vec2 vector);
        Vec2 operator-(Vec2 vector);
        void operator+=(Vec2 vector);
        void operator-=(Vec2 vector);
};

#endif