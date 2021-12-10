# CMakeList.txt : CMake project for Othello, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)


# Add source to this project's executable.
set(Sources "main.cpp" "Game.h" "Game.cpp" "IteratorRange.h" "PlayerIf.h" "ConsolePlayer.h" "GreedyAiPlayer.h" "GreedyAiPlayer.cpp" "CmdLineParser.h" "CmdLineParser.cpp")
add_executable (Othello ${Sources})
add_library(OthelloLib STATIC ${Sources})

# TODO: Add tests and install targets if needed.
