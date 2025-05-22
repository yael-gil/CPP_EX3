//yaeldorani@gmail.com

#include "Player.hpp"
#include <iostream>

namespace player{
    
    int Player::ID = 0;

        Player::Player(std::string name, game::Game *game, const std::string& roll_name): roll_name(roll_name) {
            this->name = name;
            id = ID++;
            coins = 0; //Intializing the coins to 0 
            sanction = false; 
            this->game = game;
       
        }

        Player::~Player() {

        }

        int Player:: get_coins(){
            return coins;
        }
    
        // Set current player's total coins
        void Player::set_coins(int amount){
            this->coins = this->coins + amount;
        }

        // Return true if the player is in sancion
        bool Player::get_sanction(){
            return this->sanction;
        }

        // change place
        void Player::do_sanction(){
            this->sanction = false;
        }
        
        
    //Return player's roll 
    std::string Player::get_roll(){ 
        return this->roll_name;
    }

}