#ifndef RESOURCESHPP
#define RESOURCESHPP

#include <unordered_map>
#include <string>
#include "SDL_render.h"

class Resources {
    static std::unordered_map<std::string, SDL_Texture*> imageTable;
public:
    static SDL_Texture* getImage(std::string file);
    static void clearImages();
};

#endif // RESOURCESHPP
