//yaeldorani@gmail.com

#ifndef TAX_HPP
#define TAX_HPP

#include <string>
#include "Action.hpp"
namespace game { class Game;}
namespace player { class Player;}

namespace action{


class Tax : public Action{

    private:


    public:
 

        Tax(game::Game* game, player::Player* source);

        virtual ~Tax();


        void execute() override; //The player takes two coin from the pot, the action can be blocked by "sanction"

        void execute(player::Player* target) override; // return expretion

};
}

#endif