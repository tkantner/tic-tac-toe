// game.h
// Header File for the Game Class, which maintains the instance of the game

#ifndef __GAME_H__
#define __GAME_H__

#include "player.h"

#include <iostream>

// Enumeration for the state of a user's selection
enum SquareStatus {
  SUCCESS, INVALID_CHARS, OUT_OF_RANGE, ALREADY_TAKEN
};

class Game {
  private:
    // Properties
    Player* m_player1, *m_player2; // The references to the Players
    Mark m_board[3][3];

    // Methods
    SquareStatus setSquare(Player* player, const std::string& userInput);
    int getRowFromInput(const int& userInput);
    int getColFromInput(const int& userInput);
    bool isInputInRange(const int& userInput);
    bool isSquareOpen(const int& row, const int& col);
    bool isInputAnInteger(const std::string& userInput);
    bool checkIfWinner();
    void printBoard();
  public:
    // Constructor
    Game(Player* player1, Player* player2);

    // Methods
    void playGame();
};   

#endif // __GAME_H__