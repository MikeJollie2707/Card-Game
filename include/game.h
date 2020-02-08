#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
    Player* players;
    Deck g_deck;

    Game(unsigned short int player_num = 4);
};

#endif