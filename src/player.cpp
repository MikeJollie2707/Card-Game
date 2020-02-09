#include "player.h"

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
        /*if ((*hand[0])->getValue() > (*hand[1])->getValue())
        {
            Card** temp = hand[0];
            hand[0] = hand[1];
            hand[1] = temp;
        }*/
        // thand[0] is Node<Node<Card>*>*, thand[0]->data is Node<Card>*, thand[0]->data->data is Card.
        if (thand[0]->data->data.getValue() > thand[1]->data->data.getValue()) 
        {
            Node<Node<Card>*>* temp = thand[0];
            thand[0] = thand[1];
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
    //receiveCard(deck.drawCard());
    treceiveCard(deck.drawtCard());
}

void Player::receiveCard(Card** card)
{
    hand.push_back(card);
    sortCard();
}

void Player::treceiveCard(Node<Card>* card)
{
    thand.push_back(card);
}