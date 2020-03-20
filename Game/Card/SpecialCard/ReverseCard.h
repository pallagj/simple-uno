//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_REVERSECARD_H
#define UNO_REVERSECARD_H


#include "SpecialCard.h"

class ReverseCard :  virtual  public SpecialCard{
public:
    ReverseCard(Color color) : Card(color), SpecialCard(color){}

    bool before(Player* player) override;

    virtual operator std::string() override {
        return ColorToString(color)[0] + std::string("R") ;
    }

};


#endif //UNO_REVERSECARD_H
