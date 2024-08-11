#pragma once

#include "../../libs.hpp"
#include "../settings/settings.hpp"

class Background {
 public:
    Background() = delete;

    explicit Background(BackgroundSettings& settings);

    Background(const std::vector<std::string>& vector_paths,
               const float& switch_time);

    ~Background() = default;

    void draw(sf::RenderWindow& window);

 private:
    sf::Texture update_texture();

    std::vector<sf::Texture> vector_textures;
    sf::Clock clock;
    float switch_time;
};

class Text {
 public:
    Text() = delete;

    explicit Text(TextSettings& settings);

    Text(const float& x,
         const float& y,
         const std::string& text_string,
         const unsigned int& size_text,
         const float& outline_thickness,
         const sf::Color& fill_color,
         const sf::Color& outline_color,
         const std::string& font_path);

    void draw(sf::RenderWindow& window);

 private:
    sf::Font font;
    sf::Text text;
};
