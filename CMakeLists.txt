cmake_minimum_required(VERSION 3.7)

project( EmbeddingLua )

add_subdirectory(main)
add_subdirectory(lua-5.3.4)
include_directories(lua-5.3.4)
