#include "deck.h"
#include <cstdlib> // srand
#include <ctime>   // time

Deck::Deck()
{
    createDeck();
}
void Deck::createDeck()
{
    int counter = 0;
    for (int suits = 1; suits <= 4; suits++)
        for (int num = 1; num <= 13; num++)
            deck[counter++] = new Card(num, suits);
}
Deck::~Deck()
{
    int counter = 0;
    for (int suits = 1; suits <= 4; suits++)
        for (int num = 1; num <= 13; num++)
            delete deck[counter++];
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
    int counter = 0;
    for (int suits = 1; suits <= 4; suits++)
        for (int num = 1; num <= 13; num++)
        {
            delete deck[counter];
            deck[counter++] = new Card(num, suits);
        }
    card_num = 51;
}
