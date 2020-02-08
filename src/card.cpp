#include "card.h"
#include <stdexcept>

Card::Card(unsigned short int num, unsigned short int suit)
{
    unsigned short static int counter = 0;
    if (num < 0 || num > 13) 
        throw std::invalid_argument("'num' must between 1 and 13, with 1 as A, 11 as J and 13 as K.");
    else
        this->num = num;
    
    if (suit < 0 || suit > 4)
        throw std::invalid_argument("'suit' must between 1 and 4, with 1 as spades and 4 as hearts.");
    else
        this->suit = suit;
    
    value = ++counter;
}