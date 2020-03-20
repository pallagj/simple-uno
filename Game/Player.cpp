//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include "Player.h"
#include "Card/Card.h"
#include "Card/SpecialCard/WildDrawCard.h"

Player::Player(Game* game, std::string name){
    this->game = game;
    this->name = name;
}

Card* Player::giveMeCard(){
    std::cout << name << ", melyik kartyat szeretned rakni?\n('-' nem tudsz/akarsz rakni)\n" << std::endl;
    std::cout << "Jelenlegi kartya:" <<std::endl;
    std::cout << "[ " << (std::string)*game->getActiveCard() << " ]\n" << std::endl;
    std::cout << "Kartyaid:" <<std::endl;
    std::cout << "[ ";
    for(Card* card : cards){
        std::string card_s = (std::string)*card;
        std::cout << card_s << " ";
    }
    std::cout << "]\n" << std::endl;
    std::string card_s;
    std::cin>>card_s;
    std::cout << std::endl;

    for(auto it = cards.begin(); it<cards.end(); it++){
        Card* card = *it;
        if((std::string)*card == card_s){
            cards.erase(it);
            return card;
        }else if(card_s == "WD+4" && card->getDraw()==4){
            for(auto &card : cards) {
                delete card;
                card = new WildDrawCard();
            }
        }
    }

    return nullptr;
}

Color Player::chooseColor() {
    std::cout << "Valassz szint!" << std::endl;
    std::cout<< "RED (R), GREEN (G), BLUE (B), YELLOW (Y)" << std::endl;

    std::string s_color;
    std::cin>>s_color;
    Color color = UNDEFINIT;
    for(int i=0; i<4; i++){
        if(s_color[0]== ColorToString(Color(i))[0])
            color =  Color(i);
    }

    std::cout << "A valasztott szin: " + ColorToString(color) + "\n" << std::endl;
    return color;
}

void Player::getBack(Card *pCard) {
    cards.push_back(pCard);
}
