#include "player.h"

Player::Player(std::string playerName) : name(playerName)
{
}

void Player::sortCard()
{
    unsigned short int start = 0;
    unsigned short int limit = hand.size();
    unsigned short int mid = 0;

    while (abs(limit - start) == 1 || limit == start)
    {
        mid = (limit - start) / 2 + start;
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
        pos = limit;
    
}

void Player::drawFromDeck(Deck& deck)
{
    receiveCard(deck.drawCard());
}

void Player::receiveCard(Card** const card)
{
    hand.push_back(card);
    sortCard();
}