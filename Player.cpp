//matan9402215@gmail.com
//208668624
#include "Player.hpp"
#include <iostream>
#include <algorithm>
#include <string>

Player::Player(int playerId) : id(playerId), settlements(0), cities(0), roads(0), roadCount(2), settlementCount(2), cityCount(0) {
    resources[ResourceType::WOOD] = 0;
    resources[ResourceType::BRICK] = 0;
    resources[ResourceType::WOOL] = 0;
    resources[ResourceType::WHEAT] = 0;
    resources[ResourceType::IRON] = 0;
}

void Player::addDevelopmentCard(const DevelopmentCard& card) {
    developmentCards.push_back(card);
}

void Player::removeDevelopmentCard(const DevelopmentCard& card) {
    for (auto it = developmentCards.begin(); it != developmentCards.end(); ++it) {
        if (it->type == card.type) {
            developmentCards.erase(it);
            return;
        }
    }
    std::cerr << "Error: Development card not found." << std::endl;
}

bool Player::hasResources(const std::unordered_map<ResourceType, int>& cost) const {
    for (const auto& [type, amount] : cost) {
        if (resources.at(type) < amount) {
            return false;
        }
    }
    return true;
}

bool Player::tradeWithBank(ResourceType giveResource, ResourceType getResource) {
    const int tradeRatio = 4;
    if (resources[giveResource] < tradeRatio) {
        return false; // not enough resources to trade
    }

    resources[giveResource] -= tradeRatio; // 
    resources[getResource] += 1;           // 

    return true;
}

void Player::updateVictoryPoints() {
    victoryPoints = settlements + (cities * 2);
    if (hasLongestRoad) {
        victoryPoints += 2;
    }
    if (hasLargestArmy) {
        victoryPoints += 2;
    }
    for (const auto& card : developmentCards) {
        if (card.type == DevelopmentCardType::VICTORY_POINT) {
            victoryPoints++;
        }
    }
}

// 
void Player::spendResources(const std::unordered_map<ResourceType, int>& cost) {
    for (const auto& [type, amount] : cost) {
        resources[type] -= amount;
    }
}

void Player::gainResources(ResourceType type, int amount) {
    resources[type] += amount;
}

std::string Player::DevelopmentCardTypeToString(DevelopmentCardType type) const {
    switch (type) {
        case DevelopmentCardType::KNIGHT:
            return "Knight";
        case DevelopmentCardType::VICTORY_POINT:
            return "Victory Point";
        case DevelopmentCardType::ROAD_BUILDING:
            return "Road Building";
        case DevelopmentCardType::YEAR_OF_PLENTY:
            return "Year of Plenty";
        case DevelopmentCardType::MONOPOLY:
            return "Monopoly";
        default:
            return "Unknown";
    }
}
