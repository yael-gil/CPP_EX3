//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Governor.hpp"

namespace player{


    Governor::Governor(std::string name, game::Game* game): Player(name, game){
    }
    

    Governor:: ~Governor(){}
           
    bool Governor::block_tax(Player* player){

        if (true){
            std::cout<< "Governor blocks tax";
            player->set_sanction(true); // Block the player
            return true;
        }
        return false;
    }
    

}