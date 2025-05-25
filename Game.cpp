//yaeldorani@gmail.com

#include "Game.hpp"
#include <iostream>

namespace game{
    
    int Game::ID = 0;

    Game:: Game(std::string& name){

        std::vector<player::Player*> players; // List of the players
        id = ID++;
    }
    Game::~Game() {

    }

    void Game::add_player(player::Player* player){
        for (int i = 0; i < this->players.size(); i++){
            if(players[i]->get_name() == player->get_name()){ //If player's name == player's name in game, add to the list
                throw std::runtime_error("This name is taken, there is a player in the curremt game with that name. \n"
                    "Please choose a different name.");
            }
        }
        this->players.push_back(player); // Add a new player to the game
    }
        
    const std::vector<player::Player*> Game::get_palyer_in_game(std::string& roll){
        std::vector<player::Player*> return_roll; 
        for (int i = 0; i < this->players.size(); i++){
            if(players[i]->get_roll() == roll){ //If player's roll == roll, add to the list
                return_roll.push_back(players[i]);
            }
        }
        return return_roll;
    }

}