// main.cpp
/******************************************************************************
 * 
 *  TIC-TAC-TOE
 * 
 *  This is a game I threw together quickly since I haven't written anything in
 *  C++ in awhile. It is played between 2 human players and prompts each player
 *  which square to place their mark. Multiple Games can be played in a single
 *  Match, with the final Winner displayed at the end.
 * 
 * 
 *****************************************************************************/

#include "ui.h"
#include "game.h"

int main()
{
  // Get the names of the Players
  std::string name1, name2;
  welcome(name1, name2);

  // Construct Player Objects
  Player player1(name1, Mark::X);
  Player player2(name2, Mark::O);
  

  bool quitGame;
  // Play the Match!
  do {
    // Construct Game and Play
    Game game(&player1, &player2);
    game.playGame();
    displayScore(&player1, &player2);

    std::string userInput;
    bool invalid = false;
    // Prompt user if they want to quit
    do {
      std::cout << "Would you like to play again? (y/n)" << std::endl;
      std::cin >> userInput;

      if(userInput== "y") {
        quitGame = false;
        invalid = false;
      } else if(userInput == "n") {
        quitGame = true;
        invalid = false;
      } else {
        std:: cout << "That is an invalid input. ";
        invalid = true;
      }
    } while (invalid);
  } while (!quitGame);

  showFinalWinner(&player1, &player2);
  
  return 0;
}