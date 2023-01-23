cmake_minimum_required(VERSION 3.14)

project(Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Engine STATIC
  engine.cpp
  engine.h
)

target_compile_definitions(Engine PRIVATE ENGINE_LIBRARY)
