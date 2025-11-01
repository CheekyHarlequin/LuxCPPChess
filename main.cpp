#include "./headers/main_headers.hpp"

int main(int argc, char *argv[])
{
    GameEngine engine;
    
    if(!engine.init()) {
        std::cerr << "Failed to initialize the game engine." << std::endl;
        return -1;
    }

    auto background = std::make_unique<StaticTexture>(engine.get_renderer(),
    "textures/general/test.png", 0, 0, 1920, 1080);



    engine.add_object(std::move(background));

    engine.run_loop();

    return 0;
}