//yaeldorani@gmail.com


#ifndef SPY_HPP
#define SPY_HPP

#include <string>
#include "Player.hpp"


namespace player{


class Spy : public Player{

    private:



    public:
 

        Spy(std::string name, game::Game *game, const std::string& role_name);

        virtual ~Spy();

        int peek(Player* player) override;
};
}

#endif