#include "player.h"
#include <iostream>

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
        if (hand[0].data->getValue() > hand[1].data->getValue()) 
        {
            hand.swap(*hand.front(), *(hand.front()->next));
        }
        return;
    }
    else
    {
        hand.iter = hand.front();
        for (hand.iter; hand.iter != hand.back(); hand.iter = hand.iter->next)
        {
            if (hand.iter->data->getValue() > hand.back()->data->getValue())
                break;
        }
        hand.moveto(hand.back(), hand.iter);
        hand.iter = hand.front();
    }
}

void Player::drawFromDeck(Deck& deck)
{
    receiveCard(deck.drawCard());
}

void Player::receiveCard(Node<Card>* card)
{
    hand.push_back(&(card->data));
    sortCard();
}