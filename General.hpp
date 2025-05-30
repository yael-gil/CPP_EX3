//yaeldorani@gmail.com


#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <string>
#include "Player.hpp"


namespace player{


class General : public Player{

    private:



    public:
 

        General(std::string name, game::Game *game);

        virtual ~General();

        bool block_coup(Player* player) override;


};
}

#endif