//
// Created by jasf on 3/25/16.
//

#include "Resources.h"
#include "Game.h"
#include <SDL_image.h>

#include <utility>
#include <string>
#include <iostream>

std::unordered_map<std::string, SDL_Texture *> Resources::imageTable;

SDL_Texture *Resources::getImage(std::string filename) {
    if (imageTable.find(filename) != imageTable.end())
        return imageTable[filename];

    SDL_Texture *texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), filename.c_str());

    if (!texture) {
        std::cerr << "Error while loading texture on file " << filename << std::endl;
        std::cerr << SDL_GetError() << std::endl;
    }

    imageTable.emplace(std::make_pair(filename, texture));

    return texture;

}

void Resources::clearImages() {

    for(auto tableEntry : imageTable) {
        if (tableEntry.second)
            SDL_DestroyTexture(tableEntry.second);
    }

    imageTable.clear();


}
