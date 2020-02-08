#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck
{
private:
    Card*     deck[52];
    short int card_num = 51;
public:
    // Modifiers

    void      shuffle();
    void      createDeck();
    void      reset();

    // Getter of some sort

    Card** const   drawCard() { return &deck[card_num--]; }
    void      putCard(Card** const card) { card_num++; } // Optional, depends on which game.

    // Getter

    short int numCard() { return card_num; }

    Deck(); // Call createDeck internally.
    ~Deck();
};

#endif