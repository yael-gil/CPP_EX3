//yaeldorani@gmail.com

#include "Action.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

#include "Tax.hpp"


namespace action{
 

  Tax::Tax(game::Game* game, player::Player* source, std::string name, const std::string& gather) : Action( game, source, name, gather){
    }        
    
  Tax::~Tax(){}
   
  //The player takes two coin from the pot, the action can be blocked by "sanction"
  void action::Tax::execute(){
    if (!this->get_source()->get_sanction()){ // Checks if the player has been sanction
      if(this->get_source()->get_roll() == "Governor"){
        this->get_source()->set_coins(3); // Add 3 coins   
      }
      this->get_source()->set_coins(2); // Add 2 coins 
    }
    else {
        throw std::runtime_error("You are blocked! cannot use tax.");
    }
  }
 
}