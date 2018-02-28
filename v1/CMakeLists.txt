cmake_minimum_required(VERSION 3.9)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ls ft_ls.c litt_big_r.c little_r.c pre.c )

target_link_libraries(ft_ls ${CMAKE_SOURCE_DIR})