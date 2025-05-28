//yaeldorani@gmail.com

#include <iostream>
#include <random>

#include "Player.hpp"
#include "Enum_role.cpp"

namespace player{
    
    int Player::ID = 0;

        Player::Player(std::string name, game::Game *game, const std::string& role_name): role_name(role_name) {
            this->name = name;
            id = ID++;
            coins = 0; //Intializing the coins to 0 
            sanction = false; 
            this->game = game;
            this->set_role(get_random_role());//Initilize role
            *game->add_player(this); // Add the player to the current game
        }

        Player::~Player() {

        }

        //Returns player's role 
        Enum_role Player::get_role() const {
            return this->role;
        }

        //Set player's role
        void Player::set_role (Enum_role role){
            if(this->role_set){
                throw std::runtime_error("Role has already been set and cannot be changed.");
            }
            this->role = role;
            role_set = true;
        }

        //Rerurns randon number for role
        Enum_role Player::get_random_role(){
            static std::random_device rd;
            static std::mt19937 gen(rd());
            static std::uniform_int_distribution<>dis(0,5);
        
            return static_cast<Enum_role>(dis(gen));
        
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
        


    // Return the player's name
    std::string Player::get_name(){
        return this->name;
    }

    //Does nothing if not governor
    bool Player::block_tax(Player* player){
            
        return false;
    }


}

