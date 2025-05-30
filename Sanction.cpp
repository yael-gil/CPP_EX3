//yaeldorani@gmail.com


#include <iostream>
#include "Sanction.hpp"
#include <stdexcept>
#include <string>

#include "Action.hpp"
#include "Enum_role.hpp"
namespace action{
 

  Sanction::Sanction(game::Game* game, player::Player* source) : Action( game, source,"Sanction"){}        
     
  Sanction::~Sanction(){}
   
// The player chooses another player and prevents them
// from using econmic actions until their next turn.
// This action costs 3 coins 
void Sanction::execute(player::Player* target){
   
    player:: Player* current = this->get_source();

    if (target != nullptr){ 
      
     
      this->get_source()->set_coins(-3); //Pay 3 coins
      target->set_sanction(true);
      
      if(target->get_role() == Enum_role::Judge){ //pay 1 more coin if the target is judge 
              current->set_coins(-1);
      }

      if (target->get_role() == Enum_role::Baron){ //Compensation to Baron
        target->set_coins(1);  
      }
      
    }

    else{
        throw std::runtime_error("Can't find player(Sanction).");
    }
}
//Sanction is performed on another player
void Sanction::execute(){

  throw std::runtime_error("Sanction is performed on another player.");

}
 
}