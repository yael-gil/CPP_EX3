//yaeldorani@gmail.com

#ifndef JUDGE_HPP
#define JUDGE_HPP

#include <string>
#include "Player.hpp"


namespace player{


class Judge : public Player{

    private:



    public:
 

        Judge(std::string name, game::Game *game);

        virtual ~Judge();

        bool block_bribe(Player* player) override;


};
}

#endif