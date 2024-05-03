cmake_minimum_required(VERSION 3.23)

set(project "lab_02")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(planet)
add_subdirectory(team)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})


target_link_libraries(${project} planet)
target_link_libraries(${project} team)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

