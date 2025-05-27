//yaeldorani@gmail.com

#ifndef ARREST_HPP
#define ARREST_HPP

#include <string>
#include "Action.hpp"
namespace game { class Game;}
namespace player { class Player;}

namespace action{


class Arrest : public Action{

    private:


    public:
 

        Arrest(game::Game* game, player::Player* source);

        virtual ~Arrest();


        void execute(player::Player* target) override; //The player chooses another player and takes one coin form them.
        // It cannot be used on the same player twice.

        void execute() override;
};
}

#endif