#include "menu.hpp"

Menu::Menu(MenuSettings settings) :
           background(settings.background_settings),
           music_volume(settings.music_volume) {
    if(!this->music.openFromFile(settings.music_path)) {
        // throw CustomException();
    }
    this->music.setVolume(settings.music_volume);
    this->music.setLoop(true);
    this->music.play();
}

Menu::Menu(const std::string& music_path,
           float music_volume,
           BackgroundSettings background_settings) :
           music_volume(music_volume),
           background(background_settings.vector_paths,
                      background_settings.switch_time) {
    if(!this->music.openFromFile(music_path)) {
        // throw CustomException();
    }
    this->music.setVolume(music_volume);
    this->music.setLoop(true);
    this->music.play();
}

void Menu::draw(sf::RenderWindow& window) {
    background.draw(window);
}
