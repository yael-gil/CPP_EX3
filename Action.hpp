//yaeldorani@gmail.com

#ifndef ACTION_HPP
#define ACTION_HPP

#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace action{


class Action{

    private:
    game::Game* game;
    player::Player* source;
    const std::string action_name;      

    public:
 

        Action(game::Game* game, player::Player* source,  const std::string &action_name); 
        virtual ~Action();

        virtual void execute() = 0;

        virtual void execute(player::Player* target) = 0;

        player::Player* get_source(); //Return action's source

        game::Game* get_action_game(); //Return action's game

};
}

#endif