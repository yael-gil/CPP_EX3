//yaeldorani@gmail.com

#include <iostream>
#include <random>

#include "Player.hpp"
#include "Enum_role.hpp"
#include "Game.hpp"
namespace player{
    
    int Player::ID = 0;

        Player::Player(std::string name, game::Game* game) {
            this->name = name;
            id = ID++;
            coins = 0; //Intializing the coins to 0 
            sanction = false; 
            this->game = game;
            this->set_role(get_random_role());//Initilize role
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

        // Set the player's sanction status
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

    // Convert role to string
    std::string Player::role_to_string(Enum_role role){
        switch (role)
        {
        case Enum_role::Governor: {
            return "Governor";
            break;
        }
    
        case Enum_role::Baron: {
            return "Baron";
            break;
        }

        case Enum_role::Spy: {
            return "Spy";
            break;
        }

        case Enum_role::General: {
            return "General";
                break;
        }
        case Enum_role::Judge: {
            return "Judge";
                break;
        }
        case Enum_role::Merchant: {
            return "Merchant";
                break;
        }
        default:
            break;
        }
    }
     // Check if the player is active
    bool Player::is_active() const { return this->active; }
    
    // Set player active or inactive
    void Player::set_active(bool is_active) { this->active = is_active; } 


bool Player::block_coup(Player* player) {
    return false;
}

bool Player::block_bribe(Player* player) {
    return false;
}

void Player::do_invest() {
    // do nothing by default
}

int Player::peek(Player* player) {
    return -1; // or some sentinel value
}

}

