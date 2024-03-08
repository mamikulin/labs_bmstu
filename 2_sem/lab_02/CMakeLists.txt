cmake_minimum_required(VERSION 3.12)

project(lab_2 VERSION 1.0.0)

add_executable(lab_2 main.cpp)

# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data.txt
#     ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_custom_command(
    TARGET lab_2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/data.txt
            ${CMAKE_CURRENT_BINARY_DIR}/data.txt)