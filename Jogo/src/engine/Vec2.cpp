#include <math.h>
#include <cmath>

#include "../../header/engine/Vec2.h"

#define PI 3.14159265358979323846  /* pi */

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

Vec2::~Vec2(){

}

Vec2 Vec2::Sum(Vec2 vector1, Vec2 vector2){
    return Vec2(vector1.x + vector2.x, vector1.y + vector2.y);
}
void Vec2::Sum(Vec2 vector){
    this->x += vector.x;
    this->y += vector.y;
}

Vec2 Vec2::Subtract(Vec2 vector1, Vec2 vector2){
    return Vec2(vector1.x - vector2.x, vector1.y - vector2.y);
}
void Vec2::Subtract(Vec2 vector){
    this->x -= vector.x;
    this->y -= vector.y;
}

Vec2 Vec2::MultScalar(Vec2 vector, float scalar){
    return Vec2(vector.x*scalar, vector.y*scalar);
}
void Vec2::MultScalar(float scalar){
    this->x *= scalar;
    this->y *= scalar;
}

Vec2 Vec2::GetNormalize(Vec2 vector){
    const float magnitude = vector.Magnitude();
    return Vec2(vector.x / magnitude, vector.y / magnitude);
}
Vec2 Vec2::GetNormalize(){
    const float magnitude = this->Magnitude();
    return Vec2(this->x / magnitude, this->y / magnitude);
}

float Vec2::Magnitude(Vec2 vector){
    const float x = sqrt( (vector.x * vector.x) + (vector.y * vector.y) );
    return x;
}
float Vec2::Magnitude(){
    const float x = sqrt( (this->x * this->x) + (this->y * this->y) );
    return x;
}

float Vec2::GetDistance(Vec2 vector1, Vec2 vector2){
    Vec2 sub = Vec2::Subtract(vector1, vector2);
    return sub.Magnitude();
}
float Vec2::GetDistance(Vec2 vector){
    const float x = this->x - vector.x;
    const float y = this->y - vector.y;
    Vec2 sub(x,y);
    return sub.Magnitude();
}

float Vec2::GetSlopeX(Vec2 vector){
    // const float a = vector.y / vector.x;
    const float t = atan2(vector.y, vector.x);

    return (t*180)/PI;
}
float Vec2::GetSlopeX(){
    const float t = atan2(this->y, this->x);

    return (t*180)/PI;
}

float Vec2::GetSlopeVectors(Vec2 vector1, Vec2 vector2){
    Vec2 sub = Vec2::Subtract(vector1, vector2);
    return sub.GetSlopeX();
}
float Vec2::GetSlopeVectors(Vec2 vector){
    const float x = this->x - vector.x;
    const float y = this->y - vector.y;
    Vec2 sub(x, y);
    return sub.GetSlopeX();
}

Vec2 Vec2::GetRotate(Vec2 vector, float angle){   
    // angle = angle * 180 / PI;

    const float x = (vector.x * cosf(angle)) - (vector.y * sinf(angle));
    const float y = (vector.y * cosf(angle)) + (vector.x * sinf(angle));

    return Vec2(x,y);
}
Vec2 Vec2::GetRotate(float angle){
    // angle = angle * 180 / PI;
    
    const float x = (this->x * cosf(angle)) - (this->y * sinf(angle));
    const float y = (this->y * cosf(angle)) + (this->x * sinf(angle));

    return Vec2(x,y);
}

Vec2 Vec2::operator+(Vec2 vector){
    return Vec2::Sum({this->x, this->y}, vector);
}

Vec2 Vec2::operator-(Vec2 vector){
    return Vec2::Subtract({this->x, this->y}, vector);
}

Vec2 Vec2::operator*(float num){
    return Vec2(this->x*num, this->y*num);
}

void Vec2::operator+=(Vec2 vector){
    this->x += vector.x;
    this->y += vector.y;
}

void Vec2::operator-=(Vec2 vector){
    this->x -= vector.x;
    this->y -= vector.y;
}

void Vec2::operator*=(float num){
    this->x *= num;
    this->y *= num;
}