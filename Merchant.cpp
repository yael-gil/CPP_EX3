//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Merchant.hpp"

namespace player{


    Merchant::Merchant(std::string name, game::Game* game): Player(name, game){
    }
    

    Merchant:: ~Merchant(){}
        

}