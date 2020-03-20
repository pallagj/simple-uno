//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_WILDCARD_H
#define UNO_WILDCARD_H


#include "SpecialCard.h"

class WildCard : virtual public SpecialCard{
public:
    WildCard() : Card(UNDEFINIT), SpecialCard(UNDEFINIT){}

    bool before(Player* player) override;

    virtual operator std::string() override {
        return ColorToString(color)[0]+std::string("W") ;
    }

    virtual Card* reset() override {
        SpecialCard::reset();
        color = UNDEFINIT;
        return this;
    }
};


#endif //UNO_WILDCARD_H
