#include "../../header/engine/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, string file){
    GameObject gameObject{};
    this->tileSet = new Sprite(gameObject, file);
    
    this->colums = this->tileSet->GetWidth() / tileWidth;
    this->rows = this->tileSet->GetHeight() / tileHeight;

    this->tileHeight = tileHeight;
    this->tileWidth = tileWidth;
}

TileSet::~TileSet(){
    delete this->tileSet;
}

void TileSet::RenderTile(int index, float x, float y){
    if(index < (this->colums * this->rows)-1 && this->colums > 0){
        int startX = (index % this->colums) * this->tileWidth;
        int startY = (index / this->colums) * this->tileHeight;
                
        // voltar aqui se der errado
        this->tileSet->SetClip(startX, startY, this->tileWidth, this->tileHeight);
        this->tileSet->Render(x, y);
    }
}
int TileSet::GetTileWidth(){
    return this->tileWidth;
}
int TileSet::GetTileHeight(){
    return this->tileHeight;
}