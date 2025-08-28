// player.h
// Header file for the Player class, which represents a human player

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

// Enumeration for the Player's Mark
enum Mark {
  EMPTY, X, O
};

class Player {
  private:
    // Properties
    std::string m_name;
    Mark m_mark;
    int m_gamesWon;
  
  public:
    // Constructor
    Player(std::string name, Mark mark);

    // Methods
    std::string getName();
    Mark getMark();
    void wonGame();
    int getGamesWon();
};

#endif // __PLAYER_H__