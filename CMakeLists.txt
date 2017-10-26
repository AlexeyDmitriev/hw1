project(qt-cmake-project)
cmake_minimum_required(VERSION 3.0)
find_package(Qt5 COMPONENTS Core Widgets)

find_package(PythonLibs 3.4)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${PYTHON_INCLUDE_DIRS})

set (CMAKE_CXX_STANDARD 11)

add_executable(test1 test1.c)
add_executable(test2 test2.c)

add_library(clib SHARED lib.cpp)

target_link_libraries(clib
    ${Qt5Core_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${PYTHON_LIBRARIES}
)

target_link_libraries(test1 clib)
target_link_libraries(test2 clib)

python_add_module(
    _pywidgets
    pymodule.cpp
)

target_link_libraries(_pywidgets
    clib
)
