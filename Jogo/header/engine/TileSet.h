#ifndef __TileSet_H__
#define __TileSet_H__

#include "Sprite.h"

class TileSet{
    private:
        Sprite *tileSet;
        int rows;
        int colums;

        int tileWidth;
        int tileHeight;

    public:
        TileSet(int tileWidth, int tileHeight, string file);
        ~TileSet();

        void RenderTile(int index, float x, float y);
        int GetTileWidth();
        int GetTileHeight();
};

#endif