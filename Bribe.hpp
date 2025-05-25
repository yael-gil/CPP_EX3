//yaeldorani@gmail.com

#ifndef BRIBE_HPP
#define BRIBE_HPP

#include <string>
#include "Action.hpp"
namespace game { class Game;}
namespace player { class Player;}

namespace action{


class Bribe : public Action{

    private:


    public:
 

        Bribe(game::Game* game, player::Player* source, std::string name);

        virtual ~Bribe();


        void execute() override; //The player pays 4 coins to the pot and gets a double turn (total of 3 turns)

};
}

#endif