#include "player.h"
#include <iostream>

int main()
{
    Deck deck;
    deck.shuffle();

    Player player("MikeJollie");
    int times = 4;
    for (int i = 0; i < times; i++)
    {
        Card** draw = deck.drawCard();
        std::cout << (*draw)->getNumber() << " " << (*draw)->getSuit() << " " << (*draw)->getValue();
        std::cout << std::endl;
        player.receiveCard(draw);
    }
    std::cout << "\n\n\n";
    for (int i = 0; i < times; i++)
    {
        player.setIndex(i);
        player.selectCard();
    }
    
    std::vector<Card**> cards = player.playCard();

    for (int i = 0; i < times; i++)
    {
        std::cout << (*(cards[i]))->getNumber() << " " << (*(cards[i]))->getSuit() << " " << (*(cards[i]))->getValue();
        std::cout << std::endl;
    }

    return 0;
}