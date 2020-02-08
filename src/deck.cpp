#include "deck.h"
#include <cstdlib> // srand
#include <ctime>   // time

Deck::Deck()
{
    createDeck();
}
void Deck::createDeck()
{
    for (int suits = 1; suits <= 4; suits++)
        for (int num = 1; num <= 13; num++)
            deck[num * suits - 1] = new Card(num, suits);
}
Deck::~Deck()
{
    for (int suits = 1; suits <= 4; suits++)
        for (int num = 1; num <= 13; num++)
            delete deck[num * suits - 1];
}
void Deck::shuffle()
{
    srand(time(NULL));

    int start = 0;
    int mobile = card_num - 1;

    while (start < 52)
    {
        do
            mobile = rand() % 52;
        while (mobile == start);

        Card* pCard = deck[mobile];
        deck[mobile] = deck[start];
        deck[start] = pCard;

        start++;
    }
}
void Deck::reset()
{
    for (int suits = 1; suits <= 4; suits++)
        for (int num = 1; num <= 13; num++)
        {
            delete deck[num * suits - 1];
            deck[num * suits - 1] = new Card(num, suits);
        }
    card_num = 51;
}
