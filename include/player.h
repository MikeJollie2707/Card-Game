#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include <string>
#include <vector>

class Player
{
private:
    std::string const   name;
    std::vector<Card**> hand;

    std::vector<Card**> selected_cards; // This is for playing multiple cards such as 3-4-5-6-7-...
    unsigned short int  current_index = 0; // This is for current observe card.

    void                sortCard();
public:
    void                setIndex(unsigned short int index) { current_index = index; }

    void                drawFromDeck(Deck& deck);
    void                receiveCard(Card** const card);

    std::vector<Card**> playCard() { return selected_cards; }
    void                selectCard() { selected_cards.push_back(hand[current_index]); }

    Player(std::string name = "Player");
    ~Player();
};

#endif