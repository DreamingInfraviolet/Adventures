file(GLOB CSOURCES *.c)
file(GLOB CPPSOURCES *.cpp *.cc)
file(GLOB HEADERS *.h)

add_executable(FabulaParser ${CSOURCES} ${CPPSOURCES} ${HEADERS} ${COMMON_SOURCES} ${COMMON_HEADERS})
include_directories(.)