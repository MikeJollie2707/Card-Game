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
    unsigned short int num = 0;
    unsigned short int suit = 0;
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

    Card(unsigned short int num, unsigned short int suit);
};

#endif