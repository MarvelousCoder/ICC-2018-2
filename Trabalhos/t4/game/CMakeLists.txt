project(game01)

add_executable(game01 main.cpp Game.cpp GameException.cpp State.cpp Sprite.cpp Sprite.h Vec2.cpp Vec2.h Rect.cpp Rect.h GameObject.cpp GameObject.h Face.cpp Face.h StateInput.cpp TileSet.cpp TileSet.h GameException.cpp GameException.h TileMap.cpp TileMap.h GameConfig.h CommandLineParser.cpp CommandLineParser.h GameConfig.cpp Resources.cpp Resources.h InputManager.cpp InputManager.h defines.h)

include_directories(include ${SDL2_IMAGE_INCLUDE_DIR})

target_link_libraries(game01 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

add_library(Util Util.cpp Util.h)

add_library(Vec2 Vec2.cpp Vec2.h)

add_library(Rect Rect.cpp Rect.h)

add_library(ArgParse CommandLineParser.cpp CommandLineParser.h)

install(TARGETS game01 RUNTIME DESTINATION ${BIN_DIR})
