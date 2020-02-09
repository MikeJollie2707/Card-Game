#include "player.h"
#include <iostream>

int main()
{
    Deck deck;
    Player player;
    int times = 2;
    std::cout << "Card drown: " << std::endl;
    for (int i = 0; i < times; i++)
    {
        Node<Card>* card = deck.drawtCard();
        std::cout << card->data.getNumber() << " " << card->data.getSuit() << " " << card->data.getValue();
        std::cout << std::endl;
        player.treceiveCard(card);
        player.setIndex(i);
        std::cout << "Ok boomer\n";
        player.tselectCard();
        std::cout << "Seg fault?\n";
        
    }
    List<Card*> cards = player.tplayCard();
    std::cout << "Hand: " << std::endl;
    for (int i = 0; i < times; i++)
    {
        std::cout << cards[i].data->getNumber() << " " << cards[i].data->getSuit() << " " << cards[i].data->getValue();
        std::cout << std:: endl;
    }

    return 0;
}