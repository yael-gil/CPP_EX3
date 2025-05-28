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
    std::vector<player::Player*> players; // List of the players
    std::vector<player::Player*> turn; // List for turns
    std::string last_arrest; // Keeps the last player arrested to prevent others from arresting them again

public:
 
    int id; //save current game's id   

    Game(std::string& name); 
    ~Game();

    void add_player(player::Player* player); // Add player to the game

    const std::vector<player::Player*> get_player_in_game_by_role(std::string& role); //Return specific player by role

    const std::vector<player::Player*> get_player_in_game(); //Return all players in the game

    std::vector<player::Player*> create_turns(); //Create the turn vector

    std::vector<player::Player*> get_turns(); //Get the turn vector

    player::Player* turns();// Return current turn

    std::string get_last_arrest();

    void set_last_arrest(std::string new_arrest);

    void play_game();

    int choose_action(player::Player* current); // Player choose action

    void do_action(player::Player* current_player, int action); //Do action acording to choose_action
};
}

#endif