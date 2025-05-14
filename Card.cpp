#include "Card.h"

Card::Card(Suit suit, int value) : suit(suit), value(value) { }

Suit Card::getSuit() const { return suit; }
int Card::getValue() const { return value; }

bool Card::operator==(Card& other) const {
	return suit == other.suit && value == other.value;
}

bool Card::operator>(Card& other) const {
	return suit > other.suit && value > other.value;
}