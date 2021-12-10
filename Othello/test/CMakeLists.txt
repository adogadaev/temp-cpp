# CMakeList.txt : CMake project for Othello Unit-tests.
#
cmake_minimum_required (VERSION 3.20)

set(This OthelloTests)

add_executable(${This} "othello_tests.cpp")
target_link_libraries(${This} PUBLIC gtest_main OthelloLib)

add_test(
    NAME ${This}
    COMMAND ${This}
)
