//yaeldorani@gmail.com

#include "Action.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "Coup.hpp"


namespace action{
 

  Coup::Coup(game::Game* game, player::Player* source) : Action( game, source, "Coup"){
    }        
    
  Coup::~Coup(){}
   
   //The player chooses another player and completely removes them from the game
    //This action costs 7 coins 
   void Coup::execute(player::Player* target){

    player::Player* current = this->get_source();

    if (target != nullptr){ 

        current->set_coins(-7); // Pay 7 coins 

        // Get General in the game
        std::vector<player::Player*> general_in_game = this->get_action_game()->get_player_in_game_by_role(Enum_role::General);

        // Ask the General to block
          for(size_t i = 0; i < general_in_game.size(); i++){
            bool block = general_in_game[i]->block_coup(this->get_source()); 
            if (block == true){ // If blocks, throw exception and exit
                throw std::runtime_error("You are blocked! canceled coup.");
                return;
            }
        }

        // Remove the target player from the game
        target->set_active(false); //Remove the target as  inactive player


        std::cout << "Player " << target->get_name() << " exited the game by " << current->get_name() << std::endl; 

        std::cout << "Players remaining in the game: " << std::endl; //Print the player that remaining the game

        //Print the remaining players in the game 
        for(size_t i = 0; i < this->get_action_game()->players().size(); i++){
            std::cout << this->get_action_game()->players()[i]->get_name() << std::endl;
        }
        game::winner(); //Check if there is a winner after the Coup action

    } else {
        throw std::runtime_error("Can't find player(Coup).");
    }
}

  // This function is used to execute the Coup action
  void Coup::execute() {
    throw std::runtime_error("Coup action requires a target player.");
  }

 
}