#include "Action.hpp"

#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace action {

    Action::Action(game::Game *game, player::Player *source, std::string name, const std::string &action_name)
    : game(game), source(source), name(name), action_name(action_name){
    }

    Action::~Action() {}
}