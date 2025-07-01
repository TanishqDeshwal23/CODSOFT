#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE "pause"
#else
    #define CLEAR "clear"
    #define PAUSE "read -n 1 -s -r -p \"Press any key to continue...\""
#endif

char board[3][3];
char player;

void slowPrint(std::string text, int delay = 40) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void letsPlay() {
    system(CLEAR);

    std::cout << R"(
  _____ _      _____            _____
 |_   _(_) ___|_   _|__   ___  |_   _|__   ___
   | | | |/ __|| |/ _ \ / _ \   | |/ _ \ / _ \
   | | | | (__ | | (_) |  __/   | | (_) |  __/
   |_| |_|\___||_|\___/ \___|   |_|\___/ \___|

)";
    std::cout << "\n🎮 Welcome to the Ultimate Tic-Tac-Toe Challenge! 🎮\n\n";

    slowPrint("🧠 Two players take turns...\n");
    slowPrint("❌ Player 1 is 'X'\n");
    slowPrint("⭕ Player 2 is 'O'\n");
    slowPrint("🎯 Choose a number (1-9) to mark your spot on the board\n");
    slowPrint("🏁 First to align 3 in a row, column, or diagonal wins!\n");
    slowPrint("🤝 If the board is full with no winner, it's a draw!\n");

    std::cout << "\n⌛ Loading game...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void resetBoard() {
    char val = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = val++;
}

void printBoard() {
    system(CLEAR);
    std::cout << "\n   Let's play Tic-Tac-Toe!\n";
    std::cout << "\n     Player 1: X    Player 2: O\n\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "       ";
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "      ---+---+---\n";
    }
    std::cout << "\n";
}

bool isMoveValid(int move) {
    if (move < 1 || move > 9) return false;
    int r = (move - 1) / 3;
    int c = (move - 1) % 3;
    return board[r][c] != 'X' && board[r][c] != 'O';
}

void makeMove(int move) {
    int r = (move - 1) / 3;
    int c = (move - 1) % 3;
    board[r][c] = player;
}

bool checkWin() {
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

void playGame() {
    int move;
    player = 'X';
    resetBoard();

    while (true) {
        printBoard();
        std::cout << "   Player " << player << ", enter your move (1-9): ";
        std::cin >> move;

        if (!std::cin || !isMoveValid(move)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "   🚫 Invalid move. Try again!\n";
            system(PAUSE);
            continue;
        }

        makeMove(move);

        if (checkWin()) {
            printBoard();
            std::cout << "   🎉 Player " << player << " WINS! 🏆\n";
            break;
        }

        if (checkDraw()) {
            printBoard();
            std::cout << "   🤝 It's a DRAW!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    letsPlay();  // 🎬 Game introduction
    char choice;
    do {
        playGame();
        std::cout << "\n   🔁 Play again? (y/n): ";
        std::cin >> choice;
        choice = std::tolower(choice);
    } while (choice == 'y');

    std::cout << "\n   👋 Thanks for playing! See you next time!\n";
    return 0;
}
