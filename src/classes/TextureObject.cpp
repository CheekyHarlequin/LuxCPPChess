#include "../main_headers.hpp"


TextureObject::TextureObject(SDL_Renderer* renderer, const std::string& texture_path, int x, int y, int w, int h)
    : renderer_(renderer)
{
    texture_ = IMG_LoadTexture(renderer_, texture_path.c_str());

    if (texture_ == nullptr) {
        std::cerr << "Error! Texture couldn't load! Path:" << texture_path << std::endl;
        std::cerr << "SDL_image Error: " << IMG_GetError() << std::endl;
    }

    rect_.x = x;
    rect_.y = y; 


    if (w == 0 || h == 0) {
        // standard case: uses original texture size
        SDL_QueryTexture(texture_, NULL, NULL, &rect_.w, &rect_.h);
    } else {
        // custom size
        rect_.w = w;
        rect_.h = h;
    }
}

// destructor
TextureObject::~TextureObject() {
    if (texture_ != nullptr) {
        SDL_DestroyTexture(texture_);
        texture_ = nullptr;
    }
}


// render function
void TextureObject::render()
{
    if (texture_ != nullptr && renderer_ != nullptr) {
        SDL_RenderCopy(renderer_, texture_, NULL, &rect_);
    }
}




