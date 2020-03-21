//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_GAME_H
#define UNO_GAME_H

#include <vector>
#include <initializer_list>
#include <iostream>

class Player;
class Card;

class Game{
    std::vector<Player*> players;
    std::vector<Card*> cards;
    Card* active_card;

    void printPlayers(int i, int dir) const;
    int leptet(int index, int dir) const;
public:
    Game(std::vector<Card*> cards);

    void start();

    std::vector<Card *> giveMeCard(int n) {
        if(cards.size()<(unsigned)n)
            throw "Nincs tobb kartya a pakliban!";

        std::vector<Card*> out(cards.begin(), cards.begin()+n);
        cards.erase(cards.begin(), cards.begin()+n);

        return out;

    }
    void addPlayers(std::initializer_list<Player*> players);

    template <typename Iterator>
    void addPlayers(Iterator begin, Iterator end) {
        this->players.insert(this->players.end(), begin, end);
    }

    Card* getActiveCard(){
        return active_card;
    }

    ~Game();

    static std::vector<Card*> UNO();
};


#endif //UNO_GAME_H
