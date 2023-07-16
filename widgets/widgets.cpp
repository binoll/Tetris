#include "widgets.hpp"

Background::Background(const std::vector<std::string>& vector_paths,
                       sf::Clock& clock,
                       float switch_time) : clock(clock), switch_time(switch_time) {
    sf::Texture texture;

    for (const auto& vector_path : vector_paths) {
        texture.loadFromFile(vector_path);
        this->vector_textures.push_back(texture);
    }
}

sf::Texture Background::update_texture() {
    static short texture_number = 0;
    sf::Texture texture = this->vector_textures[texture_number];

    if (clock.getElapsedTime().asSeconds() >= switch_time) {
        texture_number = (texture_number + 1) % this->vector_textures.size();
        texture = this->vector_textures[texture_number];
        clock.restart();
    }

    return texture;
}

void Background::draw(sf::RenderWindow& window) {
    sf::Texture texture = this->update_texture();
    sf::Sprite sprite(texture);

    window.draw(sprite);
}

