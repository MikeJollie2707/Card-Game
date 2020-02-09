#include "player.h"
#include <iostream>

Player::Player(std::string playerName) : name(playerName)
{
}
Player::~Player()
{
    //thand.print();
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
            thand.swap(*thand.front(), *(thand.front()->next));
        }
        return;
    }
    else
    {
        /*auto iter = hand.begin();
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
        }*/
        thand.iter = thand.front();
        for (thand.iter; thand.iter != thand.back(); thand.iter = thand.iter->next)
        {
            if (thand.iter->data->getValue() > thand.back()->data->getValue())
                break;
        }
        thand.moveto(thand.back(), thand.iter);
        thand.iter = thand.front();
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
    //std::cout << "Previous status: " << std::endl;
    //thand.print();
    thand.push_back(&(card->data));
    //std::cout << "Current status: " << std::endl;
    //thand.print();
    sortCard();
    //std::cout << "Sort status: " << std::endl;
    //thand.print();
    //std::cout << std::endl;
}