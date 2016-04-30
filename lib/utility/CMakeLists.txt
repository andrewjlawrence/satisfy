include_directories(./inc ${Boost_INCLUDE_DIR})
set(UTILITY_HEADERFILES ./inc/parforeach.h ./inc/threadgroup.h)
add_library(utility ./src/threadgroup.cpp ${UTILITY_HEADERFILES})

add_executable(utility-tests ./tests/main.cpp )
target_link_libraries(utility-tests utility ${Boost_LIBRARIES} )