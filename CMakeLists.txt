project(satisfy)
cmake_minimum_required(VERSION 2.8)

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT  C:/Tools/x64/boost_1_59_0)
set(BOOST_INCLUDEDIR  C:/Tools/x64/boost_1_59_0)
set(BOOST_LIBRARYDIR  C:/Tools/x64/boost_1_59_0/stage/lib)
find_package(Boost COMPONENTS unit_test_framework program_options REQUIRED)

include_directories(./inc ./lib/sat/inc ${Boost_INCLUDE_DIR} ./lib/parser/inc)
add_executable(solver ./src/main.cpp )
target_link_libraries(solver ${Boost_LIBRARIES})

add_subdirectory(lib)