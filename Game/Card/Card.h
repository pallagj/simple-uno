//
// Created by Pallag Jonatan on 2020. 03. 17..
//

#ifndef UNO_CARD_H
#define UNO_CARD_H

#include <exception>
#include <string>

enum Color {
    RED, GREEN, BLUE, YELLOW, UNDEFINIT
};

std::string ColorToString(Color color);

class NumberCard;
template <int n>
class DrawCard;
class ReverseCard;
class SkipCard;
class WildCard;
class WildDrawCard;
class ReverseCard;
class SpecialCard;
class Player;

class Card{
protected:
    Color color;
    int need_draw;
public:
    Card(Color color) : color(color){
        need_draw = 0;
    }

    virtual bool isFit(NumberCard *pCard) = 0;


    virtual bool isFit(SpecialCard *pCard);


    virtual bool before(Player* player);
    virtual Card* after(Player* player) = 0;

    virtual operator std::string() = 0;

    Color getColor() { return color; }

    int getDraw() const{return need_draw;}

    void resetDraw(int needDraw){ need_draw = 0;}

    void increaseDraw(int n){ need_draw += n; }

    virtual Card* reset(){
        need_draw = 0;
        return this;
    }

    virtual ~Card(){}
};

class IrregularCardException : public std::exception{
    std::string msg;
    Card* card;
    Player* player;
public:
    IrregularCardException(const std::string &msg, Card *card, Player* player) : msg(msg), card(card), player(player) {}

    virtual const char * what() const noexcept override{
        return msg.c_str();
    }
    Card* getIrregularCard(){
        return card;
    }

    Player *getPlayer() {
        return player;
    }
};

#endif //UNO_CARD_H
