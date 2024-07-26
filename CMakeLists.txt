cmake_minimum_required(VERSION 3.5.0)
project(rubrick_cube VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(cube_core)
add_subdirectory(cube_core/unit_tests)

add_executable(rubrick_cube rubrick_cube.m.cpp)
target_link_libraries(rubrick_cube PUBLIC cube_core)

include(CTest)
enable_testing()

target_compile_features(rubrick_cube PUBLIC cxx_std_20)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
