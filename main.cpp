#include "headers/class_headers/GameEngine.hpp"
#include "headers/class_headers/TextureObject.hpp"
#include "headers/class_headers/staticTexture.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char *argv[]) {
  GameEngine engine;

  if (!engine.init()) {
    std::cerr << "Failed to initialize the game engine." << std::endl;
    return -1;
  }

  engine.load_scene();

  engine.run_loop();

  return 0;
}