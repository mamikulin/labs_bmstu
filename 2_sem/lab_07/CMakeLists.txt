cmake_minimum_required(VERSION 3.23)

set(project "lab_07")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)


add_subdirectory(product)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} product)