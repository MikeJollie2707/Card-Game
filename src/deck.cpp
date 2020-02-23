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
    /*int start = 0;
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
    }*/
    //deck.print();

    deck.print();
    int count = 0;
    Node<Card>* start = deck.front();
    Node<Card>* end = deck.back();
    while (count < deck.size() && start != nullptr && end != nullptr)
    {
        int decision = rand() % 2;
        if (decision)
            deck.swap2(*start, *end);
        
        start = start->next;
        end = end->prev;
        count++;
    }
    deck.print();

    count = 0;
    start = deck.front();
    end = deck.front();
    for (int count2 = 0; count2 < deck.size(); count2++)
        end = end->next;
    
    while (end != nullptr)
    {
        int decision = rand() % 3;
        if (decision)
            deck.swap2(*start, *end);
        
        start = start->next;
        end = end->next;
        count++;
    }
}
void Deck::reset()
{
    deck.clear();
    createDeck();
    card_num = 51;
    total_card = 52;
}
