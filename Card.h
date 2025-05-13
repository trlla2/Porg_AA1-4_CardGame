#pragma once
#include "Suit.h"

class Card
{
private:
	Suit suit;
	int value;
public:
	Card();
	

	bool operator==(Card& other) const;
	bool operator>=(Card& other) const;


};

