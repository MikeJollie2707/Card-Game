#include "deck.h"
#include <cstdlib> // srand
#include <ctime>   // time
#include <iostream>

Deck::Deck()
{
    createDeck();
}
void Deck::createDeck()
{
    for (int num = 1; num <= 13; num++)
        for (int suits = 1; suits <= 4; suits++)
            deck.push_back(Card(num, suits));
}
Deck::~Deck()
{
}
void Deck::shuffle()
{
    srand(time(NULL));
    int start = 0;
    int mobile = 0;
    //deck.print();
    while (start < 52)
    {
        do
            mobile = rand() % 52;
        while (mobile == start);

        std::cout << "Swap at " << start << " " << mobile << std::endl;
        deck.swap(deck[start], deck[mobile]);
        start++;
    }
    //deck.print();
}
void Deck::reset()
{
    deck.clear();
    createDeck();
    card_num = 51;
    total_card = 52;
}
