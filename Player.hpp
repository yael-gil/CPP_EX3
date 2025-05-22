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
    const std::string& roll_name; //The player's roll   

public:
 
    int id; //save current player's id   

    Player(std::string name, game::Game *game, const std::string& roll_name); 
    ~Player();

        int get_coins(); // Return current player's total coins
        void set_coins(int amount); // Set current player's total coins
        bool get_sanction(); // Return true if the player is in sancion
        void do_sanction(); // do sanction
        virtual std::string get_roll(); //Return player's roll 


};
}

#endif