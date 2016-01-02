
file(GLOB_RECURSE COMMON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
                                 ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
                                 ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
                                 
file(GLOB_RECURSE COMMON_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
add_subdirectory(Parser)