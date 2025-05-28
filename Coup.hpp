//yaeldorani@gmail.com

#ifndef COUP_HPP
#define COUP_HPP

#include <string>
#include "Action.hpp"
namespace game { class Game;}
namespace player { class Player;}

namespace action{


class Coup : public Action{

    private:


    public:
 

        Coup(game::Game* game, player::Player* source);

        virtual ~Coup();

        //The player chooses another player and completely removes them from the game
        //This action costs 7 coins
        void execute(player::Player* target) override; 

        void execute() override;
};
}

#endif