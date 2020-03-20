//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_SKIPCARD_H
#define UNO_SKIPCARD_H

#include "SpecialCard.h"

class SkipCard : virtual public SpecialCard{
public:
    SkipCard(Color c ) : Card(c), SpecialCard(c){}

    Card* after_active(Player* player) override;

    virtual operator std::string() override {
        return ColorToString(color)[0]+std::string("S") ;
    }
};





#endif //UNO_SKIPCARD_H
