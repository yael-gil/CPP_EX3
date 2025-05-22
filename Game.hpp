//yaeldorani@gmail.com

#ifndef GAME_HPP
#define GAME_HPP

#include <string>

namespace game{


class Game{

private:
    static int ID; // ID to game

public:
 
    int id; //save current game's id   

    Game(); 
    ~Game();

};
}

#endif