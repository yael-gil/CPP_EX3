#include "GameGUI.hpp"
#include <iostream>

namespace gui {

GameGUI::GameGUI(game::Game* game) : game_(game), current_turn_index_(0) {
    if (!font_.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        if (!font_.loadFromFile("arial.ttf")) {
            std::cerr << "Couldn't load font\n";
            throw std::runtime_error("Font loading failed");
        }
    }
}

GameGUI::~GameGUI() = default;

void GameGUI::drawPlayerInfo(player::Player* player, sf::RenderWindow& window, float y) {
    sf::Text nameText(player->get_name(), font_, 24);
    nameText.setPosition(50.f, y);
    nameText.setFillColor(sf::Color::White);
    window.draw(nameText);

    std::string roleName = player->role_to_string(player->get_role());
    sf::Text roleText("Role: " + roleName, font_, 20);
    roleText.setPosition(50.f, y + 30);
    roleText.setFillColor(sf::Color::Yellow);
    window.draw(roleText);
}

void GameGUI::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Coup Game GUI");

    sf::RectangleShape actionButton(sf::Vector2f(200, 50));
    actionButton.setPosition(50, 500);
    actionButton.setFillColor(sf::Color(100, 200, 100));

    sf::Text actionText("Perform Action", font_, 24);
    actionText.setPosition(70, 510);
    actionText.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
                if (actionButton.getGlobalBounds().contains(mouse)) {
                    auto players = game_->players();
                    if (!players.empty()) {
                        size_t count = players.size();
                        for (size_t i = 0; i < count; ++i) {
                            current_turn_index_ %= players.size();
                            player::Player* current = players[current_turn_index_];
                            if (current->is_active()) {
                                std::cout << "Action: " << current->get_name() << " performed an action.\n";
                                current_turn_index_++;
                                break;
                            } else {
                                current_turn_index_++;
                            }
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        // Current turn
        std::string currentPlayerName = "No players";
        auto players = game_->players();
        if (!players.empty()) {
            size_t idx = current_turn_index_ % players.size();
            for (size_t i = 0; i < players.size(); ++i) {
                player::Player* p = players[(idx + i) % players.size()];
                if (p->is_active()) {
                    currentPlayerName = "Turn: " + p->get_name();
                    break;
                }
            }
        }

        sf::Text turnText(currentPlayerName, font_, 28);
        turnText.setPosition(50.f, 20.f);
        turnText.setFillColor(sf::Color::Cyan);
        window.draw(turnText);

        float y = 80.f;
        for (player::Player* p : players) {
            if (!p->is_active()) continue;
            drawPlayerInfo(p, window, y);
            y += 70.f;
        }

        window.draw(actionButton);
        window.draw(actionText);

        window.display();
    }
}

} // namespace gui
