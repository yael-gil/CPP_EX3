//yaeldorani@gmail.com


#ifndef BARON_HPP
#define BARON_HPP

#include <string>
#include "Player.hpp"


namespace player{


class Baron : public Player{

    private:



    public:
 

        Baron(std::string name, game::Game *game);

        virtual ~Baron();

        void do_invest() override;; //Invest 3 coins and get 6 coins

};
}

#endif