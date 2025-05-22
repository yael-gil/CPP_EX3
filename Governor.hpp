//yaeldorani@gmail.com

// 3 מטבעות מהקופה במקום 2 כשהוא משתמש בפעולת מס (tax). בנוסף, הוא יכול לבטל פעולת מס (tax) של שחקנים אחרים.

#ifndef GOVERNOR_HPP
#define GOVERNOR_HPP

#include <string>
#include "Player.hpp"


namespace player{


class Governor : public Player{

    private:

    const std::string& action_name;

    public:
 

        Governor(std::string name, game::Game *game, const std::string& roll_name);

        virtual ~Governor();

        std::string get_roll(); //Return player's roll 

};
}

#endif