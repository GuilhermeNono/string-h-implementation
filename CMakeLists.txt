cmake_minimum_required(VERSION 4.2)
project(string_proj C)

set(CMAKE_C_STANDARD 23)

if(MSVC)
    add_compile_options(/W4 /WX)
else ()
    add_compile_options(-Wall -Wextra -pedantic)
endif ()

add_executable(proj main.c include/my_string.c
        include/my_string.h)
