#pragma once

#include "../../headers/class_headers/TextureObject.hpp"
#include "../../headers/class_headers/staticTexture.hpp"
#include "../../headers/constants.hpp"
#include <SDL2/SDL.h> //
#include <algorithm>
#include <cmath>    // for std::min
#include <iostream> // for cerr
#include <memory>   // for unique_ptr
#include <vector>   // for std::vector
class GameEngine {
private:
  //  1920 / 16 = 120
  // 1080 / 9 = 120

  int vWidth = static_cast<int>(Game_Constants::Window_Dimensions::VIRTUAL_W);
  int vHeight = static_cast<int>(Game_Constants::Window_Dimensions::VIRTUAL_H);

  SDL_Window *window_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;
  bool is_running_ = false;

  // space for all game objects

  std::vector<std::unique_ptr<TextureObject>> all_objects_;

public:
  GameEngine();
  ~GameEngine();

  bool init();
  void run_loop();

  void load_scene();

  void cleanup();

  void update_scaling();

  void add_object(std::unique_ptr<TextureObject> obj);

  void quit();
  SDL_Renderer *get_renderer() const { return renderer_; }
  TextureObject *get_object_by_id(int id);
};