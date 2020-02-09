#include "player.h"
#include <iostream>

Player::Player(std::string playerName) : name(playerName)
{
}
Player::~Player()
{
    thand.iter = thand.front();
    
}

void Player::sortCard()
{
    if (thand.size() == 0)
        return;
    else if (thand.size() == 1)
        return;
    else if (thand.size() == 2)
    {
        /*if ((*hand[0])->getValue() > (*hand[1])->getValue())
        {
            Card** temp = hand[0];
            hand[0] = hand[1];
            hand[1] = temp;
        }*/
        // thand[0] is Node<Node<Card>*>*, thand[0]->data is Node<Card>*, thand[0]->data->data is Card.
        if (thand[0].data->getValue() > thand[1].data->getValue()) 
        {
            /*Node<Card*> temp = thand[0];
            std::cout << "First card value: " << std::endl;
            std::cout << temp.data->getValue() << std::endl << std::endl;
            std::cout << thand[1].data->getValue() << std::endl << std::endl;
            thand[0] = thand[1];
            std::cout << thand[0].data->getValue() << std::endl << std::endl;
            std::cout << thand[1].data->getValue() << std::endl << std::endl;
            std::cout << "Cause seg fault?" << std::endl;
            thand[1] = temp;*/
            swap(thand[0], thand[1]);
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
    thand.push_back(&(card->data));
    sortCard();
}