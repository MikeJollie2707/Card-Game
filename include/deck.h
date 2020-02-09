#ifndef DECK_H
#define DECK_H

#include "card.h"

/*
Brief explanation about Deck.
The internal deck is Card** because first it's a dynamic array (so you can dispose the deck easily)
Each element in d_deck is also a pointer to a Card (again, so you can dispose the card easily)

You can however, just use a Card* and each elements will be an instance, which is less crap to deal with.
But because the strict nature of Card (which is read-only), you can't really init a Card* d_deck.

card_num refers to the top card of the deck. If someone draw the card, it'll return the Card** at that position,
and then decrease card_num.
*/

class Deck
{
private:
    /**
     * @brief Internal deck.
     * 
     */
    Card*    d_deck[52];
    /**
     * @brief Maximum number of cards.
     *        Adjust this depends on your game.
     * 
     */
    short int total_card = 52;
    /**
     * @brief Unsure...
     * 
     */
    short int card_num = 51;
public:
    // Modifiers

    void      shuffle();
    void      createDeck();
    void      reset();

    // Getter of some sort

    Card**    drawCard() { return &d_deck[card_num--]; }
    void      putCard(Card** card) { card_num++; } // Optional, depends on which game.

    // Getter

    short int cardLeft() { return (card_num + 1); }

    Deck(); // Call createDeck internally.
    ~Deck();
};

#endif