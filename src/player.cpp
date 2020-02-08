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
    else if (hand.size() == 1)
        return;
    else if (hand.size() == 2)
    {
        if ((*hand[0])->getValue() > (*hand[1])->getValue())
        {
            Card** temp = hand[0];
            hand[0] = hand[1];
            hand[1] = temp;
        }
        return;
    }
    else
    {
        auto iter = hand.begin();
        for (iter; iter != hand.end() - 1; iter++)
        {
            if ((**iter)->getValue() > (*hand.back())->getValue())
            {
                break;
            }
        }
        if (iter != hand.end() - 1)
        {
            hand.insert(iter, hand.back());
            hand.pop_back();
        }
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