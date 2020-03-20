#include <vector>
#include <ctime>
#include <typeinfo>

#include "Game/Game.h"
#include "Game/Player.h"
#include "Game/Card/SpecialCard/SkipCard.h"
#include "Game/Card/SpecialCard/WildDrawCard.h"

std::vector<Player*> readPlayers(Game* game){
    std::cout << "Hany jatekos legyen?" << std::endl;
    int number_of_players;
    std::cin >> number_of_players;

    std::vector<Player*> players(number_of_players);
    for(int i=0; i<number_of_players; i++){
        std::cout << "Adja meg a(z) " << (i+1) << ". jatekos nevet:" << std::endl;

        std::string name;
        std::cin >> name;

        players[i] = new Player(game, name);
    }
    return players;
}


int main() {
    srand(time(NULL));

    Game* game = new Game(Game::UNO());

    std::vector<Player*> players = readPlayers(game);
    game->addPlayers(players.begin(), players.end());

    try{
        game->start();
    }catch(const char * err){
        std::cerr << err << std::endl;
    }

    delete game;

    return 0;
}
