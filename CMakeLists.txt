cmake_minimum_required(VERSION 3.16)
project (TestGCC)

if(UNIX)
    add_link_options(-static-libgcc -static-libstdc++)
endif()

add_library(mydll SHARED dll.cpp)
add_library(mydll2 SHARED dll.cpp)
target_compile_definitions(mydll PRIVATE "FILE_NAME=\"dll\"")
target_compile_definitions(mydll2 PRIVATE "FILE_NAME=\"dll2\"")
add_executable (main main.cpp)
target_link_libraries(main dl)