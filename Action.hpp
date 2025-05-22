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
    std::string name;
    const std::string& action_name  ;      

    public:
 

        Action(game::Game* game, player::Player* source, std::string name, const std::string& action_name); 
        virtual ~Action();

        virtual void execute() = 0;

        player::Player* getSource();
};
}

#endif