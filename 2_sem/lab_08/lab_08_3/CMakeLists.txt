cmake_minimum_required(VERSION 3.23)

set(project "3")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        third.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/a_third.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/b_third.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

    