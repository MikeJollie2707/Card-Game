#include "player.h"
#include <iostream> // Debug

Player::Player(std::string playerName) : name(playerName)
{
}
Player::~Player()
{
}

void Player::sortCard()
{
    if (hand.size() == 0)
        return;

    unsigned short int start = 0;
    unsigned short int limit = hand.size() - 1;
    unsigned short int mid = 0;

    while (start < limit - 1)
    {
        mid = (limit - start) / 2 + start;
        //std::cout << start << " " << limit << " " << mid << std::endl;
        if (*(hand[hand.size() - 1]) > *(hand[mid]))
        {
            start = mid;
        }
        else if (*(hand[hand.size() - 1]) < *(hand[mid]))
        {
            limit = mid;
        }
    }

    int pos = 0;
    if (*(hand[hand.size() - 1]) > *(hand[start]) && *(hand[hand.size() - 1]) < *(hand[limit]))
    {
        pos = limit;
        for (int i = hand.size() - 2; i > pos; i--) // Ignore the last card
        {
            hand[i] = hand[i - 1];
        }
        hand[pos] = hand[hand.size() - 1];
        hand.pop_back();
    }
    else if (*(hand[hand.size() - 1]) < *(hand[start]))
    {
        pos = start;
        for (int i = hand.size() - 2; i > pos; i--) // Ignore the last card
        {
            hand[i] = hand[i - 1];
        }
        hand[pos] = hand[hand.size() - 1];
        hand.pop_back();
    }
    
}

void Player::drawFromDeck(Deck& deck)
{
    receiveCard(deck.drawCard());
}

void Player::receiveCard(Card** card)
{
    hand.push_back(card);
    sortCard();
}