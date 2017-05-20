#include "TileMap.hpp"
#include <string>
#include <stdio.h>
#include <iostream>

TileMap::TileMap(std::string filename, TileSet *tileSet) {
    Load(filename);

    this->tileSet = tileSet;
}

void TileMap::Load(std::string file) {
    FILE *fp;
    fp = fopen(file.c_str(), "r");
    if(fp == nullptr){
        std::cerr << "Could not open file " << file << " for tileset" << std::endl;
    }
    fscanf(fp, "%d,%d,%d,\n\n", &mapWidth, &mapHeight, &mapDepth);

    int d = 0;
    int read = -1;

    for (int k = 0; k < mapDepth; k++) {
        for (int j = 0; j < mapHeight; j++) {
            for (int i = 0; i < mapWidth; i++) {
                read = fscanf(fp, "%d,", &d);
                if (read != 1){
                    std::cerr << "Failed to read tile index!" << std::endl;
                }
                tileMatrix.push_back(d-1);
            }
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
}

void TileMap::setTileSet(TileSet *tileSet) {
    if (this->tileSet) {
        delete tileSet;
    }
    this->tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z) {
    return tileMatrix[mapWidth * mapHeight * z + mapWidth * y + x];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
    int tileIndex = -1;
    int j, i;

    for (j = 0; j < getHeight(); j++)
        for (i = 0; i < getWidth(); i++) {
            tileIndex = At(i, j, layer);
            tileSet->Render(At(i, j, layer), cameraX + i * tileSet->getTileWidth(),
                            -cameraY + j * tileSet->getTileHeight());
        }
}

void TileMap::RenderLayer(int layer, const Vec2 &cam) {
    RenderLayer(layer, cam.x, cam.y);
}

int TileMap::getWidth() {
    return mapWidth;
}

int TileMap::getHeight() {
    return mapHeight;
}

int TileMap::getDepth() {
    return mapDepth;
}

void TileMap::Render(int cameraX, int cameraY) {
    int k;

    for(k = 0; k < mapDepth; k++)
        RenderLayer(k, cameraX, cameraY);
}
