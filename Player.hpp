//yaeldorani@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "Enum_role.hpp"

namespace game{
    class Game; // Forward declaration to avoid circular dependency
}
namespace player{


class Player{

private:
    static int ID; // ID to player
    std::string name; // Player's name
    int coins; // Current player's total coins
    bool sanction; // True if the player is in sancion
    game::Game* game; //The specific game the player belongs to
    Enum_role role; //enum for role
    bool role_set = false; //Prevents double definition or change of role for a player
    bool active = true; // True if the player is active in the game

public:
 
    int id; //save current player's id   

    Player (std::string name, game::Game* game); 
    ~Player();

        int get_coins(); // Return current player's total coins
        void set_coins(int amount); // Set current player's total coins
        bool get_sanction(); // Return true if the player is in sancion
        void set_sanction(bool sanction); // Change saction state
        std::string get_name(); // Return the player's name
        Enum_role get_role() const; // return player's role
        void set_role (Enum_role role); //Intilalizer role 
        Enum_role get_random_role(); //Choose randomaly role to player 
        std::string role_to_string(Enum_role role); // Convert role to string
        bool is_active() const; // Check if the player is active
        void set_active(bool is_active); // Set player active or inactive

        virtual bool block_tax(Player* player); //Block for Governor
        virtual bool block_coup(Player* player); //Block for General
        virtual bool block_bribe(Player* player); //Block for Judge
        virtual void do_invest(); //Invest for baron
        virtual int peek(Player* player); //Peek for Spy, not consider a turn 



    };
}

#endif