cmake_minimum_required(VERSION 3.7)

project( EmbeddingLua )

# Sub-directories where more CMakeLists.txt exist
add_subdirectory(main)
add_subdirectory(lua-5.3.4)
include_directories(lua-5.3.4)