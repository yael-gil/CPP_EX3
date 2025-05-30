#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"
#include "Enum_role.hpp"

namespace game {

class Game {
private:
    static int ID;
    int id;
    std::string name;
    std::string last_arrest;

    //List for players in the game
    std::vector<player::Player*> players_list;

    // Turn 
    std::vector<player::Player*> turn;

    // Return active players
    std::vector<player::Player*> filter_active(const std::vector<player::Player*>& list) const;

public:
    Game(std::string game_name);
    ~Game();

    void add_player(player::Player* player);

    // Create turn list from the active players
    std::vector<player::Player*> create_turns();

    // Return active players by role
    const std::vector<player::Player*> get_player_in_game_by_role(Enum_role role);

    //Return active players
    std::vector<player::Player*> players();

    //Return current turn
    player::Player* turns();

    // Return the turn vector
    std::vector<player::Player*>& get_turns();

    // Return next player's turn
    player::Player* next_turns();

    // Return last arrested player
    std::string get_last_arrest();

    //Set last arrested player 
    void set_last_arrest(std::string new_arrest);

    //Choose action from the GUI output
    int choose_action(player::Player* current, int action_from_Gui);

    //Do the choosen action 
    void do_action(player::Player* current_player, int action, int optional_target = -1);

    // Do action acording special role
    void special_operations(player::Player* current, bool want_to_invest, int optional_target = -1);

    // Get wining of the game
    std::string winner();
};

} // namespace game

#endif // GAME_HPP
