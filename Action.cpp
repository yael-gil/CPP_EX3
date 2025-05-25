#include "Action.hpp"

#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace action {

    Action::Action(game::Game *game, player::Player *source, std::string name, const std::string &action_name)
    : game(game), source(source), name(name), action_name(action_name){
    }

    Action::~Action() {}

    //Return action's source
    player::Player* Action::get_source(){
        return this->source;
    }

    //Return action's game
    game::Game* Action::get_action_game(){
        return this->game;
    }

}