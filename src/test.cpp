#include "player.h"
#include <iostream>

int main()
{
    Deck deck;
    deck.shuffle();
    
    Player player;
    int times = 6;
    std::cout << "Card drown: " << std::endl;
    for (int i = 0; i < times; i++)
    {
        Node<Card>* card = deck.drawtCard();
        std::cout << card->data.getNumber() << " " << card->data.getSuit() << " " << card->data.getValue();
        std::cout << std::endl;
        player.treceiveCard(card);
    }
    //player.print();
    std::cout << "Retrieving cards..." << std::endl;
    for (int i = 0; i < times; i++)
    {
        player.setIndex(i);
        player.tselectCard();
        //player.print();
    }
    List<Card*> cards = player.tplayCard();
    std::cout << cards.size() << std::endl;
    std::cout << "Hand: " << std::endl;
    for (int i = 0; i < times; i++)
    {
        std::cout << cards[i].data->getNumber() << " " << cards[i].data->getSuit() << " " << cards[i].data->getValue();
        std::cout << std::endl;
    }
    //cards.print();
    //std::cout << std::endl;


    return 0;
}