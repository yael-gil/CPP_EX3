//yaeldorani@gmail.com

#include "Player.hpp"
#include <iostream>

namespace player{
    
    int Player::ID = 0;

        Player::Player(std::string name, game::Game *game, const std::string& role_name): role_name(role_name) {
            this->name = name;
            id = ID++;
            coins = 0; //Intializing the coins to 0 
            sanction = false; 
            this->game = game;
            *game->add_player(this); // Add the player to the current game
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
        void Player::set_sanction(bool sanction){
            this->sanction = sanction;
        }
        
        
    //Return player's role 
    std::string Player::get_role(){ 
        return this->role_name;
    }

    // Return the player's name
    std::string Player::get_name(){
        return this->name;
    }

    //Does nothing if not governor
    bool Player::block_tax(Player* player){
            
        return false;
    }


}