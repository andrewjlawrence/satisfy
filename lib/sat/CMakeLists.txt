include_directories(./inc ${Boost_INCLUDE_DIR})
file(GLOB SAT_HEADER_FILES "./inc/*.h")
file(GLOB SAT_SOURCE_FILES "./src/*.cpp")

add_library(sat ${SAT_SOURCE_FILES} ${SAT_HEADER_FILES})

add_executable(sat_tests ./tests/main.cpp ./tests/sattest.cpp)
target_link_libraries(sat_tests sat ${Boost_LIBRARIES} )