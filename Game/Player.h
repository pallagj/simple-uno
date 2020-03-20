//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H

#include <string>
#include <vector>
#include "Game.h"
#include "Card/Card.h"

class Card;


class Player{
    std::vector<Card*> cards;
    std::string name;
    Game* game;
public:
    Player(Game* game, std::string name);

    Card* giveMeCard();

    void drawCards(int n){
        std::vector<Card*> cards = game->giveMeCard(n);

        std::cout << name << " a kovetkezo kartyakat hoztad: [ ";
        for(Card* card : cards){
            std::cout << (std::string)*card << " ";
            this->cards.push_back(card);
        }
        std::cout << "]" << std::endl;
    }

    operator const char *(){
        return name.c_str();
    }

    bool hasCard(){
        return !cards.empty();
    }

    Color chooseColor() ;

    void getBack(Card *pCard);

    ~Player(){
        for(Card* card : cards)
            delete card;
    }
};


#endif //UNO_PLAYER_H
