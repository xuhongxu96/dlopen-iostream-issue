cmake_minimum_required(VERSION 3.16)
project (TestGCC)

add_link_options(-static-libgcc -static-libstdc++)

add_library(mydll SHARED dll.cpp)
add_library(mydll2 SHARED dll.cpp)

add_executable (main main.cpp)
target_link_libraries(main dl)