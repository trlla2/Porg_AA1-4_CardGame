#include "Player.h"


Player::Player(unsigned int id, std::string name) : id(id), name(name){ }

void Player::insertCard(Card card) {
	hand.push_back(card);
	sortCards();
}

Card Player::getCard() const{
	Card card(CLUB, 0);
	if (hand.empty()) {
		std::cout << "ERROR: La mano esta vacia" << std::endl;
		return card; // Has value 0 witch means hand is empty
	}
	
	int random = generateClampedRandom(1, hand.size());
	card = hand[random];

	return card;
}

Card Player::getCard(Suit& const suit) {
	Card card(CLUB, 0);
	if (hand.empty()) {
		std::cout << "ERROR: La mano esta vacia" << std::endl;
		return card; // Has value 0 witch means hand is empty
	}

	
	for (int i = 0; i < hand.size(); i) {
		if (hand[i].getSuit() == suit && card.getValue() < hand[i].getValue()) {
			card = hand[i];
		}
	}

	return card;
}

void Player::sortCards() {
	if (hand.empty()) {
		std::cout << "ERROR: La mano esta vacia" << std::endl;
		return; // Has value 0 witch means hand is empty
	}

	for (int i = 1; i < hand.size(); i++) { // sort using insertion sort
		Card x = hand[i];
		int j = i;

		while (j > 0 && hand[j - 1] > x) {
			hand[j] = hand[j - 1];
			--j;
		}

		hand[i] = x;
	}
}