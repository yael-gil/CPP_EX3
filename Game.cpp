//yaeldorani@gmail.com
#include <iostream>


#include "Enum_role.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Action.hpp"
#include "Gather.hpp"
#include "Tax.hpp"
#include "Arrest.hpp"
#include "Bribe.hpp"
#include "Sanction.hpp"
#include "Coup.hpp"

namespace game{
    
    int Game::ID = 0;

    Game::Game(std::string game_name){

        name = game_name;
        id = ID++;
        last_arrest = "none";
    }
    Game::~Game() {

    }

    void Game::add_player(player::Player* player){
        for (int i = 0; i < this->players_list.size(); i++){
            if(this->players_list.size() >= 6){
                throw std::runtime_error("The game is full, you cannot add more players. \n"
);
            }
            if(players_list[i]->get_name() == player->get_name()){ //If player's name == player's name in game, add to the list
                throw std::runtime_error("This name is taken, there is a player in the current game with that name. \n"
                    "Please choose a different name.");
            }
        }
        this->players_list.push_back(player); // Add a new player to the game
    }

    //Create the turn vector
    std::vector<player::Player*> Game::create_turns() {
        return filter_active(turn);
    }

    //Filter the active player
    std::vector<player::Player*> Game::filter_active(const std::vector<player::Player*>& list) const {
        std::vector<player::Player*> result;
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->is_active()) {
                result.push_back(list[i]);
            }
        }
        return result;
    }


    //Returns all players in the game wuth a specific role
    const std::vector<player::Player*> Game::get_player_in_game_by_role(Enum_role role) {
        std::vector<player::Player*> active = filter_active(players_list);
        std::vector<player::Player*> result;
        for (int i = 0; i < active.size(); i++) {
            if (active[i]->get_role() == role) { //If player's role == role, add to the list
                result.push_back(active[i]);
            }
        }
        return result;
    }

    //Return all players in the game
    std::vector<player::Player*> Game::players() {
        return filter_active(players_list);
    }


    // Return current turn
    player::Player* Game::turns() {
       return this->get_turns()[0];
    }

    player::Player* Game::next_turns() {
    // Return next turn
        while (!turn.empty()) {
        player::Player* current = turn.front();
        turn.erase(turn.begin());
        turn.push_back(current);
        if (current->is_active()) {
            return current;
        }
    }
    throw std::runtime_error("No active players remain.");
}
    //Get the turn vector
    std::vector<player::Player*>& Game::get_turns(){
        return this->turn;
    } 

    std::string Game::get_last_arrest(){
        return this->last_arrest;
    }

    void Game::set_last_arrest (std::string new_arrest){
        this->last_arrest = new_arrest;
    }

   /* void Game::play_game(){
        
        this->create_turns(); //At the beginning of the game, a create turn 

        while(this->turn.size() > 1){ // If there is 1 player, game over
        
            
            player::Player* current_player = this->turns(); // get the current turn
            
            //print current player's name and role
            std::cout<<"Current player: "<< current_player->get_name()<<std::endl;
            std::cout<<"role: "<< current_player->role_to_string(current_player->get_role()) <<std::endl;

            //add swich case by role to spaicel actions

            

            int action = choose_action(current_player);

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
       */

        
    int Game::choose_action(player::Player* current, int action_from_Gui){
        //print action
        std::cout<<"Choose Action: (number)"<<std::endl;


        if (current->get_coins() >= 10){
            std::cout<<"You have more than 10 coins, you must do coup."<<std::endl;
            return 6;
        }

        bool good[7] = {false}; //Keeps the numbers of actions the player can do
     

        if(current->get_sanction()){
            std::cout<<"You are blocked! cannot use gather."<<std::endl;
        }
        if(!current->get_sanction()){    
            std::cout<<"1: Gather"<<std::endl;
            std::cout<<"2: Tax"<<std::endl;
            good[1] = true;
            good[2] = true;
        }
        
        std::cout<<"3: Arrest"<<std::endl;
        good[3] = true;

        if(current->get_coins() >= 4){
            std::cout<<"4: Bribe"<<std::endl;
            good[4] = true;

        }

        if(current->get_coins() >= 3){
            std::cout<<"5: Sanction"<<std::endl;
            good[5] = true;

        }

        if(current->get_coins() >= 7){
            std::cout<<"6: Coup"<<std::endl;
            good[6] = true;
        }

        //Current player choose action

        while(true){

            if(action_from_Gui >= 1 && action_from_Gui <= 6 && good[action_from_Gui]){
                return action_from_Gui;
            }
            throw std::runtime_error("Can't use this action.");
            }
    }
    
    void Game::do_action(player::Player* current_player, int action, int optional_target){
        //Do action acording to player's decision
        switch (action)
        {
            case 1: {
                if(current_player->get_sanction()){
                   throw std::runtime_error("You are blocked! cannot use gather.");
                   break;
                
                }
                action::Gather gather(this, current_player);
                gather.execute();
                break;
            }

            case 2: {
                if(current_player->get_sanction()){
                    throw std::runtime_error("You are blocked! cannot use tax.");
                    break;
                }
                action::Tax tax(this, current_player);
                tax.execute();
                break;
            }

            case 3: {
                action::Arrest arrest(this, current_player);
                
                std::cout<<"Choose player to attack: "<<std::endl;

                if(optional_target < 1 || optional_target > this->players_list.size()){
                    throw std::runtime_error("Invalid target! please try again.");
                }
                arrest.execute(this->players()[optional_target]);
                break;
            }
            
            case 4: {
                if(current_player->get_coins() < 4){
                    throw std::runtime_error("Can't use bribe, you don't have enough money.");
                    break;
                }
                action::Bribe bribe(this, current_player);
                bribe.execute();
                break;
            }
            case 5: {
                if(current_player->get_coins() < 3){
                    throw std::runtime_error("Can't use sanction, you don't have enough money.");
                    break;
                }

                action::Sanction sanction(this, current_player);
                sanction.execute();
                break;
            }
            case 6: {
                if(current_player->get_coins() < 7){
                    throw std::runtime_error("Can't use coup, you don't have enough money.");
                    break;
                }
                action::Coup coup(this, current_player);
                coup.execute();
                break;
            }
        
            default: {
                break;
            }
        
        }
    }

    void Game::special_operations(player::Player* current , bool want_to_invest, int optional_target) {
        switch (current->get_role())
        {
        case Enum_role::Baron:
            {
                if(want_to_invest){

                    if (current->get_coins() >= 3){
                        current->do_invest();
                        break;
                    }
                    else{
                        throw std::runtime_error("You don't have enough money, can't invest.");
                    }
                }

                else{
                    break;
                }
            }
        case Enum_role::Spy:
            {
                if(want_to_invest){
                    if(optional_target < 1 || optional_target > this->players_list.size()){
                        throw std::runtime_error("Invalid target! please try again.");
                    }
                
                    current->peek(players_list[optional_target]);
                    break;
                }

                else{
                    break;
                }
            }

        case Enum_role::Merchant:
            {
                if(current->get_coins() >= 3){
                    current->set_coins(1);
                    break;
                }

                else{
                    break;
                }
            }
        case Enum_role::General:
            {

            break;
            }
        case Enum_role::Governor:
            {

            break;
            }
        case Enum_role::Judge:
            {

            break;
            }
        }
    } 

    std::string Game::winner(){
        std::vector <player::Player*> current = filter_active(players_list);
        if(current.size() == 1){
            return current[0]->get_name(); //Return the winner's name
        } 
        else {
            return "No winner yet.";
        }
    }
}