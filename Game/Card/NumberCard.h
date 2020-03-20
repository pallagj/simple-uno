//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_NUMBERCARD_H
#define UNO_NUMBERCARD_H

#include "Card.h"

class NumberCard : virtual public Card{
    int number;
public:
    NumberCard(Color color, int number) : Card(color), number(number){}

    Card* after(Player* player) override;

    bool isFit(NumberCard *pCard) override;

    virtual operator std::string() override {
        return ColorToString(color)[0] + std::to_string(number);
    }

};

#endif //UNO_NUMBERCARD_H
