
mkdir -p out/


find . -name "*.cpp" -exec clang-format -i {} \;
find . -name "*.hpp" -exec clang-format -i {} \;
find . -name "*.c" -exec clang-format -i {} \;
find . -name "*.h" -exec clang-format -i {} \;

echo "✅ All source files formatted."


CPP_FILES=$(find . -name "*.cpp")


SDL_LIBS=$(sdl2-config --cflags --libs)


echo "Compiling..."
g++ $CPP_FILES -Ofast -g -fuse-ld=gold -o out/chess $SDL_LIBS -lSDL2_image -lSDL2_ttf


if [ $? -eq 0 ]; then
    echo "▶️ compilation successful. Starting the program..."
    ./out/chess
else
    echo "❌ compilation failed."
fi