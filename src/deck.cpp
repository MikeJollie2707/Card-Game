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

    // Shuffle 1...
    int count = 0;
    Node<Card>* start = deck.front();
    Node<Card>* end = deck.back();
    while (count < deck.size() && start != nullptr && end != nullptr)
    {
        int decision = rand() % 5;
        if (decision > 0)
            deck.swap(*start, *end);
        
        auto temp = start;
        start = end;
        end = temp;
        
        start = start->next;
        end = end->prev;
        count++;
    }

    // Shuffle 2...
    count = 0;
    start = deck.front();
    end = deck.front();
    for (int count2 = 0; count2 < deck.size(); count2++)
        end = end->next;
    
    while (end != nullptr)
    {
        int decision = rand() % 5;
        if (decision > 0)
            deck.swap(*start, *end);
        
        auto temp = start;
        start = end;
        end = temp;
        
        start = start->next;
        end = end->next;
        count++;
    }

    // Shuffle 3...
    start = deck.front();
    int decision = 0;
    while (start != nullptr)
    {
        decision = rand() % 52;
        while (start == &deck[decision])
            decision = rand() % 52;
        
        auto temp = &deck[decision];
        deck.swap(*start, deck[decision]);

        start = temp;
        start = start->next;
    }
}
void Deck::reset()
{
    deck.clear();
    createDeck();
    card_num = 51;
    total_card = 52;
}
