project(game01)

add_executable(game01 main.cpp Game.cpp GameException.cpp State.cpp Sprite.cpp Sprite.h Vec2.cpp Vec2.h)

include_directories(include ${SDL2_IMAGE_INCLUDE_DIR})

target_link_libraries(game01 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

add_library(Util Util.cpp Util.h Vec2.cpp Vec2.h)

add_library(Vec2 Vec2.cpp Vec2.h)

install(TARGETS game01 RUNTIME DESTINATION ${BIN_DIR})
