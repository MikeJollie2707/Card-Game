#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "list.h"

class Deck
{
private:
    List<Card> deck;
    Card* d_deck[52];
    unsigned short int card_num = 51;
    unsigned short int total_card = 52;
public:
    // Modifiers

    void      shuffle();
    void      createDeck();
    void      reset();

    // Getter of some sort

    Card**    drawCard() { return &d_deck[card_num--]; }
    Node<Card>* drawtCard() { return deck.pop_back(); }
    void      putCard(Card** card) { card_num++; } // Optional, depends on which game.

    // Getter

    short int cardLeft() { return (card_num + 1); }

    Deck(); // Call createDeck internally.
    ~Deck();
};

#endif