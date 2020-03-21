//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#include <algorithm>
#include <conio.h>
#include "Game.h"
#include "Card/Card.h"
#include "Player.h"
#include "Card/SpecialCard/DrawCard.h"
#include "Card/SpecialCard/ReverseCard.h"
#include "Card/SpecialCard/SkipCard.h"
#include "Card/SpecialCard/WildCard.h"
#include "Card/SpecialCard/WildDrawCard.h"

Game::Game(std::vector<Card *> cards) {
    this->cards = cards;
    active_card = nullptr;
}

void Game::addPlayers(std::initializer_list<Player*> players){
    this->players.insert(this->players.end(), players.begin(), players.end());
}

void Game::start(){
    std::system("cls");
    std::cout << "UNO Jatek, sok sikert!\n" << std::endl;
    int dir = +1;
    
    //Legfelso kartya levetele kezdeshez
    active_card = cards.back();
    cards.pop_back();

    std::random_shuffle(cards.begin(), cards.end());

    for(Player* player : players){
        player->drawCards(7);
    }

    for(int i=0; players[i]->hasCard(); i = (i+dir+players.size())%players.size() ){
        //Consol
        std::cout << "\nOK?" << std::endl;
        getch();
        std::system("cls");
        printPlayers(i, dir);

        try{
            Player* p = players[i];
            Card* new_card = active_card->after(p);

            if(new_card == nullptr)
                continue;

            cards.push_back(active_card->reset());
            std::random_shuffle(cards.begin(), cards.end());
            active_card = new_card;

            if(active_card->before(p))
                dir *= -1;

        }catch(IrregularCardException ex){

            //Szabály megszegése
            Player* player = ex.getPlayer();
            Card*   card   = ex.getIrregularCard();

            std::cout << *player <<"!\n" << ex.what() << std::endl;

            //Kártya visszajuttatása
            player->getBack(card);

            //szabálysértés esetén indexnél maradás
            i -= dir;
        }
    }
}

void Game::printPlayers(int index, int dir) const {
    for(int j=0; j < (int)players.size(); j++){
        if(index==j) std::cout << "[" << *players[j] << "]";
        else std::cout << *players[j] ;

        std::cout << (dir<0?" < ":" > ");
    }


    std::cout << "\n" << std::endl;
}

std::vector<Card*> Game::UNO(){
    std::vector<Card*> cards;

    //Specialis kartyak
    for(Color c=RED; c<UNDEFINIT; c=Color(c+1)) {
        for(int i=0; i<2; i++){
            cards.push_back(new SkipCard(c));
            cards.push_back(new ReverseCard(c));
            cards.push_back(new DrawCard<+2>(c));
        }
    }

    //Specialis szinvalaszto kartyak
    for(int i=0; i<4; i++) {
        cards.push_back(new WildCard());
        cards.push_back(new WildDrawCard());
    }

    //Szamkartyak
    for(Color c=RED; c<UNDEFINIT; c=Color(c+1)) {
        for(int n=0; n<10; n++)
            cards.push_back(new NumberCard(c, n));

        for(int n=1; n<10; n++)
            cards.push_back(new NumberCard(c, n));

    }

    //Szamkartyak megkeverese a kezdeshez
    std::random_shuffle(cards.end()-4*19, cards.end());

    return cards;
}


Game::~Game(){
    delete active_card;

    for(Card* card : cards)
        delete card;

    for(Player* player : players)
        delete player;
}
