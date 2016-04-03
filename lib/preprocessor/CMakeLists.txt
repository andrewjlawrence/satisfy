include_directories(./inc ../sat/inc ${Boost_INCLUDE_DIR})
set(PREPROCESSOR_HEADER_FILES ./inc/preprocessor.h )
add_library(preprocessor ./src/preprocessor.cpp ${PREPROCESSOR_HEADER_FILES})
target_link_libraries(preprocessor sat)
