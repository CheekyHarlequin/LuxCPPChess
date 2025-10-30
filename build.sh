mkdir -p out/

clang-format -i *.c *.h

g++ *.cpp -Ofast -g -fuse-ld=gold -o out/chess -lSDL2 -lSDL2_image -lSDL2_ttf && ./out/chess
