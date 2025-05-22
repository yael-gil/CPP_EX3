//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Governor.hpp"

namespace player{


    Governor::Governor(std::string name, game::Game* game, const std::string& roll_name): Player(name, game, "Governor"){
    }
    

    Governor:: ~Governor(){}
           
    bool Governor::block_tax(bool block){
            
        return block;
    }
    

}