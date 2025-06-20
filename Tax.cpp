//yaeldorani@gmail.com

#include "Action.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

#include "Tax.hpp"
#include "Enum_role.hpp"

namespace action{
 

  Tax::Tax(game::Game* game, player::Player* source) : Action( game, source, "Tax"){
    }        
    
  Tax::~Tax(){}
   
  //The player takes two coin from the pot, the action can be blocked by "sanction"
  void Tax::execute(){
    if (!this->get_source()->get_sanction()){ // Checks if the player has been sanction
      
      if(this->get_source()->get_role() == Enum_role::Governor){
        this->get_source()->set_coins(3); // Add 3 coins  
        return; 
      }

      std::vector<player::Player*> governor_in_game = this->get_action_game()->get_player_in_game_by_role(Enum_role::Governor);
      
      // Ask governors to block
      for(int i = 0; i < governor_in_game.size(); i++){
        bool block = governor_in_game[i]->block_tax(this->get_source()); 
        if (block == true){ //If blocks, break
          throw std::runtime_error("You are blocked! cannot use tax.");
        }
      }
      //If not blocked, take 2 coins
      this->get_source()->set_coins(2); // Add 2 coins 
      
    }
    else{
      throw std::runtime_error("You are in sanction! cannot use tax.");
    }
  }

  //Tax is not performed on another player
  void Tax::execute(player::Player* target) {
    throw std::runtime_error("Tax is not performed on another player.");
  }
 
}