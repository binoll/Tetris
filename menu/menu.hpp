#pragma once

#include "../libs.hpp"
#include "../widgets/widgets.hpp"
#include "../settings/settings.hpp"

class Menu {
 public:
    explicit Menu(MenuSettings settings);

    Menu(const std::string& music_path,
         float music_volume,
         BackgroundSettings background_settings);

    ~Menu() = default;

    void draw(sf::RenderWindow& window);

 private:
    float music_volume;
    Background background;
    sf::Music music;
};