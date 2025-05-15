#include <iostream>
#include "Card.h"
#include "Game.h"
#include "Player.h"
#include "Suit.h"

int main() {
    srand(time(NULL));

    std::cout << "porves carta" << std::endl;
    Card card1(HEART, 10);
    Card card2(HEART, 10);
    Card card3(SPADE, 12);

    // proves operador
    std::cout << "Card1 == Card2? " << (card1 == card2 ? "Sí" : "No") << std::endl; 
    std::cout << "Card3 > Card1? " << (card3 > card1 ? "Sí" : "No") << std::endl;  

    std::cout << "Probes Game" << std::endl;
    // Crear Game
    Game game(3);

    // Obtenir i descartar una carta
    Card newCard = game.getNewCard();
    game.discardCard(newCard);
    std::cout << "Primera carta descartada: ";
    game.printDiscarded();

    // Obtenir i descartar una carta
    Card anotherCard = game.getNewCard();
    game.discardCard(anotherCard);
    std::cout << "Segona carta descartada: " << std::endl;
    game.printDiscarded();

    // Pruebas para la clase Player
    std::cout << "Pobas player" << std::endl;
    Player player(1, "TestPlayer");

    // Insertar cartas
    player.insertCard(Card(CLUB, 5));
    player.insertCard(Card(HEART, 3));
    player.insertCard(Card(HEART, 11));
    player.insertCard(Card(DIAMOND, 12));

    Card randomCard = player.getCard();
    std::cout << "Carta aleatoria obtinguda: "
        << randomCard.getValue() << " de "
        << randomCard.getSuit() << std::endl;

    // Carta mes alta del palo
    Suit suitToSearch = HEART;
    Card highestCard = player.getCard(suitToSearch);
    std::cout << "Carta mes alta de Hearts: "
        << highestCard.getValue() << std::endl;

    return 0;
}