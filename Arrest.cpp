//yaeldorani@gmail.com

#include "Action.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

#include "Arrest.hpp"


namespace action{
 

  Arrest::Arrest(game::Game* game, player::Player* source) : Action( game, source, "Arrest"){
    }        
    
  Arrest::~Arrest(){}
   
//The player chooses another player and takes one coin form them.
// It cannot be used on the same player twice.  
    void Arrest::execute(player::Player* target){

      player::Player* current = this->get_source();

      if (target != nullptr && this->get_action_game()->get_last_arrest() != target->get_name()){ 
          target->set_coins(-1); //Take coin from the target
          current->set_coins(1); //Add the coin to current 
          this->get_action_game()->set_last_arrest(target->get_name());
      }
      else{
          throw std::runtime_error("Can't find player(Arrest).");
      }
  }
  //Arrest is performed on another player
  void Arrest::execute(){

    throw std::runtime_error("Arrest is performed on another player.");

  }

 
}