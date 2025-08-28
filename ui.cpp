// ui.cpp
// Utility Functions for the UI
#include "ui.h"
#include "player.h"

#include <iostream>
#include <chrono>
#include <thread>

/************************************************************
 *
 *  @func welcome
 * 
 *  @desc Welcomes the users to the game and prompts for their
 *  names. These will be used to construct the Player Objects
 * 
 *  @return None
 * 
 ************************************************************/
void welcome(std::string& name1, std::string& name2){

  // Get Names
  std::cout << "Welcome to Tic Tac Toe!" << std::endl;
  std::cout << "What is Player 1's name?" << std::endl;
  std::getline(std::cin, name1);
  std::cout << "Welcome, " + name1 + "! That is a wonderful name." << std::endl << std::endl;

  std::cout << "And what is Player 2's name?" << std::endl;
  std:: cin >> name2;
  std::cout << "Welcome, " + name2 + "! That is a great name as well." << std::endl << std::endl;

  // Pump the players up
  std::cout << "Get Ready to play..." << std::endl << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "TIC" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "TAC" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "TOE!!" << std::endl;
}

/************************************************************
 *
 *  @func displayScore
 * 
 *  @desc Displays the  number of games won in the match so
 *  far
 * 
 *  @return None
 * 
 ************************************************************/
void displayScore(Player* player1, Player* player2) {
  std::cout << "The Score is now:" << std::endl;
  std::cout << player1->getName() + ": " << player1->getGamesWon() << std::endl;
  std::cout << player2->getName() + ": " << player2->getGamesWon() << std::endl;
  return;
}

/************************************************************
 *
 *  @func showFinalWinner
 * 
 *  @desc Shows the final score of the match and determines
 *  who won the match
 * 
 *  @return None
 * 
 ************************************************************/
void showFinalWinner(Player* player1, Player* player2) {
  Player* winner;
  Player* loser;

  // Check who won and who lost
  if(player1->getGamesWon() == player2->getGamesWon()) {
    std::cout << "A draw! Nobody wins. Or nobody loses?" << std::endl;
    return;
  } else if(player1->getGamesWon() > player2->getGamesWon()) {
    winner = player1;
    loser = player2;
  } else {
    winner = player2;
    loser = player1;
  }

  std::cout << "Congrats, " + winner->getName() + "! You have won the match. Better luck next time, " + loser->getName() + "." << std::endl;
  return;
}