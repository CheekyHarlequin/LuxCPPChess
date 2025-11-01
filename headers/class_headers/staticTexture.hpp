#pragma once

#include "../main_headers.hpp"

class StaticTexture : public TextureObject {
public:

    // constructor
    StaticTexture(SDL_Renderer* renderer, const std::string& texture_path, int x_start_pos, int y_start_pos, int startHeight, int startWidth)
        : TextureObject(renderer, texture_path, x_start_pos, y_start_pos) {}



    // event handler (no events for static texture)
    void handle_event(SDL_Event& event) override {}
};