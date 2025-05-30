//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Baron.hpp"

namespace player{


    Baron::Baron(std::string name, game::Game* game): Player(name, game){
    }
    

    Baron:: ~Baron(){}
           
    void Baron::do_invest(){

            if(this->get_coins() >= 3){
                this->set_coins(3);
                std::cout<< "Baron invested."; 
                return;
            }
            throw std::runtime_error("Not enough coins, can't invest.");

    }


    

}