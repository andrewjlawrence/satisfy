include_directories(./inc ${Boost_INCLUDE_DIR})
file(GLOB UTILITY_HEADER_FILES "./inc/*.h")
file(GLOB UTILITY_SOURCE_FILES "./src/*.cpp")

add_library(utility ${UTILITY_SOURCE_FILES} ${UTILITY_HEADER_FILES})

add_executable(utility-tests ./tests/main.cpp )
target_link_libraries(utility-tests utility ${Boost_LIBRARIES} )