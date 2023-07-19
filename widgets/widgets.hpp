#pragma once

#include "../libs.hpp"
#include "../settings/settings.hpp"

class Background {
 public:
    explicit Background(BackgroundSettings settings);

    Background(const std::vector<std::string>& vector_paths,
               float switch_time);

    ~Background() = default;

    void draw(sf::RenderWindow& window);

 private:
    sf::Texture update_texture();

    std::vector<sf::Texture> vector_textures;
    sf::Clock clock;
    float switch_time;
};