//yaeldorani@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

namespace player{


class Player{

private:
    static int ID; // ID to player
    std::string name;
    int coins; //Current player's total coins
    bool sanction;
public:
 
    int id; //save current player's id   

    Player(std::string name); 
    ~Player();

        int get_coins(); // Return current player's total coins
        // void removeEdge(int src, int dst);
        // void printGraph();
        // Node* findNodeInGraph(int id);
};
}

#endif