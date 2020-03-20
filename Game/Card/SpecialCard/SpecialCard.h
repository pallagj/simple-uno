//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_SPECIALCARD_H
#define UNO_SPECIALCARD_H


#include "../Card.h"
#include "../NumberCard.h"

class SpecialCard : virtual public Card{
protected:
    bool is_active;
public:

    SpecialCard(Color color) : Card(color){
        is_active = false;
    }

    virtual bool before(Player* player) override ;

    virtual Card* after(Player* player) override ;

    virtual Card* after_active(Player* player);

    virtual Card* after_inactive(Player* player);

    bool isFit(NumberCard *pCard) override;

    virtual operator std::string() = 0;

    virtual Card* reset() override {
        Card::reset();
        is_active = false;
        return this;
    }
};



#endif //UNO_SPECIALCARD_H
