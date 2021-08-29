#include "../../header/engine/Rect.h"

Rect::Rect(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}
Rect::~Rect(){

}

Vec2 Rect::CenterSquare(Rect square){
    return Vec2( (square.x+square.w)/2.0, (square.y+square.h)/2.0 );
}
Vec2 Rect::CenterSquare(){
    return Vec2( (this->x+this->w)/2.0, (this->y+this->h)/2.0 );
}

Rect Rect::SumVec2(Rect rect, Vec2 vector){
    return Rect(rect.x+vector.x, rect.y+vector.y, rect.w, rect.h);
}
void Rect::SumVec2(Vec2 vector){
    this->x += vector.x;
    this->y += vector.y;
}

float Rect::GetDistanceRect(Rect rect1, Rect rect2){
    Vec2 center1 = rect1.CenterSquare();
    Vec2 center2 = rect2.CenterSquare();

    return Vec2::GetDistance(center1, center2);
}
float Rect::GetDistanceRect(Rect rect){
    Vec2 center1 = this->CenterSquare();
    Vec2 center2 = rect.CenterSquare();

    return Vec2::GetDistance(center1, center2);
}

bool Rect::IsCoordInRect(Rect rect, Vec2 coord){
    const float minX = rect.x;
    const float maxX = minX + rect.w;
    const float minY = rect.y;
    const float maxY = minY + rect.h;

    const bool inX = ( coord.x >= minX && coord.x <= maxX);
    const bool inY = ( coord.y >= minY && coord.y <= maxY);

    return ( inX && inY );
}
bool Rect::IsCoordInRect(Vec2 coord){
    const float minX = this->x;
    const float maxX = minX + this->w;
    const float minY = this->y;
    const float maxY = minY + this->h;

    const bool inX = ( coord.x >= minX && coord.x <= maxX);
    const bool inY = ( coord.y >= minY && coord.y <= maxY);

    return ( inX && inY );
}