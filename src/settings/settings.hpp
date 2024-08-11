#pragma once

#include "../../libs.hpp"

struct BackgroundSettings {
    const std::vector<std::string> vector_paths = {
        "../etc/textures/menu/background/1.png",
        "../etc/textures/menu/background/2.png",
        "../etc/textures/menu/background/3.png",
        "../etc/textures/menu/background/4.png",
        "../etc/textures/menu/background/5.png",
        "../etc/textures/menu/background/6.png",
        "../etc/textures/menu/background/7.png",
        "../etc/textures/menu/background/8.png",
        "../etc/textures/menu/background/9.png",
        "../etc/textures/menu/background/10.png",
        "../etc/textures/menu/background/11.png",
        "../etc/textures/menu/background/12.png",
        "../etc/textures/menu/background/13.png",
        "../etc/textures/menu/background/14.png",
        "../etc/textures/menu/background/15.png",
        "../etc/textures/menu/background/16.png"
    };
    const float switch_time = 0.2f;
};

struct TextSettings {
    const float x = 120;
    const float y = 50;
    const std::string text_string = "T E T R I S";
    const unsigned int size_text = 80;
    const float outline_thickness = 5;
    sf::Color fill_color = sf::Color::White;
    sf::Color outline_color = sf::Color::Black;
    const std::string font_path = "../etc/fonts/pixel.ttf";
};

struct MenuSettings {
    const std::string music_path = "../etc/songs/menu/background.wav";
    float music_volume = 5.0f;
    BackgroundSettings background_settings;
    TextSettings text_settings;
};
