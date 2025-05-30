//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "General.hpp"

namespace player{


    General::General(std::string name, game::Game* game): Player(name, game){
    }
    

    General:: ~General(){}
           
    bool General::block_coup(Player* player){

        if (true){
            if(this->get_coins() >= 5){
            this->set_coins(-5);
            std::cout<< "General blocks coup"<<std::endl;
            return true;
            }
            throw std::runtime_error("Not enough coins, can't do coup.");
        }
        return false;
    }
    

}