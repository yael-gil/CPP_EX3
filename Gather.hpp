//yaeldorani@gmail.com

#ifndef GATHER_HPP
#define GATHER_HPP

#include <string>
#include "Action.hpp"
namespace game { class Game;}
namespace player { class Player;}

namespace action{


class Gather : public Action{

    private:


    public:
 

        Gather(game::Game* game, player::Player* source);

        virtual ~Gather();


        void execute() override; //The player takes one coin from the pot, the action can be blocked by "sanction"

        void execute(player::Player* target) override; // return expretion
};
}

#endif