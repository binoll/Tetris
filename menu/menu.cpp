#include "menu.hpp"

Menu::Menu(MenuSettings& settings) :
           background(settings.background_settings),
           text(settings.text_settings) {
    if(!this->music.openFromFile(settings.music_path)) {
        // throw CustomException();
    }
    this->music.setVolume(settings.music_volume);
    this->music.setLoop(true);
    this->music.play();
}

Menu::Menu(const std::string& music_path,
           const float& music_volume,
           BackgroundSettings& background_settings,
           TextSettings& text_settings) :
           background(background_settings.vector_paths,
                      background_settings.switch_time),
           text(text_settings.x, text_settings.y,
                text_settings.text_string, text_settings.size_text,
                text_settings.outline_thickness, text_settings.fill_color,
                text_settings.outline_color, text_settings.font_path) {
    if(!this->music.openFromFile(music_path)) {
        // throw CustomException();
    }
    this->music.setVolume(music_volume);
    this->music.setLoop(true);
    this->music.play();
}

void Menu::draw(sf::RenderWindow& window) {
    background.draw(window);
    text.draw(window);
}
