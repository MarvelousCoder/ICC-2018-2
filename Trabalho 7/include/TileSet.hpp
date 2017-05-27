#ifndef TILESETHPP
#define TILESETHPP

#include <string>
#include "Sprite.hpp"
class TileSet {
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;
public:
    TileSet(int tileWidth, int tileHeight, std::string file);
    void Render(unsigned int index, float x, float y);
    int getTileWidth();
    int getTileHeight();
};

#endif // TILESETHPP
