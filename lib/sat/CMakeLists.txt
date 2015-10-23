include_directories(./inc ${Boost_INCLUDE_DIR})
set(SAT_HEADER_FILES ./inc/cnf.h ./inc/clause.h ./inc/literal.h ./inc/dpll.h)
add_library(sat ./src/cnf.cpp ./src/clause.cpp ./src/literal.cpp ./src/dpll.cpp ${SAT_HEADER_FILES})
