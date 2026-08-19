cmake_minimum_required(VERSION 3.15.0)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

project(Tiger_Robot_SDK VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# headers are included flat (e.g. <robot.hpp>, <mission.hpp>), so every
# module folder under include/ has to be on the include path, not just include/ itself
file(GLOB SDK_MODULE_DIRS ${PROJECT_SOURCE_DIR}/include/*)
set(SDK_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
foreach(dir ${SDK_MODULE_DIRS})
  if(IS_DIRECTORY ${dir})
    list(APPEND SDK_INCLUDE_DIRS ${dir})
  endif()
endforeach()

file(GLOB_RECURSE SDK_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(tiger_robot_sdk STATIC ${SDK_SOURCES})
target_include_directories(tiger_robot_sdk PUBLIC ${SDK_INCLUDE_DIRS})

# every .cpp under examples/ is its own standalone test program
file(GLOB_RECURSE SDK_EXAMPLE_SOURCES ${PROJECT_SOURCE_DIR}/examples/*.cpp)
foreach(example_src ${SDK_EXAMPLE_SOURCES})
  get_filename_component(example_name ${example_src} NAME_WE)
  add_executable(${example_name} ${example_src})
  target_link_libraries(${example_name} PRIVATE tiger_robot_sdk)
endforeach()
