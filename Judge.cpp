//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Judge.hpp"

namespace player{


    Judge::Judge(std::string name, game::Game* game): Player(name, game){
    }
    

    Judge:: ~Judge(){}
           
    bool Judge::block_bribe(Player* player){

        if (true){
           
            std::cout<< "Judge blocks bribe"<<std::endl;
            return true;
        }
        return false;
    }
    

}