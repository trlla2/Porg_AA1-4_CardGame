#include "Game.h"

Game::Game(unsigned int numPlayers) : numPlayers(numPlayers) {
	//Create players
	std::vector<std::string> names = { "Bork", "Marc", "Alf" }; // Random names
	
	for (int i = 1; i <= numPlayers; i++) {
		Player p(i, names[generateClampedRandom(0, names.size())]);
		players.push_back(p);
	}

	// Create deck
	for (int i = 0; i <= HEART; i++) { // for each suit
		for (int j = 1; j <= 13; j++) { // for each value
			Card card((Suit)i, j);
			deck.push_back(card); 
		}
	}

	std::random_shuffle(deck.begin(), deck.end()); // random order
	
	// distribute 10 cards 2 every player
	std::list<Player>::iterator it = players.begin();
	for (; it != players.end(); it++) {
		for (int i = 0; i < 10; i++) { 
			it->insertCard(getNewCard());
		}
	}
}
Card Game::getNewCard(){
	Card c = deck.back();
	deck.pop_back();
	return c;
}

void Game::discardCard(Card const card) {
	discarded.push_back(card);
}

void Game::printDiscarded() const{
	std::cout << "Last discarded card is: ";

	switch (discarded.back().getValue()) // if is 1 is Ace, 11 is Jack, 12 is queen and 13 is king
	{
	case 1:
		std::cout << "Ace of ";
		break;
	case 11:
		std::cout << "Jack of ";
		break;
	case 12:
		std::cout << "Queen of ";
		break;
	case 13:
		std::cout << "King of ";
		break;
	default:
		std::cout << discarded.back().getValue() + " of ";
		break;
	}

	switch (discarded.back().getSuit()) // Print Suit
	{
	case HEART:
		std::cout << "Hearts" << std::endl;
		break;
	case SPADE:
		std::cout << "Spades" << std::endl;
		break;
	case CLUB:
		std::cout << "Clubs" << std::endl;
		break;
	case DIAMOND:
		std::cout << "Diamonds" << std::endl;
		break;
	default:
		break;
	}
}



