//yaeldorani@gmail.com

#include "Game.hpp"
#include <iostream>
#include "Action.hpp"
#include "Gather.hpp"
#include "Tax.hpp"
#include "Arrest.hpp"
#include "Bribe.hpp"


namespace game{
    
    int Game::ID = 0;

    Game:: Game(std::string& game_name){

        name = game_name;
        std::vector<player::Player*> players; // List of the players
        id = ID++;
        last_arrest = "none";
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

    //Create the turn vector
    std::vector<player::Player*> Game::create_turns(){
        for(int i = 0; i < this->players.size(); i++){
            this->turn[i] = this->players[i];
        }
        return this->turn;
    } 

    //Returns all players in the game wuth a specific role
    const std::vector<player::Player*> Game::get_palyer_in_game_by_role(std::string& role){
        std::vector<player::Player*> return_role; 
        for (int i = 0; i < this->players.size(); i++){
            if(players[i]->get_role() == role){ //If player's role == role, add to the list
                return_role.push_back(players[i]);
            }
        }
        return return_role;
    }

    //Return all players in the game
    const std::vector<player::Player*> Game::get_palyer_in_game(){
    
        return this->players;
    }

    // Return current turn
    player::Player* Game::turns(){
        if(!turn.empty()){
        player::Player* current = turn.front();
        turn.erase(turn.begin());
        return current;
        }
        return nullptr;
    } 
    
    //Get the turn vector
    std::vector<player::Player*> Game::get_turns(){
        return this->turn;
    } 

    std::string Game::get_last_arrest(){
        return this->last_arrest;
    }

    void Game::set_last_arrest (std::string new_arrest){
        this->last_arrest = new_arrest;
    }

    void Game::play_game(){
        
        this->create_turns(); //At the beginning of the game, a create turn 

        while(this->players.size() > 1){ // If there is 1 player, game over
        
            
            player::Player* current_player = this->turns(); // get the current turn
            
            //print current player's name and role
            std::cout<<"Current player: "<< current_player->get_name()<<std::endl;
            std::cout<<"role: "<< current_player->get_role()<<std::endl;

            //add swich case by role to spaicel actions

            int action = choose_action();

            //Do action acording to player's decision
            do_action(current_player, action);

            //After 1 round the sanction is lifted
            if (current_player->get_sanction()){
                current_player->set_sanction(false);
            }
            
            //Add player to end of the turn
            this->turn.push_back(current_player);
       }

       //Add wining and finish game



    }

    int Game::choose_action(){
        //print action
        std::cout<<"Choose Action: (number)"<<std::endl;

        std::cout<<"1: Gather"<<std::endl;
        std::cout<<"2: Tax"<<std::endl;
        std::cout<<"3: Arrest"<<std::endl;
        std::cout<<"4: Bribe"<<std::endl;
        std::cout<<"5: Sanction"<<std::endl;
        std::cout<<"6: Coup"<<std::endl;

        //Current player choose action
        int action;
        std::cin >> action;
        
        return action;
    }
    
    void Game::do_action(player::Player* current_player, int action){
        //Do action acording to player's decision
        switch (action)
        {
            case 1: {
                if(current_player->get_sanction()){
                   std::cout<<"You are blocked! cannot use gather.";
                   int new_action = choose_action();
                   do_action(current_player, new_action);
                   break;
                
                }
                action::Gather gather(this, current_player);
                gather.execute();
                break;
            }

            case 2: {
                if(current_player->get_sanction()){
                    std::cout<<"You are blocked! cannot use tax.";
                    int new_action = choose_action();
                    do_action(current_player, new_action);
                    break;
                }
                action::Tax tax(this, current_player);
                tax.execute();
                break;
            }

            case 3: {
                action::Arrest arrest(this, current_player);
                
                std::cout<<"Choose player to attact: "<<std::endl;

                for (int i = 0; i < this->get_palyer_in_game().size(); i++){
                    std::cout<<i+1<<": "<<this->get_palyer_in_game()[i];
                }
                int target;
                std::cin >> target;

                arrest.execute(this->get_palyer_in_game()[target-1]);
                break;
            }
            
            case 4: {
                action::Bribe bribe(this, current_player);
                bribe.execute();
                break;
            }
        
            default: {
                break;
            }
        
        }
    }

}