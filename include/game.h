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

    // After inherit Card, pass the card object to the pointer for the deck to play with that deck.
    // Should change Deck to Deck<T>
    Game(Card* card_type, unsigned short int player_num = 4);
    ~Game();
};

#endif