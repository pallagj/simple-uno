//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include "SpecialCard.h"
#include "../../Player.h"


 bool SpecialCard::before(Player* player)  {
    is_active = true;
    return false;
}

 Card* SpecialCard::after(Player* player)  {
    if(!is_active)
        return after_inactive(player);

    Card* card = after_active(player);

    is_active = false;

    return card;
}

 Card* SpecialCard::after_active(Player* player){
    return after_inactive(player);
}

 Card* SpecialCard::after_inactive(Player* player){
    Card* card = player->giveMeCard();

    if(card == nullptr){
         player->drawCards(1);
         return nullptr;
     }

    if(!card->isFit(this))
        throw IrregularCardException("Nem stimmel a kartya!", card, player);

    return card;
}

bool SpecialCard::isFit(NumberCard *pCard)  {
    return color == UNDEFINIT || pCard->getColor() == color;
}