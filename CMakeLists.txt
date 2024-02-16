cmake_minimum_required(VERSION 3.27)
project(transport)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Eigen on Windows
set(EIGEN3_INCLUDE_DIR "$ENV{EIGEN3_INCLUDE_DIR}")
set(CMAKE_MODULE_PATH "$ENV{EIGEN3_DIR}")
find_package(Eigen3 3.4 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(FVM_SOURCE
        src/fvm/Node.cpp
        src/fvm/Node.h
        src/fvm/Mesh.cpp
        src/fvm/Mesh.h
        src/fvm/Face.cpp
        src/fvm/Face.h
        src/fvm/Cell.cpp
        src/fvm/Cell.h
        src/fvm/Discretization.cpp
        src/fvm/Discretization.h
        src/io/write_vtk.h
)

add_executable(transport src/main.cpp ${FVM_SOURCE})

include_directories(src)

enable_testing()
add_executable(
        square_ortho_2x2_mesh_test
        test/square_ortho_2x2_mesh_test.cpp
        ${FVM_SOURCE}
)
target_link_libraries(
        square_ortho_2x2_mesh_test
        GTest::gtest_main
)
add_executable(
        square_ortho_20x20_mesh_test
        test/square_ortho_20x20_mesh_test.cpp
        ${FVM_SOURCE}
)
target_link_libraries(
        square_ortho_20x20_mesh_test
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(
        square_ortho_2x2_mesh_test
        square_ortho_20x20_mesh_test
)
