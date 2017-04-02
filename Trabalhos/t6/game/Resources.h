//
// Created by jasf on 3/25/16.
//

#ifndef IDJ201601T1_RESOURCES_H
#define IDJ201601T1_RESOURCES_H

#include <unordered_map>
#include <string>
#include <SDL_render.h>

class Resources {

protected:
   static std::unordered_map<std::string, SDL_Texture*> imageTable;

public:

    static SDL_Texture* getImage(std::string filename);

    static void clearImages();

};


#endif //IDJ201601T1_RESOURCES_H
