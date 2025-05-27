//yaeldorani@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "Game.hpp"
namespace player{


class Player{

private:
    static int ID; // ID to player
    std::string name; // Player's name
    int coins; // Current player's total coins
    bool sanction; // True if the player is in sancion
    game::Game* game; //The specific game the player belongs to
    const std::string& role_name; //The player's role   

public:
 
    int id; //save current player's id   

    Player(std::string name, game::Game *game, const std::string& role_name); 
    ~Player();

        int get_coins(); // Return current player's total coins
        void set_coins(int amount); // Set current player's total coins
        bool get_sanction(); // Return true if the player is in sancion
        void set_sanction(bool sanction); // Change saction state
        virtual std::string get_role(); //Return player's role 
        std::string get_name(); // Return the player's name
        virtual bool block_tax(Player* player); //Block for Governor

};
}

#endif