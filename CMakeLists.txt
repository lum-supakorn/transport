cmake_minimum_required(VERSION 3.27)
project(transport)

set(CMAKE_CXX_STANDARD 20)

add_executable(transport src/main.cpp
        src/fvm/Node.cpp
        src/fvm/Node.h
        src/fvm/Mesh.cpp
        src/fvm/Mesh.h
        src/fvm/Face.cpp
        src/fvm/Face.h
        src/fvm/Cell.cpp
        src/fvm/Cell.h
)
