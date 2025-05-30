#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "Game.hpp"
#include "Player.hpp"
#include "GameGUI.hpp"

using namespace sf;
using namespace std;
using namespace game;
using namespace player;
using namespace gui;

int main() {
    RenderWindow window(VideoMode(800, 600), "Coup Game GUI");

    Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        if (!font.loadFromFile("arial.ttf")) {
            cerr << "Couldn't load font\n";
            return 1;
        }
    }

    string inputText = "";
    Text inputDisplay("", font, 24);
    inputDisplay.setPosition(50, 100);
    inputDisplay.setFillColor(Color::White);

    RectangleShape inputBox(Vector2f(400, 40));
    inputBox.setPosition(50, 100);
    inputBox.setFillColor(Color(200, 200, 200));

    Text instructions("Enter Game Name:", font, 24);
    instructions.setPosition(50, 50);
    instructions.setFillColor(Color::White);

    Text buttonText("Create Game", font, 24);
    RectangleShape button(Vector2f(200, 50));
    button.setPosition(50, 160);
    button.setFillColor(Color(100, 150, 250));
    buttonText.setPosition(70, 165);
    buttonText.setFillColor(Color::White);

    Text startGameText("Start Game", font, 24);
    RectangleShape startGameButton(Vector2f(200, 50));
    startGameButton.setPosition(50, 230);
    startGameButton.setFillColor(Color(100, 250, 150));
    startGameText.setPosition(70, 235);
    startGameText.setFillColor(Color::White);

    bool gameCreated = false;
    Game* game = nullptr;
    vector<Player*> added_players;
    string errorMessage = "";
    Text errorText("", font, 20);
    errorText.setFillColor(Color::Red);
    errorText.setPosition(50, 300);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::TextEntered) {
                if (event.text.unicode == 8 && !inputText.empty()) {
                    inputText.pop_back();
                } else if (event.text.unicode < 128 && isprint(event.text.unicode)) {
                    inputText += static_cast<char>(event.text.unicode);
                }
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2f mouse(event.mouseButton.x, event.mouseButton.y);

                if (button.getGlobalBounds().contains(mouse)) {
                    if (!inputText.empty()) {
                        if (!gameCreated) {
                            game = new Game(inputText);
                            gameCreated = true;
                            inputText.clear();
                            errorMessage = "";
                        } else {
                            try {
                                Player* p = new Player(inputText, game);
                                game->add_player(p);
                                added_players.push_back(p);
                                inputText.clear();
                                errorMessage = "";
                            } catch (const std::runtime_error& e) {
                                errorMessage = e.what();
                            }
                        }
                    }
                }

                if (startGameButton.getGlobalBounds().contains(mouse)) {
                    if (gameCreated && added_players.size() >= 2) {
                        GameGUI gui(game);
                        gui.run();
                        window.close();
                    } else {
                        errorMessage = "At least 2 players are required to start.";
                    }
                }
            }
        }

        window.clear(Color::Black);
        inputDisplay.setString(inputText);

        window.draw(instructions);
        window.draw(inputBox);
        window.draw(inputDisplay);
        window.draw(button);
        window.draw(buttonText);

        if (gameCreated) {
            instructions.setString("Enter Player Name:");
            buttonText.setString("Add Player");

            window.draw(startGameButton);
            window.draw(startGameText);

            Text playersTitle("Players:", font, 20);
            playersTitle.setPosition(500, 50);
            window.draw(playersTitle);

            for (size_t i = 0; i < added_players.size(); ++i) {
                Player* p = added_players[i];
                string player_info = p->get_name() + " (" + p->role_to_string(p->get_role()) + ")";
                Text name(player_info, font, 20);
                name.setPosition(500, 80 + i * 30);
                window.draw(name);
            }
        }

        if (!errorMessage.empty()) {
            errorText.setString(errorMessage);
            window.draw(errorText);
        }

        window.display();
    }

    for (Player* p : added_players)
        delete p;
    delete game;
    return 0;
}
