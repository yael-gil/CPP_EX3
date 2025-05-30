#ifndef COUP_GAMEGUI_HPP
#define COUP_GAMEGUI_HPP

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Player.hpp"

namespace gui {

class GameGUI {
private:
    game::Game* game_;
    sf::Font font_;
    
    size_t current_turn_index_;
    void drawPlayerInfo(player::Player* player, sf::RenderWindow& window);
    void drawPlayerInfo(player::Player* player, sf::RenderWindow& window, float y);

public:
    explicit GameGUI(game::Game* game);
    ~GameGUI();

    void run();
};

} // namespace gui

#endif // COUP_GAMEGUI_HPP
