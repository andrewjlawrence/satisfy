project(satisfy)
cmake_minimum_required(VERSION 2.8)
SET(BOOST_ROOT "/Users/andrewlawrence/Tools/boost_1_72_0")
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework program_options REQUIRED)

set (CMAKE_CXX_STANDARD 17)

include_directories(./inc ./lib/sat/inc ${Boost_INCLUDE_DIR} ./lib/parser/inc)
add_executable(solver ./src/main.cpp )
target_link_libraries(solver ${Boost_LIBRARIES} sat parser)

add_subdirectory(lib)
