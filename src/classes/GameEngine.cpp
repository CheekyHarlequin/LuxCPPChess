// all necessary includes

#include "../../headers/class_headers/GameEngine.hpp"

using namespace std;
using namespace Game_Constants;
using namespace Objects;
// Constructor
GameEngine::GameEngine() {}

GameEngine::~GameEngine() { cleanup(); }

bool GameEngine::init() {

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return false;
  }
  window_ = SDL_CreateWindow("C(PP)hess", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, vWidth, vHeight,
                             SDL_WINDOW_RESIZABLE);

  if (!window_) {
    std::cerr << "Window could not be created! " << SDL_GetError() << std::endl;
    return false;
  }
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer_) {
    std::cerr << "Renderer konnte nicht erstellt werden! " << SDL_GetError()
              << std::endl;
    return false;
  }

  // used for scaling textures, window etc.
  update_scaling();

  return true;
}

void GameEngine::load_scene() {

  // Bestimme die Größe für das quadratische Board (hier 1080)
  const int SQUARE_SIZE = min(vWidth, vHeight);

  // OPTIONAL: Zentriere das Board auf der X-Achse
  const int CENTER_X = (vWidth - SQUARE_SIZE) / 2;
  const int CENTER_Y = (vHeight - SQUARE_SIZE) / 2;

  const int Board_X_Pos = CENTER_X;
  const int Board_Y_Pos = CENTER_Y;
  auto background =
      std::make_unique<StaticTexture>(renderer_,
                                      BACKGROUND_TEXTURE, // Texture Path
                                      CENTER_X,           // X Pos
                                      CENTER_Y,           // Y Pos
                                      SQUARE_SIZE,        // Width: square
                                      SQUARE_SIZE         // height: square
      );

  this->add_object(std::move(background));
}

void GameEngine::update_scaling() {
  int actual_w, actual_h;
  SDL_GetWindowSize(window_, &actual_w, &actual_h);

  

  float scale_x = (float)actual_w / vWidth;
  float scale_y = (float)actual_h / vHeight;


  float final_scale = std::min(scale_x, scale_y);

  SDL_RenderSetScale(renderer_, final_scale, final_scale);

  int board_size = std::min(vWidth, vHeight);

}

// main loop, event handling
void GameEngine::run_loop() {
  SDL_Event event;
  is_running_ = true;

  while (is_running_) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        is_running_ = false;
      }

      // If window sized, update scaling
      if (event.type == SDL_WINDOWEVENT &&
          event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        update_scaling();
      }

      // Give the event to all objects
      for (const auto &obj : all_objects_) {
        obj->handle_event(event);
      }
    }

    // ... (Render-Logik) ...
    // Gib den Render-Befehl an alle Objekte weiter (Polymorphie)
    for (const auto &obj : all_objects_) {
      obj->render();
    }
    SDL_RenderPresent(renderer_);
    SDL_RenderClear(renderer_);
  }
}
// method to create and add objects
void GameEngine::add_object(std::unique_ptr<TextureObject> obj) {
  // if obj is valid, add to vector
  if (obj) {
    all_objects_.push_back(std::move(obj));
  }
}

void GameEngine::cleanup() {
  if (renderer_) {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
  }
  if (window_) {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
  }
  SDL_Quit();
}

// ID Finder for objects. ID's are definid in "ObjectID.hpp"
TextureObject *GameEngine::get_object_by_id(int id) {

  auto it = std::find_if(all_objects_.begin(), all_objects_.end(),

                         [&](const std::unique_ptr<TextureObject> &obj_ptr) {
                           return obj_ptr->get_object_id() == id;
                         });

  if (it != all_objects_.end()) {
    return it->get();
  }

  return nullptr;
}