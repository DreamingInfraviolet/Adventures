add_library(FabulaParser
                ${PARSER_SOURCES}
                ${PARSER_HEADERS}
                ${PARSE_NODE_SOURCES}
                ${PARSE_NODE_HEADERS}
                ${COMMON_SOURCES}
                ${COMMON_HEADERS})
include_directories(. ${PARSE_NODE_DIR})
