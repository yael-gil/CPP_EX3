//yaeldorani@gmail.com

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"

namespace game{


class Game{

private:
    static int ID; // ID to game
    std::string name; // Game's name
    std::vector<player::Player*> players; // list of the players

public:
 
    int id; //save current game's id   

    Game(std::string& name); 
    ~Game();

    void add_player(player::Player* player); // Add player to the game

    const std::vector<player::Player*> get_palyer_in_game(std::string& roll); //Return specific player by roll

};
}

#endif