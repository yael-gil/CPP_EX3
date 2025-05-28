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
          target->set_coins(-7); //Pay 7 coin 
          player::Player* begin = this->get_action_game()->get_palyer_in_game->begin();
          player::Player* end = this->get_action_game()->get_palyer_in_game->end();

          this->get_action_game()->get_palyer_in_game()->erase(std::remove(begin, end, target), end); //remove the target from the players list
          this->get_action_game()->get_turns()->erase(std::remove(begin, end, target), end); // remove the target from the turn

          std::cout<<"Player "<<target->get_name()<<" exited the game by "<<current->get_name()<<std::endl; 
          
          std::cout<<" Players remaining in the game: "<<std::endl; //Print the player that remaining the game
          for(int i = 0; i < this->get_action_game()->get_palyer_in_game()->size(); i++){
            std::cout<<this->get_action_game()->get_palyer_in_game()[i]->get_name()<<std::endl;
          }
        }
      else{
          throw std::runtime_error("Can't find player(Coup).");
      }
  }

  //Coup is performed on another player
  void Coup::execute(){

    throw std::runtime_error("Coup is performed on another player.");

  }

 
}