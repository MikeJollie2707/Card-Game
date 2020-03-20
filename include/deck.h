#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "list.h"

class Deck
{
private:
    List<Card> deck;
    unsigned short int card_num = 51;
    unsigned short int total_card = 52;
public:
    // Modifiers

    /**
     * @brief Shuffle the deck.
     * 
     */
    void      shuffle();
    /**
     * @brief Create a new deck.
     * 
     * Internally, this pushes new cards to the deck, so you can actually use this to create more than 52 cards.
     * 
     */
    void      createDeck();
    /**
     * @brief Reset all the cards in the deck and generate a new one.
     * 
     * Internally, this destroy every cards, which *invalidate* any pointers to the card.
     * 
     */
    void      reset();

    // Getter of some sort

    /**
     * @brief Draw the top card.
     * 
     * @return Node<Card>* The card just drawn.
     */
    Node<Card>* drawCard() { return deck.pop_back(); }
    void putCard(Node<Card>* card) { deck.push_back(card); card_num++; }

    // Getter

    /**
     * @brief Return the number of cards left in the deck.
     * 
     * @return short int Number of cards left.
     */
    short int cardLeft() { return (card_num + 1); }

    /**
     * @brief Construct a new Deck object
     * 
     * Internally, this call `createDeck()`
     * 
     * @see createDeck()
     * 
     */
    Deck();
    ~Deck();
};

#endif