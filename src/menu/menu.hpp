#pragma once

#include "../../libs.hpp"
#include "../widgets/widgets.hpp"
#include "../settings/settings.hpp"

class Menu {
 public:
    explicit Menu(MenuSettings& settings);

    Menu(const std::string& music_path,
         const float& music_volume,
         BackgroundSettings& background_settings,
         TextSettings& text_settings);

    ~Menu() = default;

    void draw(sf::RenderWindow& window);

 private:
    Background background;
    Text text;
    sf::Music music;
};