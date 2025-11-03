#pragma once

#include "TextureObject.hpp"
#include <SDL2/SDL.h> //
#include <algorithm>
#include <cmath>    // for std::min
#include <iostream> // for cerr
#include <memory>   // for unique_ptr
#include <vector>   // for std::vector
// Optional: Enum für den Button-Zustand, falls Sie verschiedene Bilder
// verwenden
enum class ButtonState { NORMAL, HOVER, CLICKED };

class Button : public TextureObject {
private:
  // Der Zustand des Buttons
  ButtonState current_state_ = ButtonState::NORMAL;

public:
  void hover_effect(int Button_ptr);
  void press_effect(int Button_ptr);
  void action(int Button_ptr);
};