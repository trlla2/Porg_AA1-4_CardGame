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
	void InsertCard(Card card);
	Card GetCard() const;
	Card GetCard(Suit& const suit);
	void SortCards();
};

