//matan9402215@gmail.com
//208668624
#ifndef DEVELOPMENTCARDDECK_HPP
#define DEVELOPMENTCARDDECK_HPP

#include <vector>
#include "DevelopmentCard.hpp"

class DevelopmentCardDeck {
private:
    std::vector<DevelopmentCard> deck;
    void shuffleDeck();

public:
    DevelopmentCardDeck();
    DevelopmentCard drawCard();
};

#endif // DEVELOPMENTCARDDECK_HPP
