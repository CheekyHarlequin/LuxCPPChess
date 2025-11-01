#pragma once

#include "../main_headers.hpp"

class GameEngine {
    private:

        //  1920 / 16 = 120
        // 1080 / 9 = 120
        const int VIRTUAL_W = 1920;
        const int VIRTUAL_H = 1080;
        
        SDL_Window* window_ = nullptr;
        SDL_Renderer* renderer_ = nullptr;
        bool is_running_ = false;


        // space for all game objects

        std::vector<std::unique_ptr<TextureObject>> all_objects_;

        public:

        GameEngine();
        ~GameEngine();

        bool init();
        void run_loop();

        void cleanup();

        void update_scaling();
        
        void add_object(std::unique_ptr<TextureObject> obj);

        void quit();
        SDL_Renderer* get_renderer() const { return renderer_;}

};