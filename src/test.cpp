#include "player.h"
#include <iostream>

int main()
{
    Deck deck;
    while (deck.numCard() >= 0)
    {
        Card** card = deck.drawCard();
        std::cout << (*card)->getNumber() << " " << (*card)->getSuit() << " " << (*card)->getValue();
        std::cout << std::endl;
    }
    return 0;
}