#include "../../header/engine/TileMap.h"
#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;

TileMap::TileMap(GameObject &associated, string file, TileSet * tileSet) : Component(associated){
    this->Load(file);
    this->tileSet = tileSet;
}

TileMap::~TileMap(){
    if(this->tileSet)
        delete this->tileSet;
}
        
void TileMap::Load(string file){
    ifstream loadFile;

    loadFile.open(file);

    if(!loadFile.is_open()){
        cout << "Falha ao abrir o arquivo " << file << endl;
    }
    else{
        string line;
        string number;
        while(getline(loadFile, line)){
            size_t index;

            while( (index = line.find(',')) != string::npos){
                number = line.substr(0, index);
                line = line.substr(index+1, line.size() - number.size());

                this->tileMatrix.push_back( std::stoi(number) - 1 );
            }
        }

        this->mapWidth = this->tileMatrix[0] + 1;
        this->mapHeight = this->tileMatrix[1] + 1;
        this->mapDepth = this->tileMatrix[2] + 1;

        this->tileMatrix.erase( this->tileMatrix.begin(),  this->tileMatrix.begin() + 3 );
    }
}
void TileMap::SetTileSet(TileSet * tileSet){
    if(this->tileSet)
        delete this->tileSet;

    this->tileSet = tileSet;
}
int &TileMap::At(int x, int y, int z){
    return this->tileMatrix[(y*this->mapWidth + x) + (z * this->mapWidth * this->mapHeight)];
}
void TileMap::Render(){
    for(int i = 0; i < this->mapDepth; i++){
        this->RenderLayer(i, this->associated.box.x, this->associated.box.y);
    }
}
void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int height = this->tileSet->GetTileHeight();
    int width = this->tileSet->GetTileWidth();
    
    for(int i = 0; i < this->mapHeight; i++){
        for(int j = 0; j < this->mapWidth; j++){
            this->tileSet->RenderTile(this->At(j,i, layer), j*width, i*height);
        }
    }
}
int TileMap::GetWidth(){
    return this->mapWidth;
}
int TileMap::GetHeight(){
    return this->mapHeight;
}
int TileMap::GetDepth(){
    return this->mapDepth;
}
void TileMap::Update(float dt){

}
bool TileMap::Is(string type){
    return type == "TileMap";
}