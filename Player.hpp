//yaeldorani@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "Game.hpp"
#include "Enum_role.cpp"
namespace player{


class Player{

private:
    static int ID; // ID to player
    std::string name; // Player's name
    int coins; // Current player's total coins
    bool sanction; // True if the player is in sancion
    game::Game* game; //The specific game the player belongs to
    const std::string& role_name; //The player's role   
    Enum_role role; //enum for role
    bool role_set = false; //Prevents double definition or change of role for a player

public:
 
    int id; //save current player's id   

    Player(std::string name, game::Game *game, const std::string& role_name); 
    ~Player();

        int get_coins(); // Return current player's total coins
        void set_coins(int amount); // Set current player's total coins
        bool get_sanction(); // Return true if the player is in sancion
        void set_sanction(bool sanction); // Change saction state
        std::string get_name(); // Return the player's name
        virtual bool block_tax(Player* player); //Block for Governor
        Enum_role get_role() const; // return player's role
        void set_role (Enum_role role); //Intilalizer role 
        Enum_role get_random_role(); //Choose randomaly role to player 

};
}

#endif