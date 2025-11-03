#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <thread>
class TextureObject {
protected:
  SDL_Texture *texture_;
  SDL_Rect rect_;
  SDL_Renderer *renderer_;

public:
  // constructor
  TextureObject(SDL_Renderer *renderer, const std::string &path, int x, int y,
                int w = 0, int h = 0);

  // destructor
  virtual ~TextureObject();

  // render function
  virtual void render();

  // abstract event handler
  virtual void handle_event(SDL_Event &event) = 0;

  // getter for rect
  SDL_Rect get_rect() const { return rect_; }

  // Seter for size and positionW
  void set_size(int w, int h) {
    rect_.w = w;
    rect_.h = h;
  }

  void set_position(int x, int y) {
    rect_.x = x;
    rect_.y = y;
  }
};