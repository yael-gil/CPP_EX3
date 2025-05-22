//yaeldorani@gmail.com

#include "Player.hpp"
#include <iostream>

namespace player{
    
    int Player::ID = 0;

        Player:: Player(std::string name){
            this->name = name;
            id = ID++;
            coins = 0; //Intializing the coins to 0 
            sanction = true; 
        }
        Player::~Player() {

        }

        int Player:: get_coins(){
            return coins;
        }


}