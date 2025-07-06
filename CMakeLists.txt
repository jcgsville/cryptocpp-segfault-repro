cmake_minimum_required(VERSION 3.28)
project(cryptocpp-segfault-repro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CRYPTOPP_DISABLE_ASM ON CACHE BOOL "Disable cryptopp assembly optimizations - results in segfault")
set(CRYPTOPP_BUILD_TESTING OFF CACHE BOOL "Disable building cryptopp tests")

add_subdirectory(${CMAKE_SOURCE_DIR}/cryptopp-cmake)

add_executable(repro repro.cpp)
target_link_libraries(repro cryptopp)
