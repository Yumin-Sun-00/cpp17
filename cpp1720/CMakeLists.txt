cmake_minimum_required(VERSION 3.5)

project(cpp1720 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include_directories(
#Dependencies/glfw/include
#)

#to link static library
#libglfw3.a
#find_library(GLFW_LIB NAMES libglfw.3.dylib PATHS "${CMAKE_SOURCE_DIR}/Dependencies/glfw/lib-x86_64")

#message("GLFW_LIB: " ${GLFW_LIB})

add_executable(cpp1720
#variant_unions.cpp
#span.cpp
#optional.cpp
#instantiate.cpp
#stack_heap.cpp
#lvalue_rvalue.cpp
#move.cpp
#malloc_new.cpp
#globallocalallocation.cpp
#array.cpp
#static.cpp
#main_static.cpp #for static.cpp
#localstatic.cpp
#main_linker.cpp
#Log.cpp
#Log.h
#Log2.cpp
#Log2.h
#mutable.cpp
#const.cpp
#typeconversions.cpp
#lib_staticlinking.cpp
#lib_dynamiclinking.cpp
#precompiledheaders.cpp
#pch.h
#pch.cpp
#new.cpp
#namespace.cpp
#smartpointers.cpp
#copy.cpp
this.cpp
)

#target_link_libraries(cpp1720
#    ${GLFW_LIB}
#    "-framework Cocoa"
#    "-framework OpenGL"
#    "-framework IOKit"
#)

install(TARGETS cpp1720
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
