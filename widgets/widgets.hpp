#pragma once

#include "../libs.hpp"

class Background {
 public:
    Background() = delete;

    Background(const std::vector<std::string>& vector_paths,
               sf::Clock& clock,
               float switch_time = 0.2f);

    ~Background() = default;

    void draw(sf::RenderWindow& window);

 private:
    sf::Texture update_texture();

    std::vector<sf::Texture> vector_textures;
    sf::Clock clock;
    float switch_time;
};