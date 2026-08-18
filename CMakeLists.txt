cmake_minimun_required(VERSION 3.15.0)
set(project Tiger_Robot_SDK)


set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

project(${project} VERSION ${version})

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${catkin_INCLUDE_DRIS}
)

cmake
add_compile_options(-std=c++20)



