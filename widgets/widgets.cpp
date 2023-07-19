#include "widgets.hpp"

Background::Background(BackgroundSettings& settings) :
                       switch_time(settings.switch_time) {
    sf::Texture texture;

    for (const auto& vector_path : settings.vector_paths) {
        if (!texture.loadFromFile(vector_path)) {
            // throw CustomException();
        }
        this->vector_textures.push_back(texture);
    }
}

Background::Background(const std::vector<std::string>& vector_paths,
                       const float& switch_time) : switch_time(switch_time) {
    sf::Texture texture;

    for (const auto& vector_path : vector_paths) {
        if (!texture.loadFromFile(vector_path)) {
            // throw CustomException();
        }
        this->vector_textures.push_back(texture);
    }
}

sf::Texture Background::update_texture() {
    static int texture_number = 0;
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

Text::Text(TextSettings& settings) {
    if (!font.loadFromFile(settings.font_path)) {
        // throw CustomException();
    }
    this->text.setString(settings.text_string);
    this->text.setFont(this->font);
    this->text.setOutlineColor(settings.outline_color);
    this->text.setFillColor(settings.fill_color);
    this->text.setCharacterSize(settings.size_text);
    this->text.setOutlineThickness(settings.outline_thickness);
    this->text.setPosition(settings.x, settings.y);
}

Text::Text(const float& x,
           const float& y,
           const std::string& text_string,
           const unsigned int& size_text,
           const float& outline_thickness,
           const sf::Color& fill_color,
           const sf::Color& outline_color,
           const std::string& font_path) {
    if (!this->font.loadFromFile(font_path)) {
        // throw CustomException();
    }
    this->text.setString(text_string);
    this->text.setFont(this->font);
    this->text.setOutlineColor(outline_color);
    this->text.setFillColor(fill_color);
    this->text.setCharacterSize(size_text);
    this->text.setOutlineThickness(outline_thickness);
    this->text.setPosition(x, y);
}

void Text::draw(sf::RenderWindow& window) {
    window.draw(this->text);
}
