cmake_minimum_required(VERSION 3.12)
project(trade-category)

add_definitions(-std=c++17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SRCS src/main.cpp)
include_directories(src)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

set(UNIT_SRCS 
    test/main.cpp
    test/TestTrade.cpp
)
add_executable(${PROJECT_NAME}-test ${UNIT_SRCS}) 
target_link_libraries(${PROJECT_NAME}-test ${CONAN_LIBS})
