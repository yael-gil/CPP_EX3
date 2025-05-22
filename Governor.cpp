//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Governor.hpp"

namespace player{
    
    Governor::Governor(std::string name, game::Game* game): Player(name, game){
        action_name = "Governor";
    }
    

    Governor:: ~Governor(){}
           
    //Return player's roll 
    std::string Player::get_roll(){
        return this->roll_name;
    }
    

}