# CMakeList.txt : CMake project for Othello, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


# Add source to this project's executable.
add_executable (Othello "main.cpp"  "Game.h" "Game.cpp" "IteratorRange.h" "PlayerIf.h" "ConsolePlayer.h" "GreedyAiPlayer.h" "GreedyAiPlayer.cpp" "CmdLineParser.h" "CmdLineParser.cpp")
target_compile_features(Othello PRIVATE cxx_std_20)

# TODO: Add tests and install targets if needed.
