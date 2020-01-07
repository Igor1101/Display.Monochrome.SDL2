cmake_minimum_required (VERSION 2.6)
# compiler settings
set(CMAKE_CXX_COMPILER, g++)
# project settings
set(MAIN_TARGET Display.Monochrome.SDL2)
project (${MAIN_TARGET})
# user definitions
add_definitions(-DTARGET_NAME="${MAIN_TARGET}" )
add_compile_options(-g -Og)
add_library(app STATIC app.cpp)
link_libraries(${MAIN_TARGET} app SDL2)
add_executable( Display.Monochrome.SDL2 main.cpp)
