project(game01_tests)

add_executable(util_test01 util_test01.cpp)
target_link_libraries(util_test01 Util Vec2)

add_executable(vec2test Vec2UnitTest.cpp)
target_link_libraries(vec2test Vec2)

add_executable(recttest RectTest.cpp)
target_link_libraries(recttest Rect Vec2)

add_executable(argparsetest ArgParseTest.cpp)
target_link_libraries(argparsetest ArgParse)
