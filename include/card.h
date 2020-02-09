#ifndef CARD_H
#define CARD_H

//enum suit = { hearts, diamonds, clubs, spades };

int const spades = 1;
int const clubs = 2;
int const diamonds = 3;
int const hearts = 4;

class Card
{
private:
    /**
     * @brief The number of the card.
     *        In standard card, this should range from 1 to 13, with 1 as A, 11 as J, 12 as Q and 13 as K.
     */
    unsigned short int num = 0;
    /**
     * @brief The suit of the card.
     *        In standard card, this should range from 1 to 4. Recommend using spades, clubs, diamonds and hearts.
     *        In UNO, this is the color of the card.
     */
    unsigned short int suit = 0;
    /**
     * @brief The value of the card.
     *        In Tien Len for example, spades<clubs<diamonds<hearts, 3<4<5<6<7<8<9<10<J<Q<K<A<2.
     */
    unsigned short int value = 0;
public:
    // Getters

    unsigned short int getNumber() { return num; }
    unsigned short int getSuit() { return suit; }
    unsigned short int getValue() { return value; }

    // Operations

    friend bool operator> (Card const& first, Card const& second) { return (first.value >  second.value); }
    friend bool operator==(Card const& first, Card const& second) { return (first.value == second.value); }
    friend bool operator< (Card const& first, Card const& second) { return (first.value <  second.value); }
    friend bool operator!=(Card const& first, Card const& second) { return (first.value != second.value); }

    /**
     * @brief Construct a card.
     * 
     * @param num The number on the card.
     * @param suit The suit of the card.
     */
    Card(unsigned short int num, unsigned short int suit);
};

#endif