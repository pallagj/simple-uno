//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include "Card.h"
#include <typeinfo>
#include "../Player.h"
#include "SpecialCard/SpecialCard.h"

std::string ColorToString(Color color){
    switch (color){
        case RED:    return "RED";
        case GREEN:  return "GREEN";
        case BLUE:   return "BLUE";
        case YELLOW: return "YELLOW";
        default: return "#";
    }
}

bool Card::isFit(SpecialCard *pCard){
    return color == UNDEFINIT || pCard->color == color || typeid(*this) == typeid(*pCard);
}



bool Card::before(Player* player){
    return false;
}