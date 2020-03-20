//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_WILDDRAWCARD_H
#define UNO_WILDDRAWCARD_H


#include "WildCard.h"
#include "DrawCard.h"

class WildDrawCard: public WildCard, public DrawCard<4>{
public:
    WildDrawCard() : Card(UNDEFINIT), SpecialCard(UNDEFINIT),  DrawCard<4>(UNDEFINIT){}

    virtual operator std::string() override {
        return ColorToString(color)[0]+std::string("WD")+ (is_active?"+"+std::to_string(getDraw()):"") ;
    }

    virtual Card* reset() override {
        DrawCard::reset();
        color = UNDEFINIT;
        return this;
    }
};



#endif //UNO_WILDDRAWCARD_H
