include_directories(./inc ../sat/inc ${Boost_INCLUDE_DIR})
set(PARSER_HEADER_FILES ./inc/parser.h )
add_library(parser ./src/parser.cpp ${PARSER_HEADER_FILES})
target_link_libraries(parser sat)

add_executable(parser_tests ./tests/main.cpp ./tests/parsertest.cpp)
target_link_libraries( parser_tests parser ${Boost_LIBRARIES} )