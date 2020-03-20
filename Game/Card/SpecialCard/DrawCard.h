//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_DRAWCARD_H
#define UNO_DRAWCARD_H

#include "SpecialCard.h"
#include "../../Player.h"

template <int n>
class DrawCard: virtual public SpecialCard{
public:
    DrawCard(Color color) : Card(color), SpecialCard(color){
        need_draw = +n;
    }

    Card* after_active(Player* player) override{
        Card* card = player->giveMeCard();

        if(card == nullptr && getDraw()>0) {
            player->drawCards(getDraw());
            is_active = false;
            return nullptr;
        }

        if(!card->isFit(this))
            throw IrregularCardException("Nem stimmel a kartya!", card, player);

        if(card->getDraw() == 0)
            throw IrregularCardException("Csak olyan kartyat tehetsz, ami tovabb noveli a huzas szamot, vagy huzz!", card, player);
        else
            card->increaseDraw(need_draw);

        is_active = false;

        return card;
    }

    virtual operator std::string() override {
        return ColorToString(color)[0]+std::string("D")+ (is_active?"+"+std::to_string(getDraw()):"") ;
    }

    virtual Card* reset() override {
        SpecialCard::reset();
        need_draw = n;
        return this;
    }
};


#endif //UNO_DRAWCARD_H
