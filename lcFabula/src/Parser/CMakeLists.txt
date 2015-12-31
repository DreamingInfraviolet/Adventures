file(GLOB CSOURCES *.c)
file(GLOB CPPSOURCES *.cpp *.cc)
file(GLOB PARSE_NODE_FILES ./ParseNodes/*)
file(GLOB HEADERS *.h)

add_executable(FabulaParser ${CSOURCES} ${CPPSOURCES} ${HEADERS} ${PARSE_NODE_FILES})
include_directories(.)