               
set(COMMON_DIR                                     ${CMAKE_CURRENT_SOURCE_DIR}/common/)
set(PARSE_NODE_DIR                                 ${CMAKE_CURRENT_SOURCE_DIR}/parseNodes/)
set(PARSER_DIR                                     ${CMAKE_CURRENT_SOURCE_DIR}/Parser/)
set(PARSER_CMD_DIR                                 ${CMAKE_CURRENT_SOURCE_DIR}/ParserCommandLine/)
set(INTERFACE_HTML_DIR                             ${CMAKE_CURRENT_SOURCE_DIR}/HTMLGeneratorInterface/)
                   
file(GLOB    COMMON_SOURCES                        ${COMMON_DIR}/*.cpp
                                                   ${COMMON_DIR}/*.cc
                                                   ${COMMON_DIR}/*.c)
file(GLOB    COMMON_HEADERS                        ${COMMON_DIR}/*.h
                                                   ${COMMON_DIR}/*.hpp)
                   
file(GLOB    PARSE_NODE_SOURCES                    ${PARSE_NODE_DIR}/*.cpp
                                                   ${PARSE_NODE_DIR}/*.cc
                                                   ${PARSE_NODE_DIR}/*.c)
file(GLOB    PARSE_NODE_HEADERS                    ${PARSE_NODE_DIR}/*.h
                                                   ${PARSE_NODE_DIR}/*.hpp)
                   
file(GLOB    PARSER_SOURCES                        ${PARSER_DIR}/*.cpp
                                                   ${PARSER_DIR}/*.cc
                                                   ${PARSER_DIR}/*.c)
file(GLOB    PARSER_HEADERS                        ${PARSER_DIR}/*.h
                                                   ${PARSER_DIR}/*.hpp)
                   
file(GLOB    PARSER_CMD_SOURCES                    ${PARSER_CMD_DIR}/*.cpp
                                                   ${PARSER_CMD_DIR}/*.cc
                                                   ${PARSER_CMD_DIR}/*.c)
file(GLOB    PARSER_CMD_HEADERS                    ${PARSER_CMD_DIR}/*.h
                                                   ${PARSER_CMD_DIR}/*.hpp)
               
file(GLOB    INTERFACE_HTML_SOURCES                ${INTERFACE_HTML_DIR}/*.cpp
                                                   ${INTERFACE_HTML_DIR}/*.cc
                                                   ${INTERFACE_HTML_DIR}/*.c)
file(GLOB    INTERFACE_HTML_HEADERS                ${INTERFACE_HTML_DIR}/*.h
                                                   ${INTERFACE_HTML_DIR}/*.hpp)

find_package(Boost REQUIRED program_options)

set(PSC_TEST_SOURCES parametrised_string_constructor_test.cpp)
set(PSC_TEST_HEADERS parametrised_string_constructor.h)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
add_subdirectory(Parser)
add_subdirectory(ParserCommandLine)
add_subdirectory(HTMLGeneratorInterface)
