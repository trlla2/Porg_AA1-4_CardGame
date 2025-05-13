#include "Card.h"



bool Card::operator==(Card& other) const {
	return suit == other.suit && value == other.value;
}

bool Card::operator>=(Card& other) const {
	return suit >= other.suit && value >= other.value;
}