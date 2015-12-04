set(FLEX_PATH "../third_party/")


file(GLOB CSOURCES *.c)
file(GLOB CPPSOURCES *.cpp)
file(GLOB HEADERS include/*)

include_directories(${HEADERS})
add_executable(Fabula ${CSOURCES} ${CPPSOURCES} ${HEADERS})
include_directories(include)