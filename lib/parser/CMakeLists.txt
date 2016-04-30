include_directories(./inc ../sat/inc ${Boost_INCLUDE_DIR})

file(GLOB PARSER_HEADER_FILES "./inc/*.h")
file(GLOB PARSER_SOURCE_FILES "./src/*.cpp")

add_library(parser ${PARSER_SOURCE_FILES} ${PARSER_HEADER_FILES})
target_link_libraries(parser sat)

add_executable(parser_tests ./tests/main.cpp ./tests/parsertest.cpp)
target_link_libraries( parser_tests parser ${Boost_LIBRARIES} )