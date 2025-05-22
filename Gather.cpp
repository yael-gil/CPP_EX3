//yaeldorani@gmail.com

#include "Action.hpp"
#include <iostream>
#include "Gather.hpp"
#include <stdexcept>

#include <string>

namespace action{
 

  Gather::Gather(game::Game* game, player::Player* source, std::string name, const std::string& gather) : Action( game, source, name, gather){
    }        
    
  Gather::~Gather(){}
   
  //The player takes one coin from the pot, the action can be blocked by "sanction"
  void action::Gather::execute(){
    if (!this->get_source()->get_sanction()){ // Checks if the player has been sanction
      this->get_source()->set_coins(1); // Add coin 
    } else {
        throw std::runtime_error("You are blocked! cannot use gather.");
    }
  }
 
}