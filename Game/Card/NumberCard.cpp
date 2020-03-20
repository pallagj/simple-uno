//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include "NumberCard.h"
#include "../Player.h"

Card* NumberCard::after(Player* player) {
    Card* card = player->giveMeCard();

    if(card == nullptr){
        player->drawCards(1);
        return nullptr;
    }

    if(!card->isFit(this))
        throw IrregularCardException("Nem stimmel a kartya!", card, player);

    return card;
}

bool NumberCard::isFit(NumberCard *pCard)  {
    return pCard->number == number || pCard->color == color;
}