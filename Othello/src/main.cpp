// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <memory>
#include <array>

#include "CmdLineParser.h"
#include "ConsolePlayer.h"
#include "Game.h"
#include "GreedyAiPlayer.h"

using namespace std;

#define EMPTY_CHAR "-"
#define BLACK_CHAR "X"
#define WHITE_CHAR "O"

static void show_usage(std::string name)
{
    cerr << "Usage: " << name << " [OPTION]" << endl
         << endl
         << "Options:" << endl
         << "\t-h,--help\tShow this help message" << endl
         << "\t-pvc\t\t1 player" << endl
         << "\t-pvp\t\t2 players" << endl
         << "\t-cvc\t\tComputer against itself" << endl
         << endl
         << "Reversi (Othello) command line game." << endl
         << "To play the game provide 2 numbers from 1 to 8 on each move." << endl
         << "1st number is the row number." << endl
         << "2nd number is the column number." << endl
         << "3 wrong moves cause the player to skip his/her step." << endl
         << "If both players skip their steps consequently the game ends." << endl
         << endl;
}

template <typename It>
void DrawBoard(IteratorRange<It> range) {
    const string digits("12345678");

    if (range.size() != digits.size() * digits.size()) {
        cout << "ERROR: invalid size of the printed range\n";
        return;
    }

    cout << "  " << digits << "  " << "\n";
    size_t count = 0;
    for (const auto& tile : range) {
        if (count % digits.size() == 0) {
            cout << digits[count / digits.size()] << "|";
        }

        switch (tile) {
        case TileState::BLACK:
            cout << BLACK_CHAR;
            break;
        case TileState::WHITE:
            cout << WHITE_CHAR;
            break;
        case TileState::EMPTY:
            cout << EMPTY_CHAR;
            break;
        default:
            cout << "ERROR: invalid state of a tile\n";
            return;
        }
        
        if ((count + 1) % digits.size() == 0) {
            cout << "|" << digits[count / digits.size()];
            cout << "\n";
        }
        count++;
    }
    cout << "  " << digits << "  " << "\n";
}

int main(int argc, char** argv)
{
    CmdLineParser argv_parser(argc, argv);
    Game game;
    unique_ptr<PlayerIf> players[2];

    if (argc == 1 || argv_parser.checkOption("-h") || argv_parser.checkOption("--help")) {
        show_usage(argv[0]);
        return 1;
    }
    else if (argc == 2 && argv_parser.checkOption("-pvp")) {
        players[0] = make_unique<ConsolePlayer>();
        players[1] = make_unique<ConsolePlayer>();
    }
    else if (argc == 2 && argv_parser.checkOption("-pvc")) {
        players[0] = make_unique<ConsolePlayer>();
        players[1] = make_unique<GreedyAiPlayer>(game);
    }
    else if (argc == 2 && argv_parser.checkOption("-cvc")) {
        players[0] = make_unique<GreedyAiPlayer>(game);
        players[1] = make_unique<GreedyAiPlayer>(game);
    }
    else {
        show_usage(argv[0]);
        return 1;
    }

    const size_t MAX_WRONG_MOVES = 3;
    size_t move_attempts = 0;
    size_t steps = 1;

    DrawBoard(game.GetGameState());
    while (game.IsGameOver() == false) {
        cout << "(Step " << steps << ", Score " << game.GetScore()[0] << "-" << game.GetScore()[1] << ") Player " << game.GetCurPlayer() << " move: ";
        Coords move = players[game.GetCurPlayer() - 1]->GetInput();

        if (game.SetTile(move.row, move.column)) {
            cout << "\n";
            DrawBoard(game.GetGameState());
            move_attempts = 0;
            steps++;
        }
        else {
            cout << "ERROR: Illegal move\n";
            if (dynamic_cast<ConsolePlayer*>(players[game.GetCurPlayer() - 1].get())) {
                // see https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
            }

            move_attempts++;
            if (move_attempts == MAX_WRONG_MOVES) {
                game.SkipMove();
                move_attempts = 0;
                steps++;
            }
        }
    }

    if (game.GetScore()[0] == game.GetScore()[1]) {
        cout << "\nTie Game!\n";
    }
    else if (game.GetScore()[0] > game.GetScore()[1]) {
        cout << "\nPlayer 1 wins!\n";
    }
    else {
        cout << "\nPlayer 2 wins!\n";
    }
    cout << "Game Over! Live long and prosper \\V/\n";
    
    return 0;
}
