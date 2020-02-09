#include "deck.h"
#include <cstdlib> // srand
#include <ctime>   // time

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
    /*int counter = 0;
    for (int num = 1; num <= 13; num++)
        for (int suits = 1; suits <= 4; suits++)
            delete d_deck[counter++];*/
}
void Deck::shuffle()
{
    srand(time(NULL));

    /*int start = 0;
    int mobile = card_num - 1;

    while (start < 52)
    {
        do
            mobile = rand() % 52;
        while (mobile == start);

        Card* pCard = d_deck[mobile];
        d_deck[mobile] = d_deck[start];
        d_deck[start] = pCard;

        start++;
    }*/
    Node<Card>* dfront = deck.front();
    Node<Card>* dback = deck.back();
}
void Deck::reset()
{
    deck.clear();
    createDeck();
    card_num = 51;
    total_card = 52;
}
