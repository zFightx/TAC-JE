#ifndef __TileMap_H__
#define __TileMap_H__

#include "GameObject.h"
#include "TileSet.h"

class TileMap : Component{
    private:
        std::vector<int> tileMatrix;
        TileSet *tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;

    public:
        TileMap(GameObject &associated, string file, TileSet * tileSet);
        ~TileMap();
        
        void Load(string file);
        void SetTileSet(TileSet * tileSet);
        int &At(int x, int y, int z = 0);
        void Render();
        void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
        int GetWidth();
        int GetHeight();
        int GetDepth();

        void Update(float dt);
        bool Is(string type);
};

#endif