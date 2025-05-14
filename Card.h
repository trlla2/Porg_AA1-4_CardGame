#pragma once
#include <iostream>
#include "Suit.h"
#include "utils.h"

class Card
{
private:
	Suit suit;
	int value;
public:
	Card(Suit suit, int value); 

	Suit GetSuit() const;
	int GetValue() const;

	bool operator==(Card& other) const;
	bool operator>(Card& other) const;
};

