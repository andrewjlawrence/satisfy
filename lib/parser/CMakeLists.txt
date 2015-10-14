project(Parser)
include_directories(./inc)
set(HEADER_FILES ./inc/parser.h ./inc/cnf.h ./inc/clause.h ./inc/literal.h)
add_library(parser ./src/parser.cpp ./src/cnf.cpp ./src/clause.cpp ./src/literal.cpp ${HEADER_FILES})
