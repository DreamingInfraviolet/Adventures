set(CMAKE_PREFIX_PATH C:/Users/light/Downloads/opencv/sources/build/ ${CMAKE_PREFIX_PATH})

file(GLOB CPPSOURCES *.cpp)
file(GLOB HEADERS include/*)

find_package( OpenCV REQUIRED )

include_directories(include/)
include_directories(C:/Users/light/Downloads/opencv/sources/build/install/include)

add_executable(SensorySubstitution ${CPPSOURCES} ${HEADERS})

target_link_libraries( SensorySubstitution  ${OpenCV_LIBS} )