cmake_minimum_required(VERSION 3.23)
project(Files)

set(CMAKE_CXX_STANDARD 20)

file(GLOB TEST_FILES "files/*.txt")
foreach (TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_FILE_NAME "${TEST_FILE}" NAME)
    configure_file(${TEST_FILE} "${CMAKE_BINARY_DIR}/${TEST_FILE_NAME}" COPYONLY)
endforeach ()


add_executable(Files main.cpp)
