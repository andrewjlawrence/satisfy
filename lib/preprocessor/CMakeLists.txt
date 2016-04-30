include_directories(./inc ../sat/inc ../utility/inc ${Boost_INCLUDE_DIR})

file(GLOB PREPROCESSOR_HEADER_FILES "./inc/*.h")
file(GLOB PREPROCESSOR_SOURCE_FILES "./src/*.cpp")

add_library(preprocessor ${PREPROCESSOR_SOURCE_FILES} ${PREPROCESSOR_HEADER_FILES})
target_link_libraries(preprocessor sat utility)
