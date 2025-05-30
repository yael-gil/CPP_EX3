//yaeldorani@gmail.com

#include "Action.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

#include "Bribe.hpp"


namespace action{
 

  Bribe::Bribe(game::Game* game, player::Player* source) : Action( game, source, "Bribe"){
    }        
    
  Bribe::~Bribe(){}
   
//The player pays 4 coins to the pot and gets a double turn (total of 3 turns)
  void Bribe::execute(){
    player::Player* current = this->get_action_game()->turns();
    current->set_coins(-4); //Pay the price
    if (current != nullptr){ // Add the current player to the turn twice
        // Find judge in game
      std::vector<player::Player*> judge_in_game = this->get_action_game()->get_player_in_game_by_role(Enum_role::Judge);
      
      // Ask judges to block
      for(int i = 0; i < judge_in_game.size(); i++){
        bool block = judge_in_game[i]->block_bribe(this->get_source()); 
        if (block == true){ //If blocks, break
          throw std::runtime_error("You are blocked! cannot use bribe.");
        }
      }
        this->get_action_game()->get_turns().insert(this->get_action_game()->get_turns().begin(), current);
        this->get_action_game()->get_turns().insert(this->get_action_game()->get_turns().begin(), current);
    }
    else{
        throw std::runtime_error("Can't find player(bribe).");
  }
 
}
  //Bribe is not performed on another player
  void Bribe::execute(player::Player* target) {
    throw std::runtime_error("Bribe is not performed on another player.");
  }
}