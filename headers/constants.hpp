#pragma once

namespace Game_Constants {
enum class Window_Dimensions : const int { VIRTUAL_W = 1920, VIRTUAL_H = 1080 };

}; // namespace Game_Constants

namespace Objects {

enum class Object_ID : const int {
  /*
  Order:

  Background: 0-9

  White Piece:
  10-26

  Black Piece:
  30-46

  Buttons:
  50-70

  Menu:
  80 and following
  */

  // Background
  BACKGROUND_ID = 0,

  // White Pieces

  // Black Pieces

  // Buttons
  TESTBUTTON_ID = 50
  // Menu

};
constexpr const char *BACKGROUND_TEXTURE = "textures/general/board.png";
}; // namespace Objects
