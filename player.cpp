// player.cpp
// Implementation of the Player class

#include "player.h"

// Public Methods

/************************************************************
 *
 *  @func Player Constructor
 * 
 *  @desc Constructs the Player Object
 * 
 *  @return Player Object
 * 
 ************************************************************/
Player::Player(std::string name, Mark mark) 
: m_name(name), m_mark(mark), m_gamesWon(0) {}

/************************************************************
 *
 *  @func getName
 * 
 *  @desc Name Property Accessor
 * 
 *  @return The name of the Player
 * 
 ************************************************************/
std::string Player::getName() {
  return m_name; 
}

/************************************************************
 *
 *  @func getMark
 * 
 *  @desc Mark Property Accessor
 * 
 *  @return The Mark (Enum) of the Player
 * 
 ************************************************************/
Mark Player::getMark() {
  return m_mark;
}

/************************************************************
 *
 *  @func wonGame
 * 
 *  @desc Increments the number of games that the player won
 * 
 *  @return None
 * 
 ************************************************************/
void Player::wonGame() {
  m_gamesWon++;
}

/************************************************************
 *
 *  @func getGamesWon
 * 
 *  @desc Games Won Property Accessor
 * 
 *  @return The number of games the player has won
 * 
 ************************************************************/
int Player::getGamesWon() {
  return m_gamesWon;
}
