//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include "ReverseCard.h"
#include "../../Player.h"

bool ReverseCard::before(Player* player){
    SpecialCard::before(player);
    return true;
}