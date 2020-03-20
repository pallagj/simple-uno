//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include "WildCard.h"
#include "../../Player.h"

bool WildCard::before(Player* player) {
    SpecialCard::before(player);
    color = player->chooseColor();
    return false;
}