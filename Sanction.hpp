//yaeldorani@gmail.com

#ifndef SACTION_HPP
#define SACTION_HPP

#include <string>
#include "Action.hpp"
namespace game { class Game;}
namespace player { class Player;}

namespace action{


class Sanction : public Action{

    private:


    public:
 

        Sanction(game::Game* game, player::Player* source);

        virtual ~Sanction();


        void execute() override; //Return expretion

        void execute(player::Player* target) override; //The player chooses another player and prevents them from using econmic actions until their next turn. This action costs 3 coins 
        
};
}

#endif