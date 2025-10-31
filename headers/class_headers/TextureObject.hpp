#pragma once 

#include "../main_headers.hpp"
class TextureObject {
protected: 
    SDL_Texture* texture_;
    SDL_Rect rect_;         
    SDL_Renderer* renderer_; 

public: 
    // constructor
    TextureObject(SDL_Renderer* renderer, const std::string& texture_path, int x_start_pos, int y_start_pos);

    // destructor
    virtual ~TextureObject(); 

    // render function
    virtual void render_not_surface();

    // abstract event handler
    virtual void handle_event(SDL_Event& event) = 0; 

    // getter for rect
    SDL_Rect get_rect() const { return rect_; }
};