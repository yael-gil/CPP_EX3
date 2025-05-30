//yaeldorani@gmail.com


#ifndef MERCHANT_HPP
#define MERCHANT_HPP

#include <string>
#include "Player.hpp"


namespace player{


class Merchant : public Player{

    private:



    public:
 

        Merchant(std::string name, game::Game *game);

        virtual ~Merchant();


};
}

#endif