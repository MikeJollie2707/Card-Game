#include "player.h"
#include <iostream>

int main()
{
    Deck deck;
    Player player;
    player.drawFromDeck(deck);
    player.setIndex(0);
    player.tselectCard();
    List<Node<Card>*> cards = player.tplayCard();
    std::cout << cards[0] << std::endl;
    return 0;
}