//matan9402215@gmail.com
//208668624
#include "DevelopmentCardDeck.hpp"
#include <algorithm>
#include <random>
#include <ctime>

DevelopmentCardDeck::DevelopmentCardDeck() {
    // Initialize deck with a set number of each card type
    for (int i = 0; i < 14; ++i){
        deck.emplace_back(DevelopmentCardType::KNIGHT);
    }
    for (int i = 0; i < 5; ++i){
        deck.emplace_back(DevelopmentCardType::VICTORY_POINT);
    }
    for (int i = 0; i < 2; ++i) {
        deck.emplace_back(DevelopmentCardType::ROAD_BUILDING);
        deck.emplace_back(DevelopmentCardType::YEAR_OF_PLENTY);
        deck.emplace_back(DevelopmentCardType::MONOPOLY);
    }
    shuffleDeck();
}

void DevelopmentCardDeck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}


DevelopmentCard DevelopmentCardDeck::drawCard() {
    DevelopmentCard card = deck.back();
    deck.pop_back();
    return card;
}
