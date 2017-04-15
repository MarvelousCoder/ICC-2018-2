#ifndef TILEMAPHPP
#define TILEMAPHPP

#include "TileSet.hpp"
#include <vector>
#include "Vec2.hpp"

class TileMap {
    std::vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
public:
    TileMap(string file, TileSet* tileSet);
    void Load(string file);
    void setTileSet(TileSet* tileSet);
    int& At(int x, int y, int z = 0);
    void Render(int cameraX = 0, int cameraY = 0);
    void RenderLayer(int layer, int cameraX, int cameraY);
    void RenderLayer(int layer, const Vec2 & cam);
    int getWidth();
    int getHeight();
    int getDepth();
};
#endif // TILEMAPHPP
