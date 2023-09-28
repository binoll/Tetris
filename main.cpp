#include "libs.hpp"
#include "menu/menu.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(650, 700), "Tetris", sf::Style::Default);
    MenuSettings settings;
    Menu menu(settings);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
