#include "Resources.hpp"
#include "Game.hpp"

#include <utility>
#include <string>
#include <iostream>
using std::cerr;


std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;

SDL_Texture* Resources::getImage(std::string file) {
    if (imageTable.find(file) != imageTable.end())
        return imageTable[file];

    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

    if (!texture) {
        cerr << "Error while loading texture on file " << file << endl;
        cerr << SDL_GetError() << endl;
    }

    imageTable.emplace(std::make_pair(file, texture));

    return texture;

}

void Resources::clearImages() {

    for(auto tableEntry : imageTable) {
        if (tableEntry.second)
            SDL_DestroyTexture(tableEntry.second);
    }

    imageTable.clear();
}
