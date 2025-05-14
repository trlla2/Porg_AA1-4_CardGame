#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include "Card.h"
#include "Player.h"
class Game
{
private:
	unsigned int numPlayers;
	std::vector<Card> deck;
	std::vector<Card> discarded;
	std::list<Player> players;
public:
	Game(unsigned int numPlayers);
	Card getNewCard();
	void discardCard(Card const card);
	void printDiscarded() const;
	
};

