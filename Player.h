#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player
{
private:
	unsigned int id;
	std::string name;
	std::vector<Card> hand;
public:
	Player(unsigned int id, std::string name);
	void insertCard(Card card);
	Card getCard() const;
	Card getCard(Suit& const suit);
	void sortCards();
};

