#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
    Player* players;
    unsigned short int player_num;
    unsigned short int current_player;

    Deck g_deck;

    virtual void gameRule() = 0;

    Game(unsigned short int player_num = 4);
    ~Game();
};

#endif