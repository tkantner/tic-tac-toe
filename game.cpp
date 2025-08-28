// game.cpp
// Implementation of the Game class

#include "game.h"
#include <iostream>

// Private Methods

/************************************************************
 *
 *  @func getRowFromInput
 * 
 *  @desc Converts the user's input to a row in the board
 *  (indexed)
 * 
 *  @return The row index of the input
 * 
 ************************************************************/
int Game::getRowFromInput(const int& userInput) {
  return floor((userInput - 1)/3);
}

/************************************************************
 *
 *  @func getColFromInput
 * 
 *  @desc Converts the user's input to a column in the board
 *  (indexed)
 * 
 *  @return The column index of the input
 * 
 ************************************************************/
int Game::getColFromInput(const int& userInput) {
  return (userInput - 1) % 3;
}

/************************************************************
 *
 *  @func isInputInRange
 * 
 *  @desc Checks if the user's input is within the range of
 *  1-9.
 * 
 *  @return True if the user's input is in range, false
 *  otherwise
 * 
 ************************************************************/
bool Game::isInputInRange(const int& userInput) { 
  return (userInput > 0 && userInput < 10);
}

/************************************************************
 *
 *  @func isSquareOpen
 * 
 *  @desc Check's if the user's input (converted to row/col)
 *  selected a square that is open.
 * 
 *  @return True if the selected square is open, false 
 *  otherwise
 * 
 ************************************************************/
bool Game::isSquareOpen(const int& row, const int& col) {
  return m_board[row][col] == Mark::EMPTY;
}

/************************************************************
 *
 *  @func isInputAnInteger
 * 
 *  @desc Checks if the user's input is an integer. I didn't
 *  feel like writing this so thanks Chatgpt
 * 
 *  @return True if the user's input was an integer, false
 *  otherwise
 * 
 ************************************************************/
bool Game::isInputAnInteger(const std::string& userInput) {
    if (userInput.empty()) return false;
    size_t start = (userInput[0] == '-' || userInput[0] == '+') ? 1 : 0;
    if (start == userInput.size()) return false; // only '+' or '-'
    for (size_t i = start; i < userInput.size(); i++) {
        if (!std::isdigit(userInput[i])) return false;
    }
    return true;
}

/************************************************************
 *
 *  @func setSquare
 * 
 *  @desc Attempts to set the square that the user requested.
 *  This calls a bunch of verification methods to verify the
 *  input was actually valid.
 * 
 *  @return SquareStatus Enumeration, describing the validity
 *  of the user's input
 * 
 ************************************************************/
SquareStatus Game::setSquare(Player* player, const std::string& userInput) {
  // Declare variables
  SquareStatus status;

  // First check if this actually a numeric input
  if(isInputAnInteger(userInput)) {
    int numericInput = std::stoi(userInput); // Convert to integer
    // Then check if it's in the range of 1-9
    if(isInputInRange(numericInput)) {
      // Convert the input to a row and column (indexed)
      int row = getRowFromInput(numericInput);
      int col = getColFromInput(numericInput);

      // Next check if the square is open
      if(isSquareOpen(row, col)) {
        // If so, set the board to the player's mark (X/O)
        m_board[row][col] = player->getMark();
        status  = SquareStatus::SUCCESS;
      } else {
        status = SquareStatus::ALREADY_TAKEN;
      }
    } else {
      status = SquareStatus::OUT_OF_RANGE;
    }
  } else {
    status = SquareStatus::INVALID_CHARS;
  }
  return status;
}

/************************************************************
 *
 *  @func printBoard
 * 
 *  @desc Prints the current state of the board
 * 
 *  @return None
 * 
 ************************************************************/
void Game::printBoard() {
  std::cout << std::endl;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      switch (m_board[i][j]) {
        case Mark::X:
          std::cout << "X";
          break;
        case Mark::O:
          std::cout << "O";
          break;
        // Empty
        default:
          std::cout << (i*3) + j + 1;
          break;
      }
      // Print Vertical Bars
      std:: cout << " " << (j != 2 ? "| ":"");
    }
    // Print some newlines and horizontal lines
    std::cout << std::endl << (i != 2 ? "---------":"") << std::endl;
  }
  std::cout << std::endl;
  return;
}

/************************************************************
 *
 *  @func checkIfWinner
 * 
 *  @desc Checks if a player has won the game
 * 
 *  @return True if the current player has won, False 
 *  Otherwise
 * 
 ************************************************************/
bool Game::checkIfWinner() {

  // Check Rows
  for(int i = 0; i < 3; i++) {
    if((m_board[i][0] == m_board[i][1]) &&(m_board[i][0] == m_board[i][2]) && m_board[i][0] != Mark::EMPTY) {
      return true;
    }
  }
  
  // Check Columns
  for(int i = 0; i < 3; i++) {
    if((m_board[0][i] == m_board[1][i]) &&(m_board[0][i] == m_board[2][i]) && m_board[0][i] != Mark::EMPTY) {
      return true;
    }
  }

  // Check Diagnonals
  if ((m_board[0][0] == m_board[1][1]) &&(m_board[0][0] == m_board[2][2]) && m_board[0][0] != Mark::EMPTY) {
    return true;
  }

  if ((m_board[2][0] == m_board[1][1]) &&(m_board[2][0] == m_board[0][2]) && m_board[2][0] != Mark::EMPTY) {
    return true;
  }

  return false;
}

// Public Methods

/************************************************************
 *
 *  @func Game Constructor
 * 
 *  @desc Constructs the Game Object by setting the Player
 *  references and generating a blank board
 * 
 *  @return Initialized Game Object
 * 
 ************************************************************/
Game::Game(Player* player1, Player* player2)
  : m_player1(player1), m_player2(player2) {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        m_board[i][j] = Mark::EMPTY;
      }
    }
  }

/************************************************************
 *
 *  @func playGame
 * 
 *  @desc Main Handler for the Tic-Tac-Toe Game. Prompts the
 *  users for inputs and checks for a winner after each round.
 *
 *  @return None
 * 
 ************************************************************/
void Game::playGame() {
  // Init/declare Variables
  Player* activePlayer;
  std::string userInput = "";
  SquareStatus status;

  // 9 rounds
  for(int i = 0; i < 9; i++) {
    do {
      activePlayer = i % 2 == 0 ? m_player1:m_player2;

      // Prompt active player for input
      std::cout << std::endl << "It is " + activePlayer->getName() + "'s turn (" + (activePlayer->getMark() == Mark::X ? "X":"O")
      + "). Please enter a valid number corresponding to an open square." << std::endl;
      printBoard();
      std::cin >> userInput;

      // Attempt to set the square based on the input
      status = setSquare(activePlayer, userInput);
      // Check if the input was valid
      if(status == SquareStatus::ALREADY_TAKEN) {
        std::cout << "Silly you! That number is already taken. Please try another." << std::endl;
      } else if(status == SquareStatus::OUT_OF_RANGE) {
        std::cout << "Uh-oh! That number is out of range. Please select a value in the range of 1-9." << std::endl;
      } else if(status == SquareStatus::INVALID_CHARS) {
        std::cout << "Nope, whole numbers only!" << std::endl;
      }
      
    } while(status != SquareStatus::SUCCESS); // Loop until the user provides a valid input

    // Check if there is a winner and announce if so and end the game
    if(checkIfWinner()) {
      activePlayer->wonGame();
      std::cout << "Got 'em! " + activePlayer->getName() + " has won the game! Nice work." << std::endl;
      return;
    }
  }
  // If we made it here, no one won the game
  std::cout << "Ah, a draw! Nobody won this one." << std::endl;
  return;
}