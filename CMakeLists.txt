cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(pp6Homework)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
  endif()


include_directories(Modules/include Lib/include FileReader-1.0.0)

add_library(pp6Math Lib/include/pp6Math.h Lib/src/pp6Math.cpp)
add_library(pp6io Lib/include/pp6io.h Lib/src/pp6io.cpp)

#add_executable(ex cppHomework.cpp FileReader-1.0.0/FileReader.cpp Lib/src/pp6io.cpp Lib/src/pp6Math.cpp Modules/src/day1Operations.cpp Modules/src/day2Operations.cpp)
add_executable(ex cppHomework.cpp FileReader-1.0.0/FileReader.cpp Modules/src/day1Operations.cpp Modules/src/day2Operations.cpp)
target_link_libraries(ex pp6io pp6Math)


install(TARGETS ex DESTINATION bin)

include(CPack)