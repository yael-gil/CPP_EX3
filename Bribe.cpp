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
  void action::Bribe::execute(){
    player::Player* current = this->get_action_game()->turns();
    current->set_coins(-4); //Pay the price
    if (current != nullptr){ // Add the current player to the turn twice
        this->get_action_game()->get_turns().insert(this->get_action_game()->get_turns().begin(), current);
        this->get_action_game()->get_turns().insert(this->get_action_game()->get_turns().begin(), current);
    }
    else{
        throw std::runtime_error("Can't find player(bribe).");
  }
 
}
  //Bribe is not performed on another player
  void execute(player::Player* target) {
    throw std::runtime_error("Bribe is not performed on another player.");
  }
}