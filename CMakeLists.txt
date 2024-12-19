cmake_minimum_required(VERSION 3.10) # Version minimale de CMake

# Nom du projet
project(TestTechnique VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TestTechnique_couleur src/couleur.cpp)
add_executable(TestTechnique_image src/image.cpp)
add_executable(TestTechnique_sort src/sort.cpp)
