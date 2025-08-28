// support.h
// Header file for UI utility functions

#ifndef __UI_H__
#define __UI_H__

#include "player.h"

#include <string>

void welcome(std::string& name1, std::string& name2);
void displayScore(Player* player1, Player* player2);
void showFinalWinner(Player* player1, Player* player2);

#endif //__UI_H__