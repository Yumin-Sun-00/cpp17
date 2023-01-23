cmake_minimum_required(VERSION 3.5)

project(Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(
../Engine
)

find_library(ENGINE_LIB NAMES libEngine.a PATHS "../build-Engine-Qt_6_4_2_for_macOS-Release")

message("engine lib: " ${ENGINE_LIB})
add_executable(Game main.cpp)

target_link_libraries(Game ${ENGINE_LIB})

install(TARGETS Game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

