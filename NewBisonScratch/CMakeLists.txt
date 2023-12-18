project(simple-test)
cmake_minimum_required(VERSION 3.18)
enable_language(CXX)
set (CMAKE_CXX_STANDARD 11)
set(BISON_EXECUTABLE "/usr/local/Cellar/bison/3.8.2/bin/bison" CACHE PATH "Bison executable")
find_package(BISON)
BISON_TARGET(MyParser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.h)
 include_directories(${CMAKE_CURRENT_BINARY_DIR})
 add_executable(simple-test
    ${BISON_MyParser_OUTPUTS}
 )
target_include_directories(simple-test PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
