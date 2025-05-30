//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Spy.hpp"

namespace player{


    Spy::Spy(std::string name, game::Game* game, const std::string& role_name): Player(name, game){
    }
    

    Spy:: ~Spy(){}
    
    //The spy can peek in another player coins, not cost anything and not consider a turn.
    int Spy::peek(Player* player){
        return player->get_coins();
    }
    

}