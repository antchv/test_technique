cmake_minimum_required(VERSION 3.10) # Version minimale de CMake

# Nom du projet
project(TestTechnique VERSION 1.0.0 LANGUAGES CXX)

# Spécifiez la version du standard C++ (par exemple C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoutez un exécutable à partir de votre code source
add_executable(TestTechnique src/main.cpp)
