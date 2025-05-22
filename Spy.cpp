//yaeldorani@gmail.com

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Player.hpp"
#include "Spy.hpp"

namespace player{


    Spy::Spy(std::string name, game::Game* game, const std::string& roll_name): Player(name, game, "Spy"){
    }
    

    Spy:: ~Spy(){}
    
    //איך זה עובד הקטע עם המעצר של המרגל?
    int Spy::peek(Player* player){
        return player->get_coins();
    }
    

}