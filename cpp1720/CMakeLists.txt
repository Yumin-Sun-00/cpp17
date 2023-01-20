cmake_minimum_required(VERSION 3.5)

project(cpp1720 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp1720
#variant_unions.cpp
#span.cpp
#optional.cpp
#stack_heap.cpp
#lvalue_rvalue.cpp
#move.cpp
#malloc_new.cpp
#array.cpp
static.cpp
main_static.cpp #for static.cpp
)

install(TARGETS cpp1720
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
